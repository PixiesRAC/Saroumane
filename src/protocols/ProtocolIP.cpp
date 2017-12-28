#include "ProtocolIP.h"


namespace RACprotocol
{
    BYTE        ProtocolIP::getVers_ihl() const
    {
	return	proto.bvers_ihl;
    }

    BYTE        ProtocolIP::getService() const
    {
	return proto.bservice;
    }
    short       ProtocolIP::getLenght() const
    {
	return proto.slenght;
    }
    short       ProtocolIP::getIdentification() const
    {
	return proto.sidentification;
    }
    short       ProtocolIP::getFlags_positionFragment() const
    {
    }
    BYTE        ProtocolIP::getTTL() const
    {
    }
    BYTE        ProtocolIP::getProtocol() const
    {
    }
    short       ProtocolIP::getChecksum() const
    {
    }
    int         ProtocolIP::getSrcIP() const
    {
    }
    const char  *ProtocolIP::getOption() const
    {
    }
    BYTE        ProtocolIP::getJam() const
    {
    }

}
