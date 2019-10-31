#include "CharacterFactory.h"
#include "IRace.h"
#include "IClass.h"
#include "Wizard.h"
#include "Cleric.h"
#include "Rogue.h"
#include "Fighter.h"

IClass * CharacterFactory::CreateCharacter(enumOfCharacterType CharacterType, IRace * race)
{
	IClass* retVal = nullptr;
	if (CharacterType == enumWizard) {
		retVal = new Wizard(race);
	}
	else if (CharacterType == enumRogue) {
		retVal = new Rogue(race);
	}
	else if (CharacterType == enumFighter) {
		retVal = new Fighter(race);
	}
	else if (CharacterType == enumCleric) {
		retVal = new Cleric(race);
	}

	return retVal;
}