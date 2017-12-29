#pragma once

#include "ProtocolsHeader.h"
#include <iostream>

namespace RACdecoder
{
    class DecoderLayer
    {
	public :

	    DecoderLayer(const char*);

	    void	DisplayProtocolDecoded()
	    {
		std::cout << sDataDecodeBuffer << std::endl;
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
	    std::string	sDataDecodeBuffer;
    };

    template <>
	void    DecoderLayer::DecodeLayer3<RACprotocol::ProtocolIP>(const char* pData);
}

