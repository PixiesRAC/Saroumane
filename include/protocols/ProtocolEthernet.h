#pragma once

#include "IProtocol.h"
#include "ProtocolsDefinition.h"
#include <string.h>
#include <sstream>
#include <iomanip>
#include <stdint.h>

namespace RACprotocol
{
    class	ProtocolEthernet : public IProtocol<ProtocolEthernet>
    {
	public :

	    ProtocolEthernet();
	    ~ProtocolEthernet();

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

	    typedef struct protocol mytype;
#pragma pack (pop)

	private :

	    friend class IProtocol<ProtocolEthernet>;

	   /* mytype	derivedGetStruct() const
	    {
		std::cout << "derived" << std::endl;
		return pProtoStruct;
	    } */

	    size_t		derivedGetStructSize() const
	    {
		    return sizeof(mytype);
	    }

	    void	        derivedSetStructProtocol(const char* pData);
	    const std::string   derivedGetProtocolFormated() const;

	public :

	    const uint8_t	*getDestMAC() const;
	    const uint8_t	*getSrcMAC() const;
	    uint16_t		getEtherType() const;

	private :

	    std::string	    getMACFormated(const uint8_t *) const;

	    struct	protocol    *pProtoStruct;
    };
}
