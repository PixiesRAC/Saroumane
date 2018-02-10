#include "IHackerAttack.h"
#include "JsonConfHandler.h"
#include "HackerUtils.h"
#include "LogHandler.h"

namespace RAChacker
{
    IHackerAttack::IHackerAttack()
    {
    	IPDest = RACconf::JsonConfHandler::GetValueFromConfigFile<std::string>("hackerDuXul.ip_Dest");	
	interface =  RACconf::JsonConfHandler::GetValueFromConfigFile<std::string>("hackerDuXul.interface", "eth0");

	bzero(uMacDest, sizeof(uMacDest));
	bzero(uMacSrc, sizeof(uMacSrc));
	makingAttack();
 }

 void	IHackerAttack::makingAttack()
 {
     std::string ping;	
     ping = "ping -c1 " + IPDest;
     if (system(ping.c_str()) != 0)
     {
	LOG(ERROR, "Can't ping " << IPDest);
     }

     HackerUtils::computeMacFromLocalIP(IPDest, uMacDest);
     HackerUtils::computeOwnMac(uMacSrc, interface);
     IPSrc = HackerUtils::getLocalIP(interface);
     ethernetLayer.setDestMAC(uMacDest);
     ethernetLayer.setSrcMAC(uMacSrc);
 }
}
