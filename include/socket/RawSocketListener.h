#pragma once

#include <tuple>
#include "ErrorSocket.h"

namespace RAClistener
{
    class	RawSocketListener
    {
	protected:

	    RawSocketListener();
	    RawSocketListener(const RawSocketListener& obj);
	    RawSocketListener(int fd);
	    ~RawSocketListener() = default;

	    std::tuple<const char*, int>    ReadSocket() const;

	    int				    fd;

	    static  constexpr int	    iMaxIpPacketSize = 65535;
	    RACerror::ErrorSocket            oRawSocketListenerError;
    };
}
