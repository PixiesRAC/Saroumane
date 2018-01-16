#pragma once

#include "ProtocolEthernet.h"
#include <tuple>

namespace RAChacker
{
    class	IHackerAttack
    {
	public :

		IHackerAttack();
	virtual ~IHackerAttack() {};
	
	virtual void	launchAttack(int socket) = 0;

	protected :

	virtual void	makingAttack() = 0;

	RACprotocol::ProtocolEthernet		    ethernetLayer;
	std::string				    IPDest;
	std::string				    IPSrc;
	uint8_t					    uMacDest[6];
	uint8_t					    uMacSrc[6];
	std::string				    interface;
    };
}
