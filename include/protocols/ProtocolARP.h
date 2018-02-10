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
	    uint32_t	    uSndrInternetAddr;
	    uint8_t	    uTgtHdwAddr[6];
	    uint32_t	    uTgtInternetAddr;
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


	public :

	mytype		    *getProtocol() const
	{
	    return pProtoStruct;
	}

	uint16_t	    getHdwType() const;
	uint16_t	    getProtocolType() const;
	uint8_t		    getHdwAddrLength() const;
	uint8_t		    getProtocolAddrLength() const;
	uint16_t	    getOpe() const;
	const uint8_t*	    getSndrHdwAddr() const;
	uint32_t    	    getSndrInternetAddr() const;
	const uint8_t*	    getTgtHdwAddr() const;
	uint32_t    	    getTgtInternetAddr() const;

	void	    setHdwType(uint16_t);
	void	    setProtocolType(uint16_t);
	void	    setHdwAddrLength(uint8_t);
	void	    setProtocolAddrLength(uint8_t);
	void	    setOpe(uint16_t);
	void	    setSndrHdwAddr(const uint8_t*);
	void	    setSndrInternetAddr(uint32_t );
	void	    setTgtHdwAddr(const uint8_t*);
	void	    setTgtInternetAddr(uint32_t);

	private :

	mytype	*pProtoStruct;
    };
}
