#include "IHackerAttack.h"
#include "JsonConfHandler.h"
#include "HackerUtils.h"

namespace RAChacker
{
    IHackerAttack::IHackerAttack()
    {
    	IPDest = RACconf::JsonConfHandler::GetValueFromConfigFile<std::string>("hackerDuXul.ip_Dest");	
	interface =  RACconf::JsonConfHandler::GetValueFromConfigFile<std::string>("hackerDuXul.interface", "eth0");

	// To know if we can access to this ip
	std::string ping;	
	ping = "ping -c1 " + IPDest;
	system(ping.c_str()); // maybe its more secure to add a script file which will do this

	HackerUtils::computeMacFromLocalIP(IPDest, uMacDest);
	HackerUtils::computeOwnMac(uMacSrc, interface);
	IPSrc = HackerUtils::getLocalIP(interface);

	ethernetLayer.setDestMAC(uMacDest);
	ethernetLayer.setSrcMAC(uMacSrc);
    }
}
