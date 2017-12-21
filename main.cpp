#include "LogInstanceInitializer.h"
#include "RawSocketTCP.h"
#include <memory>

int main()
{
    RAClog::FileLogHandler *log =  RAClog::FileLogHandler::GetOrCreateInstance();

    LOG(INFO, "VOICI" << "UN" << "TEST");
    std::unique_ptr<RACsocket::ISocket> socket = std::make_unique<RACsocket::RawSocketTCP>();
    RAClog::FileLogHandler::DeleteInstance();
    return 0;
}
