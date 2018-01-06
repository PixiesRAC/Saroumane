#include "DecoderLayer.h"
#include "TimeHandler.h"

#include <iostream>

namespace RACdecoder
{
    DecoderLayer::DecoderLayer(const char* pData) : iDecodedSizeBinaryBuffer(0)
    {
	sDataDecodeBuffer = RACtime::TimeHandler::GetTime();
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
	    T spProtocolLayer;

	    spProtocolLayer.setStructProtocol(pData);
	    sDataDecodeBuffer += spProtocolLayer.getProtocolFormated();
	    iDecodedSizeBinaryBuffer = sDataDecodeBuffer.length();
	}

    template <>
	void	DecoderLayer::DecodeLayer<RACprotocol::ProtocolIP>(const char *pData)
	{
	    RACprotocol::ProtocolIP ProtocolIP;

	    ProtocolIP.setStructProtocol(pData);
	    sDataDecodeBuffer += ProtocolIP.getProtocolFormated();
	    iDecodedSizeBinaryBuffer = sDataDecodeBuffer.length();
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
		    break;
	    }
	}
}
