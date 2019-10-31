// TemplatesAndClassesEXE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "../TemplatesAndClassesDLL/ICharacter.h"
#include "../TemplatesAndClassesDLL/IClass.h"
#include "../TemplatesAndClassesDLL/IRace.h"
#include "../TemplatesAndClassesDLL/CharacterFactory.h"
#include "../TemplatesAndClassesDLL/Party.h"
#include "../TemplatesAndClassesDLL/Cleric.h"
#include "../TemplatesAndClassesDLL/Fighter.h"
#include "../TemplatesAndClassesDLL/Rogue.h"
#include "../TemplatesAndClassesDLL/Wizard.h"
#include "../TemplatesAndClassesDLL/Dwarves.h"
#include "../TemplatesAndClassesDLL/Elves.h"
#include "../TemplatesAndClassesDLL/Halflings.h"
#include "../TemplatesAndClassesDLL/Humans.h"

template<class ItemType>
int main()
{
	Party<ItemType>* party1;

	//Character 1
	ICharacter* char1;
	char1->SetClass(new Wizard(new Fighter()));
}
