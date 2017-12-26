#pragma once

#include "RawSocketListener.h"

namespace RACproducer
{
    class	RawSocketProducer : public RAClistener::RawSocketListener
    {
	public:

	    RawSocketProducer() = delete;
	    RawSocketProducer(int fd);
	    ~RawSocketProducer() = default;

	    int	ListenRawDataAndFillQueue();

	private :

	   int			FillQueue(std::tuple<const char*, int> oData);

    };
}
