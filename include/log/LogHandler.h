
#pragma once

#include <fstream>
#include "TimeHandler.h"

#define LOG(level, msg)	LOG##level(msg)

#if LOG_UNIT_TEST == 0

#define LOGINFO(msg)  RAClog::FileLogHandler::oFileStream << RACtime::TimeHandler::GetTime() << " [ INFO ] " << " [msg]: " <<  msg << "\n";
#define LOGWARN(msg) RAClog::FileLogHandler::oFileStream << RACtime::TimeHandler::GetTime() << " [ WARN ] " << __FUNCTION__ << " [msg]: " <<  msg << "\n";
#define LOGDEBUG(msg) RAClog::FileLogHandler::oFileStream << RACtime::TimeHandler::GetTime() << " [ DEBUG ] " << __FILE__ << ":" << __LINE__ << "/" << __FUNCTION__ << " [msg]: " << msg << "\n";
#define LOGERROR(msg) RAClog::FileLogHandler::oFileStream << RACtime::TimeHandler::GetTime() << " [ ERROR ] " << __FUNCTION__ << " [msg]: " <<  msg << "\n";
#define LOGFLUSH() RAClog::FileLogHandler::oFileStream.flush();
#else

#define LOGINFO(msg) "[ INFO ] "
#define LOGWARN(msg) "[ WARN ] "
#define LOGDEBUG(msg) "[ DEBUG ] "
#define LOGERROR(msg) "[ ERROR ] "

#endif


namespace RAClog
{
    class	FileLogHandler
    {
	private :

	    FileLogHandler(const FileLogHandler&) = delete;
	    FileLogHandler(const FileLogHandler&&) = delete;
	    const FileLogHandler& operator=(const FileLogHandler&) = delete;
	    const FileLogHandler&& operator=(const FileLogHandler&&) = delete;

	    FileLogHandler();

	    void			CreateFileLog();
	    void			CloseFileLog();

	public:

	    ~FileLogHandler();

	    static FileLogHandler	*GetOrCreateInstance()
	    {
		if (!pInstance)
		{
		    pInstance = new FileLogHandler;
		}
		return pInstance;
	    }

	    static void         DeleteInstance()
	    {
		if (pInstance)
		{
		    delete pInstance;
		}
	    }

	private :

	    static FileLogHandler	*pInstance;
	    const   char		*pFileLogSuffix = "RacRenifleurDuXul";

	public:

	    static std::ofstream    	oFileStream;
    };
}
