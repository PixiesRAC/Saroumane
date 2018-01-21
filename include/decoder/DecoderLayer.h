#pragma once

#include "ProtocolsHeader.h"
#include "LogHandler.h"
#include <iostream>
#include <tuple>

#define	MINIMAL_TRAME_SIZE 40
#define	ETHERTYPE_MINIMAL (unsigned int)1500

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

	    std::string	computeAndGetInHexa(const char *pData, short sSize);

	    std::string		sDataDecodeBuffer;
	    unsigned int	iDecodedSizeBinaryBuffer;
	    short		sDataLengthToBeDecoded;
};

    template <>
	void    DecoderLayer::DecodeLayer<RACprotocol::ProtocolIP>(const char* pData);
    template <> // Void for unknown protocol
	void    DecoderLayer::DecodeLayer<void>(const char* pData);
}
