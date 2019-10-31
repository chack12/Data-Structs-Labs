#include "CharacterFactory.h"
#include "IRace.h"
#include "IClass.h"
#include "Wizard.h"
#include "Cleric.h"
#include "Rogue.h"
#include "Fighter.h"

IClass * CharacterFactory::CreateCharacter(enumOfCharacterType CharacterType, IRace * race)
{
	IRace* retVal = nullptr;
	if (CharacterType == Wizard) {
		retVal = new Wizard(race);
	}
	else if (CharacterType == Rogue) {
		retVal = new Rogue(race);
	}
	else if (CharacterType == Fighter) {
		retVal = new Fighter(race);
	}
	else if (CharacterType == Cleric) {
		retVal = new Cleric(race);
	}

	return retVal;
}