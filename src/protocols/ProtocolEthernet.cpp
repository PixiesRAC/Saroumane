#include "ProtocolEthernet.h"
#include <unistd.h>

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

    const std::string	ProtocolEthernet::getProtocolFormated() const
    {
	boost::format fmt("Dest MAC : %02x::%02x::%02x::%02x::%02x::%02x\nSrc MAC  : %02x::%02x::%02x::%02x::%02x::%02x\nEtherType : %d");
	for (int i = 0; i != sizeof(pProtoStruct->uSrcMAC); ++i)
	{
	    fmt % ((int)pProtoStruct->uSrcMAC[i]);
	}
	for (int i = 0; i != sizeof(pProtoStruct->uDestMAC); ++i)
	{
	    fmt % ((int)pProtoStruct->uDestMAC[i]);
	}
	fmt % pProtoStruct->uEtherType;

	return fmt.str();
    }

    void	ProtocolEthernet::setStructProtocol(const char* data)
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

    const uint16_t  ProtocolEthernet::getEtherType() const
    {
	return pProtoStruct->uEtherType;
    } 
}
