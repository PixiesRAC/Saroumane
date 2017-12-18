#pragma once

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
	    return ("123");
	}
    };
}
