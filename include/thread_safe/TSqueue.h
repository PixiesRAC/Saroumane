#pragma once

#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

namespace RACqueue
{
    template <typename T>
	class TSqueue
	{
	    public :

		T	pop()
		{
		    std::unique_lock<std::mutex> mlock(mutex);
		    while (queue.empty())
		    {
			cond.wait(mlock);
		    }
		    auto item = queue.front();
		    queue.pop();
		    return item;
		}

		void	push(const T& data)
		{
		    std::unique_lock<std::mutex> mlock(mutex);
		    queue.push(data);
		    mlock.unlock();
		    cond.notify_one();
		}

	    private :

		static std::queue<T>			queue;
		static std::mutex			mutex;
		static std::condition_variable  	cond;

	};
}
