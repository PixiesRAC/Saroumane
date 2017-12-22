
#include <errno.h>
#include <string.h>
#include "ErrorSocket.h"
#include "LogHandler.h"

namespace RACerror
{
    const char  *ErrorSocket::GetErrorFromErno() const
    {
	return  strerror(errno);
    }

    void        ErrorSocket::SetErrorState(bool bErrorFlag)
    {
	bErr = bErrorFlag;
    }

    void        ErrorSocket::LogErrorFromErno() const
    {
	LOG(ERROR, GetErrorFromErno());
    }

    void        ErrorSocket::SetOwnErrorLog(const char* pErrMsg) const
    {
	LOG(ERROR, pErrMsg);
    }
}
