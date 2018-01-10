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
		   DecodeLayer3<RACprotocol::ProtocolIP>((pData + ProtocolLayer2.getStructSize()));
		    break;
	    }
	}
	else
	{
	    iDecodedSizeBinaryBuffer = 0;
	    // We receive the size of the data
	}
    }

    template <typename T>
	void	DecoderLayer::DecodeLayer3(const char *pData)
	{
	    T spProtocolLayer3;

	    spProtocolLayer3->setStructProtocol(pData);
	    sDataDecodeBuffer += spProtocolLayer3->getProtocolFormated();
	    iDecodedSizeBinaryBuffer = sDataDecodeBuffer.length();
	}

    template <>
	void	DecoderLayer::DecodeLayer3<RACprotocol::ProtocolIP>(const char *pData)
	{
	    RACprotocol::ProtocolIP ProtocolIP;

	    ProtocolIP.setStructProtocol(pData);
	    sDataDecodeBuffer += ProtocolIP.getProtocolFormated();
	    iDecodedSizeBinaryBuffer = sDataDecodeBuffer.length();
	    switch (ProtocolIP.getProtocol())
	    {

	    }
	}
}
