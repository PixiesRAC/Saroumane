#include "LogInstanceInitializer.h"
#include "RawSocket.h"
#include "RawSocketProducer.h"
#include "RawSocketConsumer.h"
#include "HackerDuXul.h"
#include <memory>
#include <thread>
#include "JsonConfInstanceInitializer.h"
#ifdef RAC_FILTER 
#include "FilterOutputInstanceInitializer.h"
#endif

#include <getopt.h>
#include <signal.h>

void    intHandler(int dummy)
{
    (void)dummy;
}

#include <iostream>
int main(int argc, char **argv)
{
    std::shared_ptr<RACconf::JsonConfHandler>   spJsonConf(RACconf::JsonConfHandler::GetOrCreateInstance());
    std::unique_ptr<RAClog::FileLogHandler> spLog(RAClog::FileLogHandler::GetOrCreateInstance());
    std::unique_ptr<RACsocket::ISocket> spSocket = std::make_unique<RACsocket::RawSocket>();

    //signal(SIGINT, intHandler);

    int opt = 0;
    while ((opt = getopt(argc, argv, "se")) != -1)
    {
	switch (opt) 
	{
	    case 'e' :
		LOG(INFO, "Mode attack encoder");
		{
		    RAChacker::HackerDuXul hacker;
		    hacker.iWantToFuckSomeMother(spSocket->GetSocketfd());
		    return 0;
		}
	    case 's' :
		LOG(INFO, "Mode sniffer ON");
		{
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

	    default :
		goto bad_arg;
	}
    }
    if (opt == -1)
    {
	goto bad_arg;
    }
    
    bad_arg : 
    LOG(ERROR, "./RAC_RenifleurDuXul -e [ENCODER_MODE : ON] -s [SNIFFER_MODE : ON]"); 
    return 1;
}


