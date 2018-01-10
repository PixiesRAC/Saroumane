#include "HackerDuXul.h"
#include "AttacksHeader.h"
#include "LogHandler.h"
#include "JsonConfHandler.h"
#include "AttacksDefinition.h"

namespace RAChacker
{
    HackerDuXul::HackerDuXul() : pAttack(nullptr)
    {
	int iAttack = RACconf::JsonConfHandler::GetValueFromConfigFile<int>("hackerDuXul.attack_type");

	switch (iAttack)
	{
	    case	attack::ARPSPOOF:
		LOG(INFO, "ARPSOOF ATTACK");
		pAttack = new HackerARP(); 
		break;
	    default:
		LOG(ERROR, "Unknonw attack,  please be sure if the field attack_type is correctly filled in the configuration file, cf attack_type.txt");
	}
    }

    HackerDuXul::~HackerDuXul()
    {
	if (pAttack != nullptr)
	{
	    delete pAttack;
	}
    }

  void  HackerDuXul::iWantToFuckSomeMother()
  {
      pAttack->launchAttack();
  }
}
