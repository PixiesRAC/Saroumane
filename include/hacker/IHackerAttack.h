#pragma once

#include "HackerUtils.h"
#include "ProtocolEthernet.h"

#include <net/if.h>
#include <linux/if_packet.h>

namespace RAChacker
{
    class	IHackerAttack
    {
	public :

		IHackerAttack();
	virtual ~IHackerAttack() {};
	
	virtual void	launchAttack(int socket) = 0;

	protected :

	virtual void	makingAttack();

	RACprotocol::ProtocolEthernet		    ethernetLayer;

	std::string				    IPDest;
	std::string				    IPSrc;
	uint8_t					    uMacDest[6];
	uint8_t					    uMacSrc[6];
	uint8_t					    uMacHost[6];
	std::string				    interface;

	struct sockaddr_ll			    sll;
	struct ifreq				    ifr;
    };
}
