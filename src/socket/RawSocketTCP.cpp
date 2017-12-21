#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#include "RawSocketTCP.h"
#include "LogHandler.h"
#include "JsonConfInstanceInitializer.h"

namespace RACsocket
{
    RawSocketTCP::RawSocketTCP()
    {
	Config();
	CreateSocket(); 
	if (!oRawSocketTCPError.IsErrorFromRawSocketTCP())
	{
	    LOG(INFO, "Creation of the RAW SOCKET TCP");
	}
    }

    RawSocketTCP::~RawSocketTCP()
    {
	CloseSocket();
    }

    int RawSocketTCP::CreateSocket()
    {
	fd = socket(PF_INET, SOCK_RAW, IPPROTO_TCP);
	if (fd == -1)
	{
	    oRawSocketTCPError.setErrorStateAndLogErrorMsg(true);
	}
    }

    int RawSocketTCP::CloseSocket()
    {
	close(fd);
    }

    int	RawSocketTCP::BindSocket()
    {

    }

    void    RawSocketTCP::Config()
    {
	std::unique_ptr<jsonConf>   spJsonConf(jsonConf::GetOrCreateInstance());

	iPort = spJsonConf->GetValueFromConfigFile<int>("port");
	LOG(DEBUG, spJsonConf->GetValueFromConfigFile<std::string>("ip", "127.0.0.1"));
    }

    const char	*RawSocketTCP::Error::GetErrorFromErno()
    {
	return  strerror(errno);
    }

    bool	RawSocketTCP::Error::IsErrorFromRawSocketTCP()
    {
	return  bErr;
    }

    void	RawSocketTCP::Error::setErrorStateAndLogErrorMsg(bool bFlag)
    {
	LOG(ERROR, GetErrorFromErno());
	bErr = true;
    }
}
