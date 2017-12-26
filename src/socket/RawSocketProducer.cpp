#include <unistd.h>

#include "LogHandler.h"
#include "PacketData.h"
#include "RawSocketProducer.h"

namespace RACproducer
{
    RawSocketProducer::RawSocketProducer(int fd) : RAClistener::RawSocketListener(fd)
    {
    }

    int	RawSocketProducer::ListenRawDataAndFillQueue()
    {
	if (!oRawSocketListenerError.IsError())
	{
	    LOG(INFO, "Producer RUN, Queue is filling");
	    while (1)
	    {
		FillQueue(ReadSocket());
	    }
	}
    }

  int   RawSocketProducer::FillQueue(std::tuple<const char*, int> oData)
  {    
      std::lock_guard<std::mutex> lock(RACdata::RawData::oMutex);
      RACdata::RawData::qData.push(&oData);
  }
}
