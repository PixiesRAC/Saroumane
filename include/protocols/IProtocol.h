#pragma once

#include <boost/format.hpp>
#include <string>

namespace RACprotocol
{
    class IProtocol
    {
	public :

	virtual ~IProtocol() = default;

	protected :

	using BYTE = char;

	virtual const	std::string	getProtocolFormated()
	{
	    return ("UNKNOW PROTOCOL");
	};
	virtual	void			setStructProtocol(const char* data) = 0;
    };
}
