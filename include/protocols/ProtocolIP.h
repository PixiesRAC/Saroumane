#pragma once

#include <iostream>
#include <string.h>
#include <sstream>
#include "IProtocol.h"
#include "ProtocolsDefinition.h"

namespace RACprotocol
{
  class	ProtocolIP : public IProtocol
    {
	public :
	    
	    ProtocolIP() = default;
	    virtual ~ProtocolIP() override final = default;

	private :
#pragma pack (push, 1)

	struct protocol
	{
	    BYTE    bvers_ihl;
	    BYTE    bservice;
	    short   slenght;
	    short   sidentification;
	    short   sflags_position_fragment;
	    BYTE    bttl;
	    BYTE    bprotocol;
	    short   schecksum;
	    int	    isrcIP;
	    int	    idestIP;
	    char    coption[24];
	    BYTE    bjam;
	};

#pragma pack (pop)

	public :

	const ProtocolIP* GetStruct() const
	{
	}

/*	virtual void  display() const override final
	{
	    std::stringstream os;

	    os << "Vers_ihl : " << static_cast<int>(getVers_ihl()) <<
		  "Service : " <<  static_cast<int>(getService()) <<
		  "Lenght : " << getLenght() <<
		  "Identification : " << getIdentification();

	 std::cout << os.str() << std::endl;   
	} */

	void	    set(const char* data)
	{
	    memcpy(&proto, data, 20);
	}

	BYTE	    getVers_ihl() const;
	BYTE	    getService() const;
	short	    getLenght() const;
	short	    getIdentification() const;
	short	    getFlags_positionFragment() const;
	BYTE	    getTTL() const;
	BYTE	    getProtocol() const;
	short	    getChecksum() const;
	int	    getSrcIP() const;
	const char  *getOption() const;
	BYTE	    getJam() const;

	struct	protocol    proto;
  };
}
