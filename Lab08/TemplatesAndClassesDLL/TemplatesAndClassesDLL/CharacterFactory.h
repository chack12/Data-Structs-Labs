#pragma once

#ifdef TEMPLATESANDCLASSESDLL_EXPORTS
#define TEMPLATESANDCLASSESDLL_API __declspec(dllexport)
#else
#define TEMPLATESANDCLASSESDLL_API __declspec(dllimport)
#endif

#include "IRace.h"
#include "IClass.h"
#include "ICharacter.h"

class CharacterFactory {
	public:
		CharacterFactory() {};

		enum enumOfCharcterType { ClassType, RaceType};
		
		ICharacter* CreateCharacter(enumOfCharacterType, IRace* race);
};