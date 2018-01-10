#pragma once

#include "RawSocketListener.h"
#include "RawSocketConsumer.h"
#include "TSqueue.h"
#include <tuple>

namespace RACproducer
{
    class	RawSocketProducer : public RAClistener::RawSocketListener
    {
	public:

	    RawSocketProducer();
	    RawSocketProducer(int fd);
	    RawSocketProducer(const RawSocketProducer&);
	    ~RawSocketProducer() = default;

	    int	ListenRawDataAndDecode();

	private :

	   int			DecodeAndFillQueue(std::tuple<const char*, int> oData);

	   RACqueue::TSqueue<std::string>   queue;
    };
}
