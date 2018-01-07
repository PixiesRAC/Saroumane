#pragma once

#include "IProtocol.h"
#include <netinet/udp.h>

namespace RACprotocol
{
    class   ProtocolUDP : public IProtocol<ProtocolUDP>
    {

	public :

	ProtocolUDP();
	~ProtocolUDP();

	using protocol = struct udphdr;

	private :

	friend class IProtocol<ProtocolUDP>;

	size_t	derivedGetStructSize() const // modifier le nom avec derived
	{
	    return sizeof(protocol);
	}

	void	        derivedSetStructProtocol(const char *pData);

	const std::string   derivedGetProtocolFormated() const;

	u_short getSport() const;
	u_short getDport() const;
	short   getUl() const;
	u_short getSum() const;

	public:

	protocol	*pProtoStruct;
    };
}
