#pragma once

#include "ISocket.h"
#include "JsonConfHandler.h"

namespace RACsocket
{
    class RawSocketTCP : public ISocket
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


	    class  Error
	    {
		public :

			Error() : bErr(false)
		{
		}

		private :

		    const char    *GetErrorFromErno();

		public :

		    bool        IsErrorFromRawSocketTCP();
		    void	setErrorStateAndLogErrorMsg(bool bFlag);

		private :

		    bool	  bErr;

	    };

	private :

	    Error	    		oRawSocketTCPError;
	    int				iPort;
    };
}
