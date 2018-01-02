#include "LogHandler.h"
#include "RawSocketTCP.h"
#include "JsonConfInstanceInitializer.h"

#include <net/ethernet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>

#include <sys/ioctl.h>
#include <net/if.h>
#include <sys/socket.h>
#include <linux/if_packet.h>
#include <net/ethernet.h> /* the L2 protocols */

namespace RACsocket
{
    RawSocketTCP::RawSocketTCP()
    {
	Config();
	CreateSocket(); 
	if (!oRawSocketTCPError.IsError())
	{
	    LOG(INFO, "Raw Socket Tcp Creation : DONE SUCCESS");
	}
    }

    RawSocketTCP::~RawSocketTCP()
    {
	CloseSocket();
    }

    int RawSocketTCP::CreateSocket()
    {
	fd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
	if (fd == -1)
	{
	    oRawSocketTCPError.SetErrorStateAndLogErrorFromErno(true);
	}
	return fd;
    }

    int RawSocketTCP::CloseSocket()
    {
	return close(fd);
    }

    void    RawSocketTCP::PerformPromiscuousMode()
    {

	struct ifreq ifr;
	struct packet_mreq mr;

	ifr.ifr_ifindex = 0;
	strcpy(ifr.ifr_name, "eth0");

	if (ioctl(fd, SIOGIFINDEX, &ifr) < 0)
	{
	    perror("ioctl error ");
	    return ;
	}

	memset(&mr, 0, sizeof(mr));
	mr.mr_ifindex = ifr.ifr_ifindex;
	mr.mr_type =  PACKET_MR_PROMISC;

	if (setsockopt(fd, SOL_PACKET, PACKET_ADD_MEMBERSHIP,
		    (char *)&mr, sizeof(mr)) < 0)
	{
	    perror("setsockopt error ");
	    return ;
	}
    }

    int	RawSocketTCP::Bind()
    {
/*	sockaddr_in addr;

	if (setsockopt(fd, SOL_SOCKET, SO_BINDTODEVICE, sInterface.c_str(), sInterface.length()) == -1)
	{
	    oRawSocketTCPError.SetErrorStateAndLogErrorFromErno(true);
	    return -1;
	}
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(iPort);
	addr.sin_addr.s_addr = inet_addr(sIp.c_str());
	if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1)
	{
	    oRawSocketTCPError.SetErrorStateAndLogErrorFromErno(true);
	    return -1;
	} */
	PerformPromiscuousMode();
	return 1;
    }

    void    RawSocketTCP::Config()
    {
	std::unique_ptr<jsonConf>   spJsonConf(jsonConf::GetOrCreateInstance());

	try{
	    iPort = spJsonConf->GetValueFromConfigFile<int>("sniffer.port");
	    sIp = spJsonConf->GetValueFromConfigFile<std::string>("sniffer.ip", "127.0.0.1");
	    sInterface = spJsonConf->GetValueFromConfigFile<std::string>("sniffer.interface", "lo");
	}
	catch (std::exception &e)
	{
	    oRawSocketTCPError.SetErrorStateAndLogOwnError(true, e.what());
	}
    }

    void        RawSocketTCP::Error::SetErrorStateAndLogErrorFromErno(bool bErrorFlag)
    {
	SetErrorState(bErrorFlag);
	LogErrorFromErno();
    }

    void	RawSocketTCP::Error::SetErrorStateAndLogOwnError(bool bErrorFlag, const char* pErrMsg)
    {
	SetErrorState(bErrorFlag);
	LogOwnError(pErrMsg);
    }
}
