#include "DecoderLayer.h"

DecoderLayer::DecoderLayer(const char* pData)
{
    RACprotocol::ProtocolEthernet ProtocolLayer2;

    ProtocolLayer2.setStructProtocol(pData);
    switch (protocol.GetEtherType)
    {
	IP :
	    DecodeLayer3<RACprotocol::ProtocolIP>(pData + (sizeof(protocol.getStruct))

    sDataDecodeBatching += protocol.getProtocolFormated();
    }
}

template <typename T>
DecoderLayer::DecodeLayer3(const char *pdata)
{
    std::unique_ptr<RACprotocol::IProtocol> spProtocolLayer3 = std::make_unique<T>();

    ProtocolLayer2->setStructProtocol(pData);
    sDataDecoderBatching += protocol->GetProtocolFormated();
}

template <>
DecoderLayer::DecodeLayer3<RACprotocol::ProtocolIP>(const char *pdata)
{
    RACprotocol::ProtocolIP p;

    P.setStructProtocol(pData);

    switch (p.getProtocol)
    {
	case : TCP
	   DecodeLayer4<RACprotocol::ProtocolTCP>(pData + (sizeof(protocol.getStruc))
    }

    sDataDecoderBatching += p.GetProtocolFormated();
}


