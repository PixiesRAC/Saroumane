#pragma once

#include "IRawSocket.h"

namespace RACsocket
{
    class RawSocketTCP : public IRawSocket
    {
	public:

	    RawSocketTCP();
	    ~RawSocketTCP();

	private :

	    virtual int CreateSocket();
	    virtual int CloseSocket();

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

	    RawSocketTCPError   oRawSocketTCPError;
    };
}
