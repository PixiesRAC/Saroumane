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

    const std::string	    ProtocolIP::getProtocolFormated() const
    {
	std::stringstream   ss;

	ss << "Version: " << (int)getVersion() << "\n" <<
	"Header Length:" <<  (int)getHeaderLength() << "\n" <<
	"Total Length:" << (short)getTotalLength() << "\n" <<
	"Identification:" << (int)getID() << "\n" <<
	"Fragment Offset:" << getOff() << "\n" <<
	"Time to live:" << (int)getTTL() << "\n" <<
	"Protocol:" << (int)getProtocol() << "\n" <<
	"Header checksum:" << getChecksum() << "\n"
	"Source:" << inet_ntoa(getSrcIP()) << "\n"
	"Destination:" << inet_ntoa(getDestIP()) << "\n";

	return ss.str();
    }

    void    ProtocolIP::setStructProtocol(const char *pData)
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
