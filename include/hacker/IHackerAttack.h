#pragma once

#include "ProtocolEthernet.h"

namespace RAChacker
{
    class	IHackerAttack
    {
	public :

	virtual ~IHackerAttack() {};
	
	virtual void	launchAttack() = 0;

	protected :

	virtual void	makingAttack() = 0;

	RACprotocol::ProtocolEthernet	ethernetLayer;
    };
}
