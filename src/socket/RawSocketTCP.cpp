#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#include "RawSocketTCP.h"
#include "LogHandler.h"

namespace RACsocket
{
    RawSocketTCP::RawSocketTCP()
    {
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
	if (!fd)
	{
	    oRawSocketTCPError.setAndLogErrorFromRawSocketTCP(true);
	}
    }

    int RawSocketTCP::CloseSocket()
    {
	close(fd);
    }

    const char	*RawSocketTCP::RawSocketTCPError::GetErrorFromErno()
    {
	return  strerror(errno);
    }

    bool	RawSocketTCP::RawSocketTCPError::IsErrorFromRawSocketTCP()
    {
	return  bErrFromRawSocketTCP;
    }

    void	RawSocketTCP::RawSocketTCPError::setAndLogErrorFromRawSocketTCP(bool bFlag)
    {
	LOG(ERROR, GetErrorFromErno());
	bErrFromRawSocketTCP = true;
    }
}
