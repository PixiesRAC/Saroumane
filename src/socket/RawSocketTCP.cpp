#include "LogHandler.h"
#include "RawSocketTCP.h"
#include "JsonConfInstanceInitializer.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>

namespace RACsocket
{
    RawSocketTCP::RawSocketTCP()
    {
	Config();
	CreateSocket(); 
	if (!oRawSocketTCPError.IsErrorFromRawSocketTCP())
	{
	    LOG(INFO, "Raw Socket Tcp Creation : DONE SUCCESS");
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
	    oRawSocketTCPError.SetErrorStateAndLogErrorFromErno(true);
	}
	return fd;
    }

    int RawSocketTCP::CloseSocket()
    {
	return close(fd);
    }

    int	RawSocketTCP::Bind()
    {
	sockaddr_in addr;

	if (setsockopt(fd, SOL_SOCKET, SO_BINDTODEVICE, sInterface.c_str(), sInterface.length()) == -1)
	{
	    oRawSocketTCPError.SetErrorStateAndLogErrorFromErno(true);
	    return -1;
	}
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(iPort);
	addr.sin_addr.s_addr = inet_addr(sIp.c_str());
	if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1)
	{
	    oRawSocketTCPError.SetErrorStateAndLogErrorFromErno(true);
	    return -1;
	}
	return 1;
    }

    void    RawSocketTCP::Config()
    {
	std::unique_ptr<jsonConf>   spJsonConf(jsonConf::GetOrCreateInstance());

	try{
	    iPort = spJsonConf->GetValueFromConfigFile<int>("sniffer.port");
	    sIp = spJsonConf->GetValueFromConfigFile<std::string>("sniffer.ip", "127.0.0.1");
	    sInterface = spJsonConf->GetValueFromConfigFile<std::string>("sniffer.interface", "lo");
	}
	catch (std::exception &e)
	{
	    oRawSocketTCPError.SetErrorStateAndLogOwnError(true, e.what());
	}
    }

    bool	RawSocketTCP::Error::IsErrorFromRawSocketTCP() const
    {
	return bErr;
    }

    void        RawSocketTCP::Error::SetErrorStateAndLogErrorFromErno(bool bErrorFlag)
    {
	SetErrorState(bErrorFlag);
	LogErrorFromErno();
    }

    void	RawSocketTCP::Error::SetErrorStateAndLogOwnError(bool bErrorFlag, const char* pErrMsg)
    {
	SetErrorState(bErrorFlag);
	SetOwnErrorLog(pErrMsg);
    }




}
