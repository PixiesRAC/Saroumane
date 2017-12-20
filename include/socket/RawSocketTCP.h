#pragma once

#include "IRawSocket.h"

namespace RACsocket
{
    class RawSocketTCP : public IRawSocket
    {
	public:

	    RawSocketTCP();
	    ~RawSocketTCP();

	private :

	    virtual int open();
	    virtual int close();
    };
}
