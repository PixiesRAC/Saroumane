#pragma once

#include <fstream>
#include <utility>
#include <tuple>
#include "LogHandler.h"


#include <unistd.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

namespace RAChacker
{
    class HackerUtils
    {
	static constexpr char*  pArpCachePath = "/proc/net/arp";
	static constexpr char*	pMACPath = "/sys/class/net/";

	static void convertMacToBytes(const char *pMacSrc, uint8_t *pMacDst)
	{
	    unsigned int    uMac[6];

	    if (pMacDst == nullptr)
		return ;
	    sscanf(pMacSrc, "%x:%x:%x:%x:%x:%x", &uMac[0], &uMac[1], &uMac[2], &uMac[3], &uMac[4], &uMac[5]);
	    
	    for(int i = 0; i < 6; ++i )
		pMacDst[i] = (uint8_t) uMac[i];
	}

	public :

	static void computeMacFromLocalIP(const std::string &ip, uint8_t *uMac)
	{
	    std::ifstream  fs;
	    fs.open (pArpCachePath);

	    try // i have to find a better solution for this function
	    {	
		std::string	    buffer;
		char		    ipFromArpCache[100];
		char		    mac[64];
		char		    useless[100];

		while (!std::getline(fs, buffer).eof())
		{
		    sscanf(buffer.c_str(), "%s 0x%x 0x%x %s %100s %100s\n", ipFromArpCache, useless, useless, mac, useless, useless);
		    if (ip == ipFromArpCache)
		    {
			convertMacToBytes(mac, uMac);
			if (uMac == nullptr)
			{
			    LOG(ERROR, "Error during the initialisation of the MAC adress");
			}
			fs.close();
			return ;
		    }	
		}
	    }
	    catch(std::ifstream::failure e)
	    {
		LOG(ERROR, "Exception happened: " << e.what() << "\n"
			<< "Error bits are: "
			<< "\nfailbit: " << fs.fail() 
			<< "\neofbit: " << fs.eof()
			<< "\nbadbit: " << fs.bad());    
	    }
	    LOG(ERROR, "Can't find the mac adress for this ip : " << ip);
	    fs.close();
	}

	static	void	    computeOwnMac(uint8_t *pMacSrc, const std::string &interface = "eth0")
	{
	    uint8_t	    aMac[6];
	    std::string	    macPath;

	    macPath = pMACPath + interface + "/address";
	    std::ifstream infile(macPath);

	    if (infile.good())
	    {
		std::string sLine;
		std::getline(infile, sLine);
		convertMacToBytes(sLine.c_str(), pMacSrc);
	    }
	    else
	    {
		LOG(ERROR, "Can't open file : " << macPath);
	    }
	    infile.close();
	}

	static	const std::string    getLocalIP(const std::string &interface = "eth0")
	{
	    struct		    ifaddrs *ifap, *ifa;
	    struct		    sockaddr_in *sa;
	    std::string		    addr;
	

	    getifaddrs (&ifap);
	    ifa = ifap;
	    while (ifap)
	    {
		if (ifap->ifa_addr && ifap->ifa_addr->sa_family == AF_INET) 
		{
		    if (interface == ifap->ifa_name)
		    {
			sa = (struct sockaddr_in *) ifap->ifa_addr;
			//addr = inet_network(inet_ntoa(sa->sin_addr));
			addr = inet_ntoa(sa->sin_addr);
			break;
		    }
		}
		ifap = ifap->ifa_next;
	    }
	    freeifaddrs(ifa);
	    return addr;
	}
    };
}
