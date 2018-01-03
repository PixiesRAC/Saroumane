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
		void	DecodeLayer3(const char* pData);
	    /*	template <typename T>
		void	DecodeLayer4(const char* pData);
		template <typename T>
		void	DecodeLayer5(const char* pData);
		template <typename T>
		void	DecoderLayer6(const char* pData);
	     */

	    std::string		sDataDecodeBuffer;
	    unsigned int	iDecodedSizeBinaryBuffer;
    };

    template <>
	void    DecoderLayer::DecodeLayer3<RACprotocol::ProtocolIP>(const char* pData);
}

