#include <iostream>
#include <sstream>
#include "LogHandler.h"
#include "TimeHandler.h"

void RAClog::FileLogHandler::CreateFileLog(const std::string& fileSuffix)
{
    if (!oFileStream.is_open())
    {
	std::stringstream fileStream;
	oFileStream.open(fileStream.str());

	fileStream << "log/" << RACtime::TimeHandler::GetTime() << "_" << fileSuffix;

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

