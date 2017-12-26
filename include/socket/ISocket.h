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
	    int	    fd;

	public:

	    virtual int	Bind() = 0;
	    int	    GetSocketfd(); 
    };
}
