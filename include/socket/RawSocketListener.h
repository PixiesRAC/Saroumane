#pragma once

#include "ISocketListener.h"

namespace RAClistener
{
    class	RawSocketListener : public ISocketListener
    {
	public:

	    RawSocketListener() = delete;
	    RawSocketListener(int fd);
	    virtual ~RawSocketListener();

	private :

	    virtual int ReadFromSocket() override final;
    };
}
