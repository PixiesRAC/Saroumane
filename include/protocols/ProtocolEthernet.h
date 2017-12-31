#pragma once

#include <iostream>
#include <string.h>
#include <sstream>
#include <iomanip>
#include <stdint.h>
#include "IProtocol.h"
#include "ProtocolsDefinition.h"

namespace RACprotocol
{
  class	ProtocolEthernet : public IProtocol
    {
	public :
	    
	    ProtocolEthernet();
	    virtual ~ProtocolEthernet() override final;

	private :
#pragma pack (push, 1)

	    struct	   protocol
	    {
		uint8_t	    uDestMAC[6]; 
		uint8_t	    uSrcMAC[6];
		uint8_t	    uEtherType[2];
	    };

	    struct	    protocol8021Q
	    {	
		uint16_t    Priority : 3,
			    CFI : 1,
			    VLANID : 12;
		short	    sEtherType;
	    };

#pragma pack (pop)

	public :

	struct protocol	*getStruct() const
	{
	    return pProtoStruct;
	}

	virtual const std::string   getProtocolFormated() const override final;
	virtual void		    setStructProtocol(const char* pData) override final;

	const uint8_t	*getDestMAC() const;
	const uint8_t	*getSrcMAC() const;
	const uint16_t	getEtherType() const;

	private :

	struct	protocol    *pProtoStruct;
  };
}
