#pragma once

#include <iostream>
#include <string.h>
#include <sstream>
#include <netinet/ip.h>
#include "IProtocol.h"
#include "ProtocolsDefinition.h"

namespace RACprotocol
{
    class	ProtocolIP : public IProtocol
    {
	public :

	    using protocol  = struct ip;

	    ProtocolIP();
	    virtual ~ProtocolIP() override final;

	    const std::string   getProtocolFormated() const;	
	    void		setStructProtocol(const char* data);

	    BYTE	    getProtocol() const;
	    int		    getSrcIP() const;
	    int		    getDestIP() const;


	private :

		protocol    *pProtoStruct;
    };
}
