#pragma once

#include "ISocket.h"
#include "JsonConfHandler.h"
#include "ErrorSocket.h"

namespace RACsocket
{
    class RawSocketTCP : public ISocket
    {
	using jsonConf = RACconf::JsonConfHandler;

	public:

		    RawSocketTCP();
	   virtual ~RawSocketTCP();

	    virtual int	Bind() override final;

	private :

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

	    Error	    		oRawSocketTCPError;
	    int				iPort;
	    std::string			sIp;
	    std::string			sInterface;
    };
}
