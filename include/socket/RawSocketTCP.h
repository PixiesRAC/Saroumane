#pragma once

#include "IRawSocket.h"
#include "JsonConfHandler.h"

namespace RACsocket
{
    class RawSocketTCP : public IRawSocket
    {
	using jsonConf = RACconf::JsonConfHandler;

	public:

		    RawSocketTCP();
	   virtual ~RawSocketTCP();

	private :

	    virtual int CreateSocket() override final;
	    virtual int CloseSocket() override final;
	    virtual int	BindSocket() override final;

	    void	Config();


	    class  RawSocketTCPError
	    {
		public :

		    RawSocketTCPError() : bErrFromRawSocketTCP(false)
		{
		}

		private :

		    const char    *GetErrorFromErno();

		public :

		    bool        IsErrorFromRawSocketTCP();
		    void	setAndLogErrorFromRawSocketTCP(bool bFlag);

		private :

		    bool	  bErrFromRawSocketTCP;

	    };

	private :

	    RawSocketTCPError		oRawSocketTCPError;
	    int				iPort;
    };
}
