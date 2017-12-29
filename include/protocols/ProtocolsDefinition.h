#pragma once

using BYTE = char;

namespace ip_protocol
{
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
}
