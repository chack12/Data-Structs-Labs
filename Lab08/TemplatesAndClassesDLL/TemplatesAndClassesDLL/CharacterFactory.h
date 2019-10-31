#pragma once

#ifdef TEMPLATESANDCLASSESDLL_EXPORTS
#define TEMPLATESANDCLASSESDLL_API __declspec(dllexport)
#else
#define TEMPLATESANDCLASSESDLL_API __declspec(dllimport)
#endif

#include "IRace.h"
#include "IClass.h"
#include "ICharacter.h"

class TEMPLATESANDCLASSESDLL_API CharacterFactory {
	public:
		CharacterFactory() {}

		enum enumOfCharacterType { enumWizard, enumRogue, enumFighter, enumCleric};
		
		IClass* CreateCharacter(enumOfCharacterType, IRace* race);
};