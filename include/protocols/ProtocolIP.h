#pragma once

#include <netinet/ip.h>
#include "IProtocol.h"
#include "ProtocolsDefinition.h"

namespace RACprotocol
{
    class	ProtocolIP : public IProtocol
    {
	public :

	    using protocol  = struct ip;

	     protocol   *getStruct() const // must be virtual
	     {
		   return pProtoStruct;
	     }


	    ProtocolIP();
	    virtual ~ProtocolIP() override final;

	    const std::string   getProtocolFormated() const;	
	    void		setStructProtocol(const char* data);

	private :
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
