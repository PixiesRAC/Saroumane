#pragma once

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>

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
	    auto t = std::time(nullptr);
	    auto tm = *std::localtime(&t);

	    std::stringstream oss;
	    oss << std::put_time(&tm, "%d-%m-%Y_%H-%M-%S");
	    return oss.str();
	}
    };
}
