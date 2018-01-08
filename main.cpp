#include "LogInstanceInitializer.h"
#include "RawSocket.h"
#include "RawSocketProducer.h"
#include "RawSocketConsumer.h"
#include <memory>
#include <thread>
#include "JsonConfInstanceInitializer.h"
#ifdef RAC_FILTER 
#include "FilterOutputInstanceInitializer.h"
#endif

int main()
{
    std::shared_ptr<RACconf::JsonConfHandler>   spJsonConf(RACconf::JsonConfHandler::GetOrCreateInstance());
    std::unique_ptr<RAClog::FileLogHandler> spLog(RAClog::FileLogHandler::GetOrCreateInstance());
    std::unique_ptr<RACsocket::ISocket> spSocket = std::make_unique<RACsocket::RawSocket>();

#ifdef RAC_FILTER 
    std::unique_ptr<RACfilter::FilterOutput> spFilter(RACfilter::FilterOutput::GetOrCreateInstance());
#endif
    RACproducer::RawSocketProducer  producer(spSocket->GetSocketfd());
    RACconsumer::RawSocketConsumer  consumer;


    std::thread tProducer(&RACproducer::RawSocketProducer::ListenRawDataAndDecode, producer);
    std::thread tConsumer(&RACconsumer::RawSocketConsumer::ConsumeQueueAndDisplay, consumer);

    tProducer.join();
    tConsumer.join();
    return 0;
}
