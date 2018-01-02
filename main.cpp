#include "LogInstanceInitializer.h"
//#include "RawDataInstanceInitializer.h"
#include "RawSocketTCP.h"
#include "RawSocketProducer.h"
#include "RawSocketConsumer.h"
#include "DecodedDataHandler.h"
#include <memory>
#include <thread>

int main()
{
    std::unique_ptr<RAClog::FileLogHandler> log(RAClog::FileLogHandler::GetOrCreateInstance());
    std::unique_ptr<RACsocket::ISocket> socket = std::make_unique<RACsocket::RawSocketTCP>();

    RACproducer::RawSocketProducer  producer(socket->GetSocketfd());

    //producer.ListenRawDataAndFillQueue();
    RACconsumer::RawSocketConsumer  consumer;
    //RACreader::DecodedDataHandler   reader;

    std::thread tProducer(&RACproducer::RawSocketProducer::ListenRawDataAndDecode, producer);
    std::thread tConsumer(&RACconsumer::RawSocketConsumer::ConsumeQueueAndDisplay, consumer);
    //std::thread tReader(&RACreader::DecodedDataHandler::ReadDecodedValue, reader);

    tProducer.join();
    tConsumer.join();
    //tReader.join();
    return 0;
}
