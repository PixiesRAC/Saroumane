#include "ProtocolIP.h"

#include <iostream>
#include <string.h>
#include <sstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

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

    const std::string	    ProtocolIP::derivedGetProtocolFormated() const
    {
	std::stringstream   ss;

	ss << "Version: " << (int)getVersion() << std::endl <<
	"Header Length:" <<  (int)getHeaderLength() << std::endl <<
	"Total Length:" << (short)getTotalLength() << std::endl <<
	"Identification:" << (int)getID() << std::endl <<
	"Fragment Offset:" << getOff() << std::endl <<
	"Time to live:" << (int)getTTL() << std::endl <<
	"Protocol:" << (int)getProtocol() << std::endl <<
	"Header checksum:" << getChecksum() << std::endl <<
	"Source:" << inet_ntoa(getSrcIP()) << std::endl <<
	"Destination:" << inet_ntoa(getDestIP()) << std::endl;

	return ss.str();
    }

    void    ProtocolIP::derivedSetStructProtocol(const char *pData)
    {
	memcpy(pProtoStruct, pData, sizeof(*pProtoStruct));
    }


    u_char          ProtocolIP::getHeaderLength() const
    {
	return pProtoStruct->ip_hl * 4;
    } 

    u_char          ProtocolIP::getVersion() const
{
	return pProtoStruct->ip_v;
    }

    u_char          ProtocolIP::getTos() const
    {
	return pProtoStruct->ip_tos;
    }

    short           ProtocolIP::getTotalLength() const
    {
	return pProtoStruct->ip_len - getHeaderLength();
    }

    u_short         ProtocolIP::getID() const
    {
	return pProtoStruct->ip_id;
    }

    short           ProtocolIP::getOff() const
    {
	return pProtoStruct->ip_off;
    }

    u_char          ProtocolIP::getTTL() const
    {
	return pProtoStruct->ip_ttl;
    }

    u_char        ProtocolIP::getProtocol() const
    {
	return pProtoStruct->ip_p;
    }

    u_short         ProtocolIP::getChecksum() const
    {
	return pProtoStruct->ip_sum;
    }

    struct in_addr         ProtocolIP::getSrcIP() const
    {
	return pProtoStruct->ip_src;
    }

    struct in_addr		ProtocolIP::getDestIP() const
    {
	return pProtoStruct->ip_dst;
    }
}
