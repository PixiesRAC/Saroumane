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
		RACdata::RawData::qData.pop();
	    }
	}
    }

    int RawSocketConsumer::DecodeRawData(std::tuple<const char*, int> *oData)
    {
	RACdecoder::DecoderLayer decodeLayer(std::get<0>(*oData));

	decoderLayer.Display();

/*	proto.setStructProtocol(std::get<0>(*oData));
	std::cout << proto.getProtocolFormated() << std::endl;
	std::cout << std::get<1>(*oData) << std::endl; */
    }

}
