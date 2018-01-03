#include "LogHandler.h"
#include "RawSocketProducer.h"
#include "TSqueueInitializer.h"
#include "DecoderLayer.h" 

#include <unistd.h>

namespace RACproducer
{
    RawSocketProducer::RawSocketProducer()
    {
	fd = -1;
    }

    RawSocketProducer::RawSocketProducer(int fd) : RAClistener::RawSocketListener(fd)
    {
    }

    RawSocketProducer::RawSocketProducer(const RawSocketProducer& obj) : RAClistener::RawSocketListener(obj.fd)
    {
    }

    int	RawSocketProducer::ListenRawDataAndDecode()
    {
	if (!oRawSocketListenerError.IsError())
	{
	    LOG(INFO, "Producer RUN, Queue is filling");
	    while (1)
	    {
		DecodeAndFillQueue(ReadSocket());
	    }
	    return 0;
	}
	return 1;
    }

    int   RawSocketProducer::DecodeAndFillQueue(std::tuple<const char*, int> oData)
    {
	if (((std::get<1>(oData)) >= MINIMAL_TRAME_SIZE))
	{
	    RACdecoder::DecoderLayer decoderLayer(std::get<0>(oData));
	    queue.push(decoderLayer.getProtocolDecoded());
	    return 0;
	}
	return 1;
    }
}
