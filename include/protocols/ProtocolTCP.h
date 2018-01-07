#pragma once

#include "IProtocol.h"
#include <netinet/tcp.h>

namespace RACprotocol
{
    class   ProtocolTCP : public IProtocol<ProtocolTCP>
    {
	public :

	    ProtocolTCP();
	    ~ProtocolTCP();

	    using protocol = struct tcphdr;

	private :
	
	    friend class IProtocol<ProtocolTCP>;

	    size_t	derivedGetStructSize() const
	    {
		return sizeof(protocol);
	    }

	    void	        derivedSetStructProtocol(const char *pData);
	    const std::string   derivedGetProtocolFormated() const;

	    u_short	getSport() const;
	    u_short	getDport() const;
	    tcp_seq	getSeq() const;
	    tcp_seq	getAck() const;
	    u_char	getOff() const;
	    u_char	getFlags() const;
	    u_short	getWin() const;	
	    u_short	getSum() const;
	    u_short	getUrp() const;

	public :

	    protocol    *pProtoStruct;
    };
}
