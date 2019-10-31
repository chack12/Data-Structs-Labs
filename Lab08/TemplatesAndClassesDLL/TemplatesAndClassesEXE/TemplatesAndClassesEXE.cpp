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

int main()
{
	Party<ICharacter> party1;

	//Character 1
	ICharacter char1;
	char1.SetClass(Wizard(new Elves()));
	party1.addChar(char1);

	//Character 2
	ICharacter char2;
	char2.SetClass(Cleric(new Halflings()));
	party1.addChar(char2);

	//Character 3
	ICharacter char3;
	char3.SetClass(Fighter(new Elves()));
	party1.addChar(char3);

	//Character 4
	ICharacter char4;
	char4.SetClass(Rogue(new Humans()));
	party1.addChar(char4);

	//Party 2
	Party<ICharacter> party2;

	//Character 5
	ICharacter char5;
	char5.SetClass(Wizard(new Dwarves()));
	party2.addChar(char5);

	//Character 6
	ICharacter char6;
	char6.SetClass(Wizard(new Halflings()));
	party2.addChar(char6);

	//Character 7
	ICharacter char7;
	char7.SetClass(Wizard(new Humans()));
	party2.addChar(char7);

	//Character 8
	ICharacter char8;
	char8.SetClass(Fighter(new Elves()));
	party2.addChar(char8);
}
