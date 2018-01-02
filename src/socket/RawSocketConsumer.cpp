//#include "PacketData.h"
#include "RawSocketConsumer.h"
#include "LogHandler.h"
#include "DecoderLayer.h"
//#include "DecodedData.h"
#include <unistd.h>

namespace RACconsumer
{
    RawSocketConsumer::RawSocketConsumer()
    {
	gettimeofday(&tv,NULL);
	
	ulRefferedTime = 1000000 * tv.tv_sec + tv.tv_usec;
	ulActualTime = ulRefferedTime;
	LOG(INFO, "Consumer RUN, Queue is popping");
    }

    RawSocketConsumer::RawSocketConsumer(const RawSocketConsumer& obj)
    {
	ulRefferedTime = obj.ulRefferedTime;
    }

    bool RawSocketConsumer::isOutputAvailable() const
    {
	if ((ulActualTime - ulRefferedTime) >= 1000)
	{
	    return true;
	}
	return false;
    }

    int RawSocketConsumer::ConsumeQueueAndDisplay()
    {
	while (1)
	{
	    if (isOutputAvailable())
	    {
		ulRefferedTime = ulActualTime;
		std::cout << queue.pop() << std::endl;
	    }
	    gettimeofday(&tv,NULL);
	    ulActualTime = 1000000 * tv.tv_sec + tv.tv_usec;
	}
    }
}
