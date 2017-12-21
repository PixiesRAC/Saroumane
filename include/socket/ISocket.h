#pragma once

namespace RACsocket
{
    class ISocket
    {
	public :
	    ISocket() = default;
	    virtual    ~ISocket() = default; 

	protected :

	    virtual int CreateSocket() = 0;
	    virtual int CloseSocket() = 0;
	    virtual int	BindSocket() = 0;

	    int fd;
    };
}
