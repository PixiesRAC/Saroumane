#include "LogInstanceInitializer.h"
#include "RawDataInstanceInitializer.h"
#include "RawSocketTCP.h"
#include "RawSocketProducer.h"
#include "RawSocketConsumer.h"
#include <memory>
#include <thread>

int main()
{
    std::unique_ptr<RAClog::FileLogHandler> log(RAClog::FileLogHandler::GetOrCreateInstance());
    std::unique_ptr<RACsocket::ISocket> socket = std::make_unique<RACsocket::RawSocketTCP>();

    RACproducer::RawSocketProducer  producer(socket->GetSocketfd());
    RACconsumer::RawSocketConsumer  consumer;


    std::thread tProducer(&RACproducer::RawSocketProducer::ListenRawDataAndFillQueue, producer);
    std::thread tConsumer(&RACconsumer::RawSocketConsumer::ConsumeQueueAndDecode, consumer);


    tProducer.join();
    tConsumer.join();
    return 0;
}
