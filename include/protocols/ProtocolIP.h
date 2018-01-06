#pragma once

#include <netinet/ip.h>
#include "IProtocol.h"
#include "ProtocolsDefinition.h"

namespace RACprotocol
{
    class	ProtocolIP : public IProtocol<ProtocolIP>
    {
	public :

	    ProtocolIP();
	    ~ProtocolIP();

	    using protocol  = struct ip;

	    size_t	getStructSize() const
	    {
		return sizeof(protocol);
	    }


	private :

	    friend class IProtocol<ProtocolIP>;

	    void		derivedSetStructProtocol(const char* pData);

	    const std::string   derivedGetProtocolFormated() const;	

	    u_char	    getHeaderLength() const;
	    u_char	    getVersion() const;
	    u_char	    getTos() const;
	    short	    getTotalLength() const;
	    u_short	    getID() const;
	    short	    getOff() const;
	    u_char	    getTTL() const;
	    u_short	    getChecksum() const;
	    struct  in_addr getSrcIP() const;
	    struct  in_addr getDestIP() const;

	public :

	    u_char	    getProtocol() const;

	    protocol    *pProtoStruct;
    };
}
