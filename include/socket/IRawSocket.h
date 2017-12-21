#pragma once

namespace RACsocket
{
    class IRawSocket
    {
	public :
	    IRawSocket() = default;
	    virtual    ~IRawSocket() = default; 

	protected :

	    virtual int CreateSocket() = 0;
	    virtual int CloseSocket() = 0;
	    virtual int	BindSocket() = 0;

	    int fd;
    };
}
