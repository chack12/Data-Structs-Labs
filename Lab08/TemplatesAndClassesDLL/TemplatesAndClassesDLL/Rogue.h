#pragma once

#ifdef TEMPLATESANDCLASSESDLL_EXPORTS
#define TEMPLATESANDCLASSESDLL_API __declspec(dllexport)
#else
#define TEMPLATESANDCLASSESDLL_API __declspec(dllimport)
#endif

#include "IClass.h"

class TEMPLATESANDCLASSESDLL_API Rogue : public IClass
{
public:
	/**
	* The constructor for the rogue
	*
	* @param
	* @return
	*/
	Rogue(IRace* myRace) : IClass(myRace) {
		canAttackBackRow = true;
		hitPoints = 8;
		armorClass = 1;
		hitBonus = 3;
		initiativeBonus = 3;
	}

	/**
	* The destructor for the rogue
	*
	* @param
	* @return
	*/
	virtual ~Rogue();
private:
	Rogue();
};

