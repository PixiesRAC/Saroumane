#pragma once

#include <netinet/in.h>
#include "IProtocol.h"

namespace RACprotocol
{
    class ProtocolARP : public IProtocol<ProtocolARP>
    {

	public :

	    ProtocolARP();
	    ~ProtocolARP();

	private :

#pragma pack (push, 1)

	struct protocol
	{
	    uint16_t	    uHdwType;
	    uint16_t	    uProtocolType;
	    uint8_t	    uHdwAddrLength; // in bytes
	    uint8_t	    uProtocolAddrLength; // in bytes
	    uint16_t	    uOpe;
	    uint8_t	    uSndrHdwAddr[6];
	    struct  in_addr sSndrInternetAddr;
	    uint8_t	    uTgtHdwAddr[6];
	    struct in_addr  sTgtInternetAddr;
	};

	typedef struct protocol mytype;

#pragma pack (pop)

	private :

	friend class IProtocol<ProtocolARP>;

	/* mytype	derivedGetStruct() const
	   {
	   std::cout << "derived" << std::endl;
	   return pProtoStruct;
	   } */

	size_t		    derivedGetStructSize() const
	{
	    return sizeof(mytype);
	}

	void		    derivedSetStructProtocol(const char* pData);
	const std::string   derivedGetProtocolFormated() const;


	uint16_t	    getHdwType() const;
	uint16_t	    getProtocolType() const;
	uint8_t		    getHdwAddrLength() const;
	uint8_t		    getProtocolAddrLength() const;
	uint16_t	    getOpe() const;
	const uint8_t*	    getSndrHdwAddr() const;
	struct in_addr	    getSndrInternetAddr() const;
	const uint8_t*	    getTgtHdwAddr() const;
	struct in_addr	    getTgtInternetAddr() const;

	mytype	*pProtoStruct;
    };
}
