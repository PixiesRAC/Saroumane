#include "LogInstanceInitializer.h"

int main()
{
    RAClog::FileLogHandler *log =  RAClog::FileLogHandler::CreateInstance();

    log->CreateFileLog("rac_log_renifleur_du_cul");
    LOG(INFO, "TEST");
    log->CloseFileLog();
    RAClog::FileLogHandler::DeleteInstance();

    return 0;	
}
