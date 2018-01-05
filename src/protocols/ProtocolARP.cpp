#include "ProtocolARP.h"
#include <unistd.h>
#include <string.h>
#include <sstream>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <byteswap.h>

namespace RACprotocol
{
    ProtocolARP::ProtocolARP() : pProtoStruct(nullptr)
    {
	pProtoStruct = new mytype;
	bzero(pProtoStruct, sizeof(*pProtoStruct));
    }

    ProtocolARP::~ProtocolARP()
    {
	if (pProtoStruct != nullptr)
	{
	    delete pProtoStruct;
	}
    }

    void    ProtocolARP::derivedSetStructProtocol(const char* pData)
    {
	memcpy(pProtoStruct, pData, sizeof(*pProtoStruct));
    }

    std::string         getMACFormated(const uint8_t *uMAC)
    {
	char    cMAC[64];

	bzero(cMAC, 64);
	sprintf(cMAC, "%02x::%02x::%02x::%02x::%02x::%02x",
		(int)uMAC[0], (int)uMAC[1], (int)uMAC[2], (int)uMAC[3], (int)uMAC[4], (int)uMAC[5]);

	return std::string(cMAC);
    }

    const std::string	    ProtocolARP::derivedGetProtocolFormated() const
    {
	std::stringstream   ss;

	ss << "\033[1;32m@@@ ARP PROTOCOL @@@\033[0m" << std::endl <<
	"Hardware type: " << getHdwType() << std::endl <<
	"Protocol type: " << getProtocolType() << std::endl <<
	"Hardware size: " << getHdwAddrLength() << std::endl <<
	"Protocol size: " << getProtocolAddrLength() << std::endl <<
	"Opcode : " << getOpe() << std::endl << 
	"Sender MAC address: " << getMACFormated(getSndrHdwAddr()) << std::endl <<
	"Sender IP address: " << inet_ntoa(getSndrInternetAddr()) << std::endl <<
	"Target MAC address: " << getMACFormated(getTgtHdwAddr()) << std::endl <<
	"Target IP address: " << inet_ntoa(getTgtInternetAddr())  << std::endl;

	return ss.str();
    }

    uint16_t ProtocolARP::getHdwType() const
    {
	return __bswap_16(pProtoStruct->uHdwType);
    }

    uint16_t ProtocolARP::getProtocolType() const
    {
	return pProtoStruct->uProtocolType;
    }

    uint8_t ProtocolARP::getHdwAddrLength() const
    {
	return pProtoStruct->uHdwAddrLength;
    }

    uint8_t ProtocolARP::getProtocolAddrLength() const
    {
	return pProtoStruct->uProtocolAddrLength;
    }

    uint16_t ProtocolARP::getOpe() const
    {
	return __bswap_16(pProtoStruct->uOpe);
    }

    const uint8_t  *      ProtocolARP::getSndrHdwAddr() const
    {
	return pProtoStruct->uSndrHdwAddr;	
    }

    struct in_addr      ProtocolARP::getSndrInternetAddr() const
    {
	return pProtoStruct->sSndrInternetAddr;
    }

    const uint8_t*      ProtocolARP::getTgtHdwAddr() const
    {
	return pProtoStruct->uTgtHdwAddr;
    }

    struct in_addr    ProtocolARP::getTgtInternetAddr() const
    {
	return pProtoStruct->sTgtInternetAddr;
    }
}
