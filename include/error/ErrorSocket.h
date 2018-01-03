#pragma once

namespace RACerror
{
    class ErrorSocket
    {
	public :

	    ErrorSocket();
	    ~ErrorSocket() = default;

	    const char		*GetErrorFromErno() const;

	    void		SetErrorState(bool bErrorFlag);
	    void		LogErrorFromErno() const;
	    void		LogOwnError(const char* pErrMsg) const;
	    bool		IsError() const;

	    private :

	    bool          bErr;
    };
}
