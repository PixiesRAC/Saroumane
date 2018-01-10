#pragma once

#include <string>

namespace RACprotocol
{
    template <typename T>
	class IProtocol
	{

	    public :

		struct protocol;

		IProtocol() = default;
		~IProtocol() = default;

		using BYTE = char;

		size_t	getStructSize()
		{
		    return static_cast<T*>(this)->derivedGetStructSize();
		}

		void	setStructProtocol(const char* pData)
		{
		    return static_cast<T*>(this)->derivedSetStructProtocol(pData);
		}

		const	std::string	getProtocolFormated() 
		{
		    return static_cast<T*>(this)->derivedGetProtocolFormated();
		}
	};
}
