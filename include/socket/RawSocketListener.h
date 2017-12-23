#pragma once

#include <tuple>
#include "ErrorSocket.h"

namespace RAClistener
{
    class	RawSocketListener
    {
	protected:

	    RawSocketListener() = delete;
	    RawSocketListener(int fd);
	    ~RawSocketListener() = default;

	    std::tuple<const char*, int>    ReadSocket() const;

	    static const constexpr int	    iMaxIpPacketSize = 65535;
	    int				    fd; 

	    RACerror::ErrorSocket            oRawSocketListenerError;
    };
}
