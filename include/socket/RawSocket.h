#pragma once

#include "ISocket.h"
#include "ErrorSocket.h"

namespace RACsocket
{
    class RawSocket : public ISocket
    {
	public:

	RawSocket();
	virtual ~RawSocket() override final;

	virtual int	Bind() override final;

	private :

	void    PerformPromiscuousMode();

	virtual int CreateSocket() override final;
	virtual int CloseSocket() override final;

	void	Config();

	private :

	class  Error : public RACerror::ErrorSocket
	{
	    public :

		void	SetErrorStateAndLogErrorFromErno(bool bErrorFlag);
		void	SetErrorStateAndLogOwnError(bool bErrorFlag, const char* pErrMsg);
	};

	private :

	Error				oRawSocketError;
	int				iPort;
	std::string			sIp;
	std::string			sInterface;
    };
}
