#include "LogInstanceInitializer.h"
#include "RawSocketTCP.h"
#include "RawSocketListener.h"
#include <memory>

int main()
{
    RAClog::FileLogHandler *log =  RAClog::FileLogHandler::GetOrCreateInstance();
    std::unique_ptr<RACsocket::ISocket> socket = std::make_unique<RACsocket::RawSocketTCP>();
    socket->Bind();
    std::unique_ptr<RAClistener::ISocketListener> listener = std::make_unique<RAClistener::RawSocketListener>(socket->GetSocketfd());
    RAClog::FileLogHandler::DeleteInstance();
    return 0;
}
