#include <unistd.h>

#include "LogHandler.h"
//#include "PacketData.h"
#include "RawSocketProducer.h"
#include "TSqueueInitializer.h"


//#include "DecodedData.h"
#include "DecoderLayer.h" 

namespace RACproducer
{

    RawSocketProducer::RawSocketProducer(int fd) : RAClistener::RawSocketListener(fd)
    {
    }

    RawSocketProducer::RawSocketProducer(const RawSocketProducer& obj)
    {
	fd = obj.fd;
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
	}
    }

  int   RawSocketProducer::DecodeAndFillQueue(std::tuple<const char*, int> oData)
  {
      if (((std::get<1>(oData)) > MINIMAL_TRAME_SIZE))
      {
     	RACdecoder::DecoderLayer decoderLayer(std::get<0>(oData));
	queue.push(decoderLayer.getProtocolDecoded());
      }
  }
}
