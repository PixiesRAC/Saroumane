#include "DecoderLayer.h"

namespace RACdecoder
{
    DecoderLayer::DecoderLayer(const char* pData)
    {
	RACprotocol::ProtocolEthernet ProtocolLayer2;

	ProtocolLayer2.setStructProtocol(pData);
	//	    switch (protocol.GetEtherType)
	//IP :
	//DecodeLayer3<RACprotocol::ProtocolIP>(pData + (sizeof(protocol.getStruct))

	sDataDecodeBuffer += ProtocolLayer2.getProtocolFormated();
	DecodeLayer3<RACprotocol::ProtocolIP>(pData);
	std::cout << "LAYER 2 " << std::endl;
    }

    template <typename T>
	void	DecoderLayer::DecodeLayer3(const char *pData)
	{
	    std::cout << "Layer 3 " << std::endl;
	    std::unique_ptr<RACprotocol::IProtocol> spProtocolLayer3 = std::make_unique<T>();

	    spProtocolLayer3->setStructProtocol(pData);
	    sDataDecodeBuffer += spProtocolLayer3->getProtocolFormated();
	}

    template <>
	void	DecoderLayer::DecodeLayer3<RACprotocol::ProtocolIP>(const char *pData)
	{
	    std::cout << "LAYER 3 UNDER SPECIALIZATION" << std::endl;
	    RACprotocol::ProtocolIP ProtocolIP;

	    ProtocolIP.setStructProtocol(pData);

	    sDataDecodeBuffer += ProtocolIP.getProtocolFormated();
	}
}
