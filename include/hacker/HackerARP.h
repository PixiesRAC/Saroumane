#pragma once

#include "IHackerAttack.h"
#include "ProtocolARP.h"
#include <string>

namespace RAChacker
{
    class HackerARP : public IHackerAttack
    {
	public :

	HackerARP();
	virtual ~HackerARP() override final = default;

	public :

	virtual void	launchAttack(int socket) override final;

	private :
	
	virtual void	makingAttack() override final;

	protected :

	RACprotocol::ProtocolARP   ARPlayer;
	
	std::string	targetIP;
	std::string	hostIP;
	bool		bBothSide;
	bool		bDos;
	char		cPacket[256];	
	size_t		uPacketSize;
    };
}
