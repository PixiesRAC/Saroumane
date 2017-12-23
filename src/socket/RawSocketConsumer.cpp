#include "PacketData.h"
#include "RawSocketConsumer.h"
#include "PacketData.h"
#include "LogHandler.h"
#include <unistd.h>

namespace RACconsumer
{
    RawSocketConsumer::RawSocketConsumer()
    {
	LOG(INFO, "Consumer RUN, Queue is popping");
    }

    int RawSocketConsumer::ConsumeQueueAndDecode()
    {
	while (1)
	{
	    std::lock_guard<std::mutex> lock(RACdata::RawData::oMutex);
	    if (!RACdata::RawData::qData.empty())
	    {
		DecodeRawData(RACdata::RawData::qData.front());
	    }
	}
    }

    int RawSocketConsumer::DecodeRawData(std::tuple<const char*, int> *oData)
    {
	write(1, "DECODE", 6);
	write(1, std::get<0>(*oData), std::get<1>(*oData));
	RACdata::RawData::qData.pop();
    }

}
