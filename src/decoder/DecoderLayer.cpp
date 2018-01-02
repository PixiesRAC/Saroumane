#include "DecoderLayer.h"
#include "TimeHandler.h"
//#include "DecodedData.h"

namespace RACdecoder
{
    DecoderLayer::DecoderLayer(const char* pData) : bIsError(false), iDecodedSizeBinaryBuffer(0)
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
		    DecodeLayer3<RACprotocol::ProtocolIP>(pData + (sizeof((*(ProtocolLayer2.getStruct()) ))) );
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
	    std::unique_ptr<RACprotocol::IProtocol> spProtocolLayer3 = std::make_unique<T>();

	    spProtocolLayer3->setStructProtocol(pData);
	    sDataDecodeBuffer += spProtocolLayer3->getProtocolFormated();
	}

    template <>
	void	DecoderLayer::DecodeLayer3<RACprotocol::ProtocolIP>(const char *pData)
	{
	    RACprotocol::ProtocolIP ProtocolIP;

	    ProtocolIP.setStructProtocol(pData);
	    sDataDecodeBuffer += ProtocolIP.getProtocolFormated();
	    iDecodedSizeBinaryBuffer =sDataDecodeBuffer.length();
	    switch (ProtocolIP.getProtocol())
	    {

	    }
	}
}
