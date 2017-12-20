#pragma once

namespace RACsocket
{
    class IRawSocket
    {
	public :
	    IRawSocket() = default;
	    virtual    ~IRawSocket() = default;


	protected :

	    virtual int open() = 0;
	    virtual int close() = 0;

	    int fd;
    };
}
