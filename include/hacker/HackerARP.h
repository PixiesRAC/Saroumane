#pragma once

#include "IHackerAttack.h"
#include "ProtocolARP.h"

namespace RAChacker
{
    class HackerARP : public IHackerAttack
    {
	public :

	HackerARP();
	virtual ~HackerARP() override final = default;

	public :

	virtual void	launchAttack() override final;

	private :
	
	virtual void	makingAttack() override final;

	RACprotocol::ProtocolARP   ARPlayer;

    };
}
