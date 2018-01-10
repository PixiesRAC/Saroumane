#include "FilterOutput.h"
#include "JsonConfHandler.h"
#include <iostream>
#include <unistd.h>
namespace RACfilter
{
    FilterOutput::FilterOutput()
    {
	filterKeywords.push_back(RACconf::JsonConfHandler::GetValueFromConfigFile<std::string>("filter.protocol", ""));
	filterKeywords.push_back(RACconf::JsonConfHandler::GetValueFromConfigFile<std::string>("filter.port", ""));
	filterKeywords.push_back(RACconf::JsonConfHandler::GetValueFromConfigFile<std::string>("filter.ip", ""));

	// delete useless filtre
	auto i = std::begin(filterKeywords);

	while (i != std::end(filterKeywords)) {
	    // Do some stuff
	    if (i->length() < 1)
		i = filterKeywords.erase(i);
	    else
		++i;
	}
    }

    FilterOutput::~FilterOutput()
    {
    }
}
