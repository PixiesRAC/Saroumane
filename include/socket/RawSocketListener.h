#pragma once

#include <tuple>
#include "ErrorSocket.h"

namespace RAClistener
{
    class	RawSocketListener
    {
	protected:

	    RawSocketListener() {fd = -1;}
	    RawSocketListener(const RawSocketListener& obj)
	    {
		fd = obj.fd;
	    }

	    RawSocketListener(int fd);
	    ~RawSocketListener() = default;

	    std::tuple<const char*, int>    ReadSocket() const;

	    static  constexpr int	    iMaxIpPacketSize = 65535;
	    int				    fd; 

	    RACerror::ErrorSocket            oRawSocketListenerError;
    };
}
