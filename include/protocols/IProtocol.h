#pragma once

#include <boost/format.hpp>
#include <string>

namespace RACprotocol
{
    class IProtocol
    {
	public :

	virtual ~IProtocol() = default;

	using BYTE = char;

	virtual const	std::string	getProtocolFormated() const = 0;
	virtual	void			setStructProtocol(const char* data) = 0;
    };
}
