#include "PacketData.h"
#include "RawSocketConsumer.h"
#include "PacketData.h"
#include "LogHandler.h"
#include "DecoderLayer.h"
#include "DecodedData.h"
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
	    if (!RACdata::RawData::qData.empty())
	    {
		std::lock_guard<std::mutex> lock(RACdata::RawData::oMutex);
		DecodeRawData(RACdata::RawData::qData.front());
		RACdata::RawData::qData.pop();
	    }
	}
    }

    int RawSocketConsumer::DecodeRawData(std::tuple<const char*, int> *oData)
    {
	if (((std::get<1>(*oData)) > 0))
	{
	    RACdecoder::DecoderLayer decoderLayer(std::get<0>(*oData));

	   // std::lock_guard<std::mutex> lock(RACdata::DecodedData::oMutex);
	    RACdata::DecodedData::qData.push(decoderLayer.getProtocolDecoded());
	}
    }
}
