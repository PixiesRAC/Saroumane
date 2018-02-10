#include "ProtocolEthernet.h"
#include <unistd.h>
#include <sstream>

namespace RACprotocol
{
    ProtocolEthernet::ProtocolEthernet() : pProtoStruct(nullptr)
    {
	pProtoStruct = new protocol;
	bzero(pProtoStruct, sizeof(*pProtoStruct));
    }

    ProtocolEthernet::~ProtocolEthernet()
    {
	if (pProtoStruct != nullptr)
	{
	    delete pProtoStruct;
	}
    }

    std::string		ProtocolEthernet::getMACFormated(const uint8_t *uMAC) const
    {
	char	cMAC[64];

	bzero(cMAC, 64);
	sprintf(cMAC, "%02x::%02x::%02x::%02x::%02x::%02x", 
		(int)uMAC[0], (int)uMAC[1], (int)uMAC[2], (int)uMAC[3], (int)uMAC[4], (int)uMAC[5]);

	return std::string(cMAC);
    }

    const std::string	ProtocolEthernet::derivedGetProtocolFormated() const 
    {
	std::stringstream ss;

	ss << std::endl << "Src MAC: " << getMACFormated(pProtoStruct->uSrcMAC) << std::endl << "Dest MAC: " << getMACFormated(pProtoStruct->uDestMAC) << std::endl << "EtherType: " << getEtherType() << std::endl;
	return ss.str();
    }

    void	ProtocolEthernet::derivedSetStructProtocol(const char* data)
    {
	memcpy(pProtoStruct, data, sizeof(*pProtoStruct));
    }
  
    const uint8_t   *ProtocolEthernet::getDestMAC() const
    {
	return pProtoStruct->uDestMAC;
    }

    const uint8_t   *ProtocolEthernet::getSrcMAC() const
    {
	return pProtoStruct->uSrcMAC;
    }

    uint16_t   ProtocolEthernet::getEtherType() const
    {
	return ( pProtoStruct->uEtherType[0] << 8 |  pProtoStruct->uEtherType[1]);
    }

    void    ProtocolEthernet::setDestMAC(const uint8_t *pDestMAC)
    {
	memcpy(pProtoStruct->uDestMAC, pDestMAC, sizeof(pProtoStruct->uDestMAC));
    }

    void    ProtocolEthernet::setSrcMAC(const uint8_t *pSrcMAC)
    {
	memcpy(pProtoStruct->uSrcMAC, pSrcMAC, sizeof(pProtoStruct->uSrcMAC));
    }

    void    ProtocolEthernet::setEtherType(const uint8_t *pEtherType)
    {
	memcpy(pProtoStruct->uEtherType, pEtherType, sizeof(pProtoStruct->uEtherType));
    }

  }
