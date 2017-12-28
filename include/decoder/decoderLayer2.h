#pragma once

#include "ProtocolEthernet.h"

namespace RACdecoder
{
    class DecoderLayer
    {
	public :

	DecoderLayer(const char*);
	Display();
	private :

	template <typename T>
	void	DecodeLayer3(const char* pData);
	template <RACprotocol::ProtocolIP>
	void    DecodeLayer3(const char* pData);
	template <typename T>
	void	DecodeLayer4(const char* pData);
	template <typename T>
	void	DecodeLayer5(const char* pData);
	template <typename T>
	void	DecoderLayer6(const char* pData);

	std::string	sDataDecodeBatching;

    };
}
