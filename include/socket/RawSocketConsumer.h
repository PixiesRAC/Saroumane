#pragma once

#include "TSqueue.h"
#include "ErrorSocket.h"
#include <tuple>

namespace RACconsumer
{
    class   RawSocketConsumer
    {
	public :

	    RawSocketConsumer();
	    RawSocketConsumer(const RawSocketConsumer&);
	    const RawSocketConsumer &operator=(const RawSocketConsumer&);

	    int ConsumeQueueAndDisplay();

	private :

	    bool			isOutputAvailable() const;
	    RACerror::ErrorSocket	oRawSocketListenerError;

	    unsigned long					    ulRefferedTime;
	    unsigned long					    ulActualTime;
	    struct timeval					    tv;
	    RACqueue::TSqueue<std::string>			    queue;
    };
}
