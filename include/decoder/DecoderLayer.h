#pragma once

#include "ProtocolsHeader.h"
#include "LogHandler.h"
#include <iostream>
#include <tuple>

namespace RACdecoder
{
    class DecoderLayer
    {
	public :

	    DecoderLayer(const char*);
	    ~DecoderLayer() = default;

	    std::tuple<const char*, int> getProtocolDecoded()
	    {
		//return sDataDecodeBuffer;
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
	    std::string	    sDataDecodeBuffer;
	    unsigned	int iDecodedSizeBinaryBuffer;
	    bool	    bIsError;
    };

    template <>
	void    DecoderLayer::DecodeLayer3<RACprotocol::ProtocolIP>(const char* pData);
}

