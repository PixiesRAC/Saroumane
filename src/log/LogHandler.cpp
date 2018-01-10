#include <iostream>
#include <sstream>
#include "LogHandler.h"
#include "TimeHandler.h"
#include <signal.h>
#include <unistd.h>

static void handler(int sig)
{
    (void)sig;
    alarm(1);
    LOGFLUSH();
}

namespace RAClog
{

    FileLogHandler::FileLogHandler()
    {
	this->CreateFileLog();
	sigset(SIGALRM, handler);
	alarm(1);
    }

    FileLogHandler::~FileLogHandler()
    {
	this->CloseFileLog();
    }

    void FileLogHandler::CreateFileLog()
    {
	if (!oFileStream.is_open())
	{
	    std::stringstream fileStream;

	    fileStream << "log/" << RACtime::TimeHandler::GetTime() << "_" << pFileLogSuffix;
	    oFileStream.open(fileStream.str());
	    try
	    {
		oFileStream.exceptions(oFileStream.failbit);
		LOG(INFO, "File Log Created");
	    }
	    catch (const std::ios_base::failure& e)
	    {
		std::cerr << "An Error has occured during the creation of the file in the folder log" << std::endl <<  
		    e.what() << std::endl;
		FileLogHandler::DeleteInstance();
	    }

	}
    }

    void FileLogHandler::CloseFileLog()
    {
	if (oFileStream.is_open())
	{
	    LOG(INFO, "The log file is going to be close");
	    oFileStream.close();
	}
    }
}
