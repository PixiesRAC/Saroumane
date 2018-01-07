#include "RawSocketListener.h"
#include "LogHandler.h"
#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

namespace RAClistener
{
    RawSocketListener::RawSocketListener() 
    {
	fd = -1;
    }

    RawSocketListener::RawSocketListener(const RawSocketListener& obj)
    {
	fd = obj.fd;
    }

    RawSocketListener::RawSocketListener(int fd)
    {
	struct stat statbuf;
	fstat(fd, &statbuf);
	this->fd = fd;

	if (S_ISSOCK(statbuf.st_mode) != 1)
	{
	    oRawSocketListenerError.LogOwnError("Error bad mode file descriptor");
	    oRawSocketListenerError.SetErrorState(true);
	}
    }

    std::tuple<const char*, int>	RawSocketListener::ReadSocket() const
    {

	char	buffer[iMaxIpPacketSize];
	int	iDataRead = 0;

	bzero(&buffer, sizeof(buffer));

	iDataRead = recv(fd, buffer, iMaxIpPacketSize, 0);
	if (iDataRead <= 0 || iDataRead > iMaxIpPacketSize)
	{
	    oRawSocketListenerError.LogErrorFromErno();
	}
	return  std::make_tuple(buffer, iDataRead);
    }
}
