#pragma once

namespace RAClistener
{
    class	ISocketListener
    {
	public:

	    ISocketListener() = default;
	    virtual ~ISocketListener() = default;

	protected :

	    virtual int	ReadFromSocket() = 0;

	    int	fd;
    };
}
