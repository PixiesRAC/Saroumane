#pragma once

#include <string>
#include <vector>
#include <algorithm>

namespace RACfilter
{
    class FilterOutput
    {
	private :

	FilterOutput();

	public :

	~FilterOutput();
	static FilterOutput *GetOrCreateInstance()

	{
	    if (pInstance == nullptr)
	    {
		pInstance = new FilterOutput; 
	    }
	    return pInstance;
	}

	static const std::string  computeAndGetUsefullData(const std::string &data)
	{
	      if (filterKeywords.empty())
	      {
		  return data;
	      }
	      if (std::any_of(filterKeywords.begin(), filterKeywords.end(),
		  [&](const std::string& str){return data.find(str) != std::string::npos;}))
	       {
		   return data;
	       }
	       else
	       {
		   return "";
	       }
	}
	
	private :

	static std::vector<std::string> filterKeywords;
	static FilterOutput		*pInstance;
    };
}
