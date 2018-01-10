#include "LogInstanceInitializer.h"
#include "RawSocket.h"
#include "RawSocketProducer.h"
#include "RawSocketConsumer.h"
#include <memory>
#include <thread>

int main()
{
    std::unique_ptr<RAClog::FileLogHandler> log(RAClog::FileLogHandler::GetOrCreateInstance());
    std::unique_ptr<RACsocket::ISocket> socket = std::make_unique<RACsocket::RawSocket>();

    RACproducer::RawSocketProducer  producer(socket->GetSocketfd());
    RACconsumer::RawSocketConsumer  consumer;

    std::thread tProducer(&RACproducer::RawSocketProducer::ListenRawDataAndDecode, producer);
    std::thread tConsumer(&RACconsumer::RawSocketConsumer::ConsumeQueueAndDisplay, consumer);

    tProducer.join();
    tConsumer.join();
    return 0;
}
