#pragma once

#ifdef TEMPLATESANDCLASSESDLL_EXPORTS
#define TEMPLATESANDCLASSESDLL_API __declspec(dllexport)
#else
#define TEMPLATESANDCLASSESDLL_API __declspec(dllimport)
#endif

#include "IClass.h"

class TEMPLATESANDCLASSESDLL_API Cleric : public IClass
{
public:
	/**
	* The constructor for the cleric
	*
	* @param
	* @return
	*/
	Cleric(IRace* myRace) : IClass(myRace) {
		canAttackBackRow = false;
		hitPoints = 8;
		armorClass = 1;
		hitBonus = 4;
		initiativeBonus = 2;
	}

	/**
	* The destructor for the cleric
	*
	* @param
	* @return
	*/
	virtual ~Cleric();
private:
	Cleric();
};

