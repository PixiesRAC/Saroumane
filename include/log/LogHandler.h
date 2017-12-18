
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

	    FileLogHandler(const FileLogHandler&) = delete;
	    FileLogHandler(const FileLogHandler&&) = delete;
	    const FileLogHandler& operator=(const FileLogHandler&) = delete;
	    const FileLogHandler&& operator=(const FileLogHandler&&) = delete;

	private:

	    FileLogHandler();
	    ~FileLogHandler();

	    void			CreateFileLog();
	    void			CloseFileLog();

	public:

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
