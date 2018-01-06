#pragma once

#include "ProtocolsHeader.h"
#include "LogHandler.h"
#include <iostream>
#include <tuple>

#define  MINIMAL_TRAME_SIZE 40
#define	 ETHERTYPE_MINIMAL (unsigned int)1500

namespace RACdecoder
{
    class DecoderLayer
    {
	public :

	    DecoderLayer(const char*);
	    ~DecoderLayer() = default;

	    std::string getProtocolDecoded() const
	    {
		return sDataDecodeBuffer;
	    }

	private :

	    template <typename T>
		void	DecodeLayer(const char* pData);

	    std::string		sDataDecodeBuffer;
	    unsigned int	iDecodedSizeBinaryBuffer;
    };

    template <>
	void    DecoderLayer::DecodeLayer<RACprotocol::ProtocolIP>(const char* pData);
}

