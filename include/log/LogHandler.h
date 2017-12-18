
#pragma once

#include <fstream>

#define LOG(level, msg)	LOG##level(msg)

#if LOG_UNIT_TEST == 0

#define LOGINFO(msg) RAClog::FileLogHandler::oFileStream << "[ INFO ] " << " [msg]: " <<  msg << "\n"; 
#define LOGWARN(msg) RAClog::FileLogHandler::oFileStream << "[ WARN ] " << __FUNCTION__ << " [msg]: " <<  msg << "\n";
#define LOGDEBUG(msg)
#define LOGERROR(msg)

#else

#define LOGINFO(msg) "[ INFO ] "
#define LOGWARN(msg) "[ WARN ] "
#define LOGDEBUG(msg) "[ DEBUG ] "
#define LOGERROR(msg)

#endif


namespace RAClog
{
    class	FileLogHandler
    {

	public:

	    void			CreateFileLog(const std::string& fileSuffix);
	    void			CloseFileLog();

	    static FileLogHandler	*CreateInstance()
	    {
		if (!pInstance)
		{
		    pInstance = new FileLogHandler;
		}
	    }

	    static void		DeleteInstance()
	    {
		if (pInstance)
		{
		    if (oFileStream.is_open())
		    {
			LOG(WARN, "You should Close the Log File with the function CloseFileLog before");
			return ;
		    }
		    delete pInstance;	
		}
	    }

	private :

	    static FileLogHandler	*pInstance;

	public:

	    static std::ofstream    	oFileStream;
    };
}
