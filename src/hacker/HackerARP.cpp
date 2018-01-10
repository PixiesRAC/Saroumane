#include "IHackerAttack.h"
#include "HackerARP.h"

#include <iostream>

namespace RAChacker
{
    HackerARP::HackerARP()
    {
	makingAttack();
    }

    void    HackerARP::launchAttack()
    {
	std::cout << "HACKERARP LAUNCH ATTACK" << std::endl;
	std::cout << ethernetLayer.getProtocolFormated() << std::endl;
    }

    void    HackerARP::makingAttack()
    {
	// ETHERNET LAYER 2

	uint8_t	DestMac[6] = { 00, 80, 86, 252, 106, 108 };
	    
	ethernetLayer.setDestMAC(DestMac);
//	ethernetLayer.setSrcMAC("345056766572");
//	ethernetLayer.setEtherType("01");

	// ARP LAYER 3
    }
}
