#pragma once

#include <queue>
#include <tuple>
#include <mutex>

namespace RACdata
{
    class   DecodedData
    {
	public :

	static std::queue<std::tuple<const char*, int>> qData;
	static std::mutex oMutex;
    };
}
