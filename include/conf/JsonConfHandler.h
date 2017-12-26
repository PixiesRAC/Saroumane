#pragma once

#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/json_parser.hpp"

namespace RACconf
{
    class	JsonConfHandler
    {
	private:

	    JsonConfHandler();
	    JsonConfHandler(const JsonConfHandler&) = delete;
	    JsonConfHandler(const JsonConfHandler&&) = delete;
	    const JsonConfHandler& operator=(const JsonConfHandler&) = delete;
	    const JsonConfHandler&& operator=(const JsonConfHandler&&) = delete;

	public :

	    static JsonConfHandler*  GetOrCreateInstance()
	    {
		if (pInstance == nullptr)
		{
		    pInstance = new JsonConfHandler;
		}
		return pInstance;
	    }

	    template<typename T>
		T	GetValueFromConfigFile(const char* pJsonBalise)
		{
		    return oRoot.get<T>(pJsonBalise);
		}
	    template<typename T>
		T   GetValueFromConfigFile(const char* pJsonBalise, T optionnalValue)
		{
		    return oRoot.get<T>(pJsonBalise, optionnalValue);
		}


	    private :

	    const char* pJsonPathFilename = "conf/RenifleurDuXul.json";
	    boost::property_tree::ptree oRoot;

	    static  JsonConfHandler *pInstance; 
    };

}
