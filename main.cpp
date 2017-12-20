#include "LogInstanceInitializer.h"
#include "RawSocketTCP.h"
#include <memory>

int main()
{
    RAClog::FileLogHandler *log =  RAClog::FileLogHandler::CreateInstance();

    LOG(INFO, "VOICI" << "UN" << "TEST");
    std::unique_ptr<RACsocket::IRawSocket> socket = std::make_unique<RACsocket::RawSocketTCP>();
    RAClog::FileLogHandler::DeleteInstance();

    return 0;
}
