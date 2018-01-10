#pragma once

#include "TSqueue.h"

namespace RACqueue
{
    template <typename T>
	std::queue<T>		    TSqueue<T>::queue;
    template <typename T>
	std::mutex		    TSqueue<T>::mutex;
    template <typename T>
	std::condition_variable	    TSqueue<T>::cond;
}
