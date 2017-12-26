#include "ISocket.h"

namespace RACsocket
{

    int     ISocket::GetSocketfd() const
    {
	return fd;
    }
}
