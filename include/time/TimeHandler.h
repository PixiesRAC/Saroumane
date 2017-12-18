#pragma once

#include <sstream>
#include <sys/time.h>

#define SIZE_ISO8601_WITH_MILI 25

namespace RACtime
{
    class	TimeHandler
    {
	TimeHandler() = delete;
	~TimeHandler() = delete;
	TimeHandler(const TimeHandler&) = delete;
	TimeHandler& operator=(const TimeHandler&) = delete;
	TimeHandler(const TimeHandler&&) = delete;
	TimeHandler&& operator=(const TimeHandler&&) = delete;

	public :

	static const std::string GetTime()
	{
	    std::stringstream ss;

	    timeval curTime;
	    gettimeofday(&curTime, NULL);
	    int milli = curTime.tv_usec / 1000;

	    char buffer [SIZE_ISO8601_WITH_MILI] = "";
	    strftime(buffer, sizeof(buffer), "%Y-%m-%dT%H:%M:%S", localtime(&curTime.tv_sec)); // ISO 8601
	    ss << buffer << "." << milli;
	    return ss.str();
	}
    };
}
