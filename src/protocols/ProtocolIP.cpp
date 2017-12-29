#include "ProtocolIP.h"

namespace RACprotocol
{

    ProtocolIP::ProtocolIP()
    {
	pProtoStruct = new protocol;
	bzero(pProtoStruct, sizeof(protocol));
    }

    ProtocolIP::~ProtocolIP()
    {
	if (pProtoStruct != nullptr)
	{
	    delete pProtoStruct;
	}
    }

    const std::string	ProtocolIP::getProtocolFormated() const
    {
	return std::string("");
    }

    void    ProtocolIP::setStructProtocol(const char *pData)
    {
	memcpy(pProtoStruct, pData, sizeof(*pProtoStruct));
    }

    BYTE        ProtocolIP::getProtocol() const
    {
    }
    int         ProtocolIP::getSrcIP() const
    {
    }
    int		ProtocolIP::getDestIP() const
    {
    }
}
