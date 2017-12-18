#include <iostream>
#include <sstream>
#include "LogHandler.h"
#include "TimeHandler.h"

void RAClog::FileLogHandler::CreateFileLog(const std::string& fileSuffix)
{
    if (!oFileStream.is_open())
    {
	std::stringstream fileStream;

	fileStream << "log/" << RACtime::TimeHandler::GetTime() << "_" << fileSuffix;
	this->oFileStream.open(fileStream.str());
	LOG(INFO, "File Log Created");
    }
}

void RAClog::FileLogHandler::CloseFileLog()
{
    if (oFileStream.is_open())
    {
	LOG(INFO, "The log file is going to be close");
	this->oFileStream.close();
    }
}

