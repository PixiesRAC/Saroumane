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
	"Sender IP address: " << inet_ntoa((*(struct in_addr*)&pProtoStruct->uSndrInternetAddr)) << std::endl <<
	"Target MAC address: " << getMACFormated(getTgtHdwAddr()) << std::endl;
	// warning lorsque je continue la boucle de "<<" la target ip est egale a la sender ip avec la meme ligne de code
	ss << "Target IP address: " << inet_ntoa((*(struct in_addr*)&pProtoStruct->uTgtInternetAddr))  << std::endl;

	return ss.str();
    }

    uint16_t ProtocolARP::getHdwType() const
    {
#if BYTE_ORDER == LITTLE_ENDIAN
	return __bswap_16(pProtoStruct->uHdwType);
#endif
#if BYTE_ORDER == BIG_ENDIAN 
	return pProtoStruct->uHdwType;
#endif
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
#if BYTE_ORDER == LITTLE_ENDIAN
	return __bswap_16(pProtoStruct->uOpe);
#endif
#if BYTE_ORDER == BIG_ENDIAN
	return pProtoStruct->uOpe;
#endif
    }

    const uint8_t  *      ProtocolARP::getSndrHdwAddr() const
    {
	return pProtoStruct->uSndrHdwAddr;	
    }

    uint32_t      ProtocolARP::getSndrInternetAddr() const
    {
	return pProtoStruct->uSndrInternetAddr;
    }

    const uint8_t*      ProtocolARP::getTgtHdwAddr() const
    {
	return pProtoStruct->uTgtHdwAddr;
    }

    uint32_t    ProtocolARP::getTgtInternetAddr() const
    {
	return pProtoStruct->uTgtInternetAddr;
    }

    void	ProtocolARP::setHdwType(uint16_t uHdwType)
    {
	pProtoStruct->uHdwType = uHdwType;
    }

    void	ProtocolARP::setProtocolType(uint16_t uProtocolType)
    {
	pProtoStruct->uProtocolType = uProtocolType;
    }

    void	ProtocolARP::setHdwAddrLength(uint8_t uHdwAddrLength)
    {
	pProtoStruct->uHdwAddrLength = uHdwAddrLength;
    }
    
    void	ProtocolARP::setProtocolAddrLength(uint8_t uProtocolAddrLength)
    {
	pProtoStruct->uProtocolAddrLength = uProtocolAddrLength;
    }

    void	ProtocolARP::setOpe(uint16_t uOpe)
    {
	pProtoStruct->uOpe = uOpe;
    }

    void	ProtocolARP::setSndrHdwAddr(const uint8_t* uSndrHdwAddr)
    {
	memcpy(pProtoStruct->uSndrHdwAddr, uSndrHdwAddr, sizeof(pProtoStruct->uSndrHdwAddr));
    }

    void	ProtocolARP::setSndrInternetAddr(uint32_t uSndrInternetAddr)
    {

	pProtoStruct->uSndrInternetAddr = uSndrInternetAddr;
    }

    void	ProtocolARP::setTgtHdwAddr(const uint8_t* uTgtHdwAddr)
    {
	 memcpy(pProtoStruct->uTgtHdwAddr, uTgtHdwAddr, sizeof(pProtoStruct->uTgtHdwAddr));
    }

    void	ProtocolARP::setTgtInternetAddr(uint32_t uTgtInternetAddr)
    {
	pProtoStruct->uTgtInternetAddr = uTgtInternetAddr;
    }

}
