#include "ProtocolUDP.h"

#include <iostream>
#include <string.h>
#include <sstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

namespace RACprotocol
{
    ProtocolUDP::ProtocolUDP()
    {
	pProtoStruct = new protocol;
	bzero(pProtoStruct, sizeof(protocol));
    }

    ProtocolUDP::~ProtocolUDP()
    {
	if (pProtoStruct != nullptr)
	{
	    delete pProtoStruct;
	}
    }

    void    ProtocolUDP::derivedSetStructProtocol(const char *pData)
    {
	memcpy(pProtoStruct, pData, sizeof(*pProtoStruct));
    }
    
    const std::string       ProtocolUDP::derivedGetProtocolFormated() const
    {
	std::stringstream   ss;

	ss << "\033[1;34m@@@ UDP PROTOCOL @@@\033[0m" << std::endl <<
	"Source port: " << getSport() << std::endl <<
	"Destination port: " << getDport() << std::endl << 
	"Length :" << getUl() << std::endl << 
	"Checksum :" << getSum() << std::endl;

	return ss.str();
    }

    u_short ProtocolUDP::getSport() const
    {
#if BYTE_ORDER == LITTLE_ENDIAN
	return __bswap_16(pProtoStruct->uh_sport);
#endif
#if BYTE_ORDER == BIG_ENDIAN
	return pProtoStruct->uh_sport;
#endif
    }

    u_short ProtocolUDP::getDport() const
    {
#if BYTE_ORDER == LITTLE_ENDIAN
	return __bswap_16(pProtoStruct->uh_dport);
#endif
#if BYTE_ORDER == BIG_ENDIAN
	return pProtoStruct->uh_dport;
#endif
    }

    short   ProtocolUDP::getUl() const
    {
#if BYTE_ORDER == LITTLE_ENDIAN
	return __bswap_16(pProtoStruct->uh_ulen);
#endif
#if BYTE_ORDER == BIG_ENDIAN
	return pProtoStruct->uh_ulen;
#endif
    }

    u_short ProtocolUDP::getSum() const
    {
	return pProtoStruct->uh_sum;
    }
}
