#include "RawSocketListener.h"
#include "LogHandler.h"
#include <netinet/in.h>
#include <strings.h>
#include <iostream>
       #include <unistd.h>



namespace RAClistener
{
    RawSocketListener::RawSocketListener(int fd)
    {
	ISocketListener::fd = fd;
	std::cout << this->fd << std::endl;
	ReadFromSocket();
    }

    RawSocketListener::~RawSocketListener()
    {

    }

    int    RawSocketListener::ReadFromSocket()
    {
	char	buffer[65000];

	bzero(&buffer, sizeof(buffer));
	struct sockaddr saddr;
	int saddr_len = sizeof (saddr);

	while (1)
    	{
	    int i = recvfrom(fd,buffer,65536,0,&saddr,(socklen_t *)&saddr_len);
//	    write(1, buffer, i);
	}
    }
}
