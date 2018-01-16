#pragma once

using BYTE = char;

namespace etherType
{
    namespace protocol
    {
	enum value : uint16_t 
	{
	    IPV4 = 0x0800,	    
	    ARP = 0x0806
	};
    }
}

namespace IPv4
{
    namespace protocol
    {
	enum value
	{
	    ICMP = 1,
	    IGMP = 2,
	    TCP = 6,
	    UDP = 17
	};
    }
}

namespace hardwareType
{
    enum value : int
    {
	ETHERNET = 1
    };
}

namespace service
{
    namespace priority
    {
	enum value
	{
	    ROUTINE,
	    PRIORITARY,
	    IMMEDIAT,
	    URGENT,
	    VERY_URGENT,
	    CRITIC,
	    INTER,
	    NETWORK
	};
    }

    namespace delay
    {
	enum value
	{
	    NORMAL,
	    LOW
	};
    }

    namespace throughput
    {
	enum value
	{
	    NORMAL,
	    HIGH
	};
    }

    namespace reliability
    {
	enum value
	{
	    NORMAL,
	    HIGH
	};
    }

    namespace cost
    {
	enum value
	{
	    NORMAL,
	    LOW
	};
    }
}
