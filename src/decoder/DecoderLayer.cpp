#include "DecoderLayer.h"
#include "DecodedData.h"

namespace RACdecoder
{
    DecoderLayer::DecoderLayer(const char* pData) : bIsError(false), iDecodedSizeBinaryBuffer(0)
    {
	std::lock_guard<std::mutex> lock(RACdata::DecodedData::oMutex);
	RACprotocol::ProtocolEthernet ProtocolLayer2;

	ProtocolLayer2.setStructProtocol(pData);
	sDataDecodeBuffer += ProtocolLayer2.getProtocolFormated();

	const uint16_t	EtherType = ProtocolLayer2.getEtherType();
	switch (EtherType)
	{
	    case  etherType::protocol::IPV4 :
		DecodeLayer3<RACprotocol::ProtocolIP>(pData + (sizeof((*(ProtocolLayer2.getStruct()) ))) );
		break;
	    default:
		bIsError = true;
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
	    switch (ProtocolIP.getProtocol())
	    {

	    }
	}
}
