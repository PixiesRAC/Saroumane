#include <iostream>
#include <sstream>
#include "LogHandler.h"
#include "TimeHandler.h"

RAClog::FileLogHandler::FileLogHandler()
{
    this->CreateFileLog();
}

RAClog::FileLogHandler::~FileLogHandler()
{
    this->CloseFileLog();
}

void RAClog::FileLogHandler::CreateFileLog()
{
    if (!oFileStream.is_open())
    {
	std::stringstream fileStream;

	fileStream << "log/" << RACtime::TimeHandler::GetTime() << "_" << pFileLogSuffix;

	oFileStream.open(fileStream.str());
	try
	{
	    oFileStream.exceptions(oFileStream.failbit);
	}
	catch (const std::ios_base::failure& e)
	{
	    std::cerr << "An Error has occured during the creation of the file in the folder log" << std::endl <<  
	    e.what() << std::endl;
	    FileLogHandler::DeleteInstance();
	}
	LOG(INFO, "File Log Created");
    }
}

void RAClog::FileLogHandler::CloseFileLog()
{
    if (oFileStream.is_open())
    {
	LOG(INFO, "The log file is going to be close");
	oFileStream.close();
    }
}

