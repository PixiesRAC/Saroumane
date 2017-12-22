#pragma once

namespace RACerror
{
    class ErrorSocket
    {
	protected :

	    ErrorSocket() = default;
	    ~ErrorSocket() = default;

	    const char		*GetErrorFromErno() const;

	    void		SetErrorState(bool bErrorFlag);
	    void		LogErrorFromErno() const;
	    void		SetOwnErrorLog(const char* pErrMsg) const;

	    bool          bErr;
    };
}
