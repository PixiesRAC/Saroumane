#include "LogInstanceInitializer.h"

int main()
{
    RAClog::FileLogHandler *log =  RAClog::FileLogHandler::CreateInstance();

    LOG(INFO, "TEST");
    RAClog::FileLogHandler::DeleteInstance();

    return 0;	
}
