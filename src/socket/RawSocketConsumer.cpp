#include "RawSocketConsumer.h"
#include "LogHandler.h"
#include "DecoderLayer.h"

#include <unistd.h>

#ifdef RAC_FILTER
#include "FilterOutput.h"
#endif

# define WAITING_OUTPUT_MS 10

namespace RACconsumer
{
    RawSocketConsumer::RawSocketConsumer()
    {
	gettimeofday(&tv,NULL);
	
	ulRefferedTime = 1000000 * tv.tv_sec + tv.tv_usec;
	ulActualTime = ulRefferedTime;
    }

    RawSocketConsumer::RawSocketConsumer(const RawSocketConsumer& obj)
    {
	ulRefferedTime = obj.ulRefferedTime;
    }

    bool RawSocketConsumer::isOutputAvailable() const
    {
	return ((ulActualTime - ulRefferedTime) >= WAITING_OUTPUT_MS);
    }

    int RawSocketConsumer::ConsumeQueueAndDisplay()
    {
	LOG(INFO, "Consumer RUN, Queue is popping");
	while (1)
	{
	    if (isOutputAvailable())
	    {
		ulRefferedTime = ulActualTime;
#ifdef RAC_FILTER
		std::cout << RACfilter::FilterOutput::computeAndGetUsefullData(queue.pop());
#else
		std::cout << queue.pop();
#endif
	    }
	    gettimeofday(&tv,NULL);
	    ulActualTime = 1000000 * tv.tv_sec + tv.tv_usec;
	}
	return 0;
    }
}
