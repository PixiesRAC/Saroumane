#include "ProtocolTCP.h"

#include <iostream>
#include <string.h>
#include <sstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

namespace RACprotocol
{

    ProtocolTCP::ProtocolTCP() : pProtoStruct(nullptr)
    {
	pProtoStruct = new protocol;
	bzero(pProtoStruct, sizeof(protocol));
    }

    ProtocolTCP::~ProtocolTCP()
    {
	if (pProtoStruct != nullptr)
	{
	    delete pProtoStruct;
	}
    }

    void    ProtocolTCP::derivedSetStructProtocol(const char *pData)
    {
	memcpy(pProtoStruct, pData, sizeof(*pProtoStruct));
    }

    const std::string       ProtocolTCP::derivedGetProtocolFormated() const
    {
	std::stringstream   ss;
    
	ss << "\033[1;33m@@@ TCP PROTOCOL @@@\033[0m" << std::endl <<
	"Source port: " << getSport() << std::endl <<
	"Destination port: " << getDport() << std::endl <<
	"Sequence number: " << getSeq() << std::endl <<
	"Acknowledgement number: " << getAck() << std::endl <<
	"Header length: " << (unsigned short)getOff() << std::endl <<
	"Flags: " << (unsigned int)getFlags() << std::endl <<
	"Window size value: " << getWin() << std::endl <<
	"Checksum : " << getSum() << std::endl;
	return ss.str();
    
    }

    u_short ProtocolTCP::getSport() const
    {
#if BYTE_ORDER == LITTLE_ENDIAN
	return __bswap_16(pProtoStruct->th_sport);
#endif
#if BYTE_ORDER == BIG_ENDIAN
	return pProtoStruct->th_sport;
#endif
    }

    u_short ProtocolTCP::getDport() const
    {
#if BYTE_ORDER == LITTLE_ENDIAN
	return __bswap_16(pProtoStruct->th_dport);
#endif
#if BYTE_ORDER == BIG_ENDIAN
	return pProtoStruct->th_dport;
#endif
    }

    tcp_seq ProtocolTCP::getSeq() const
    {
	return pProtoStruct->th_seq;
    }

    tcp_seq ProtocolTCP::getAck() const
    {
	return pProtoStruct->th_ack;	
    }

    u_char  ProtocolTCP::getOff() const
    {
#if BYTE_ORDER == LITTLE_ENDIAN
	return __bswap_16(pProtoStruct->th_off);
#endif
#if BYTE_ORDER == BIG_ENDIAN
	return pProtoStruct->th_off;
#endif
    }

    u_char  ProtocolTCP::getFlags() const
    {
#if BYTE_ORDER == LITTLE_ENDIAN
	return __bswap_16(pProtoStruct->th_flags);
#endif
 #if BYTE_ORDER == BIG_ENDIAN
	return pProtoStruct->th_flags;
#endif
   }

    u_short ProtocolTCP::getWin() const
    {
#if BYTE_ORDER == LITTLE_ENDIAN
	return __bswap_16(pProtoStruct->th_win);
#endif
 #if BYTE_ORDER == BIG_ENDIAN
	return pProtoStruct->th_win;
#endif
   }

    u_short ProtocolTCP::getSum() const
    {
#if BYTE_ORDER == LITTLE_ENDIAN
	return __bswap_16(pProtoStruct->th_sum);
#endif
 #if BYTE_ORDER == BIG_ENDIAN
	return pProtoStruct->th_sum;
#endif
   }

    u_short ProtocolTCP::getUrp() const
    {
#if BYTE_ORDER == LITTLE_ENDIAN
	return __bswap_16(pProtoStruct->th_urp);
#endif
 #if BYTE_ORDER == BIG_ENDIAN
	return pProtoStruct->th_urp;
#endif
   }

} 
