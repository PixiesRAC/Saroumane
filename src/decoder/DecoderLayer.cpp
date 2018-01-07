#include "DecoderLayer.h"
#include "TimeHandler.h"
#include <iostream>
#include <sstream>
#include <iomanip>

namespace RACdecoder
{
    DecoderLayer::DecoderLayer(const char* pData) : iDecodedSizeBinaryBuffer(0), sDataLengthToBeDecoded(0)
    {
	sDataDecodeBuffer = "\n";
	sDataDecodeBuffer += RACtime::TimeHandler::GetTime();
	RACprotocol::ProtocolEthernet ProtocolLayer2;
	ProtocolLayer2.setStructProtocol(pData);

	const uint16_t	EtherType = ProtocolLayer2.getEtherType();

	if (EtherType > ETHERTYPE_MINIMAL)
	{
	   sDataDecodeBuffer += ProtocolLayer2.getProtocolFormated();
	   iDecodedSizeBinaryBuffer = sDataDecodeBuffer.length();

	    switch (EtherType)
	    {
		case  etherType::protocol::IPV4 :
		    DecodeLayer<RACprotocol::ProtocolIP>((pData + ProtocolLayer2.getStructSize()));
		    break;
		case  etherType::protocol::ARP :
		    DecodeLayer<RACprotocol::ProtocolARP>((pData + ProtocolLayer2.getStructSize()));
		    break;
		default :
		    DecodeLayer<void>((pData + ProtocolLayer2.getStructSize()));
		    
	    }
	}
	else
	{
	    iDecodedSizeBinaryBuffer = 0;
	    // We receive the size of the data, i ignore it
	}
	sDataDecodeBuffer += "______________________________________________"; // Best code ever
    }

    template <typename T>
	void	DecoderLayer::DecodeLayer(const char *pData)
	{
	    T ProtocolLayer;

	    ProtocolLayer.setStructProtocol(pData);
	    sDataDecodeBuffer += ProtocolLayer.getProtocolFormated();
	    iDecodedSizeBinaryBuffer = sDataDecodeBuffer.length();
	    sDataLengthToBeDecoded -= ProtocolLayer.getStructSize();
	    //LookingForHighProtocolLayer(pData);
	    if (sDataLengthToBeDecoded  > 0)
	    {
		 DecodeLayer<void>(pData + ProtocolLayer.getStructSize());
	    }
	}

    template <>
	void	DecoderLayer::DecodeLayer<RACprotocol::ProtocolIP>(const char *pData)
	{
	    RACprotocol::ProtocolIP ProtocolIP;

	    ProtocolIP.setStructProtocol(pData);
	    sDataDecodeBuffer += ProtocolIP.getProtocolFormated();
	    iDecodedSizeBinaryBuffer = sDataDecodeBuffer.length();
	    sDataLengthToBeDecoded = ProtocolIP.getTotalLength();
	    
	    switch (ProtocolIP.getProtocol())
	    {
		case IPv4::protocol::ICMP :
		    break;
		case IPv4::protocol::IGMP :
		    break;
		case IPv4::protocol::TCP :
		    DecodeLayer<RACprotocol::ProtocolTCP>((pData + ProtocolIP.getStructSize()));
		    break;
		case IPv4::protocol::UDP :
		    DecodeLayer<RACprotocol::ProtocolUDP>((pData + ProtocolIP.getStructSize()));
		    break;
		default :
		    DecodeLayer<void>((pData + ProtocolIP.getStructSize()));
	    }
	}

    template <>
	void	DecoderLayer::DecodeLayer<void>(const char* pData)
	{
	    std::stringstream ss;

	    ss << "Data bytes : " << sDataLengthToBeDecoded << std::endl;
	    ss << computeAndGetInHexa(pData, sDataLengthToBeDecoded) << std::endl;
	    sDataDecodeBuffer += ss.str();
	    iDecodedSizeBinaryBuffer = sDataDecodeBuffer.length();
	}

    std::string	DecoderLayer::computeAndGetInHexa(const char *pData, short sSize)
    {
	std::stringstream   ss;

	for (int i = 0; i != sSize; ++i)
	{
	    ss << std::hex << (short)pData[i] << " ";
	    if (i % 8 == 0 && i >= 8)
		ss << std::endl;
	}
	return ss.str();
    }
}
