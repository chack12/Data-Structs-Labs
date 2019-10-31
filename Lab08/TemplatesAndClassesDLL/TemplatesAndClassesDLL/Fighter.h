#pragma once

#ifdef TEMPLATESANDCLASSESDLL_EXPORTS
#define TEMPLATESANDCLASSESDLL_API __declspec(dllexport)
#else
#define TEMPLATESANDCLASSESDLL_API __declspec(dllimport)
#endif

#include "IClass.h"

class TEMPLATESANDCLASSESDLL_API Fighter : public IClass
{
public:
	/**
	* The constructor for the fighter
	*
	* @param
	* @return
	*/
	Fighter(IRace* myRace) : IClass(myRace) {
		canAttackBackRow = false;
		hitPoints = 10;
		armorClass = 3;
		hitBonus = 3;
		initiativeBonus = 1;
	}

	/**
	* The destructor for the fighter
	*
	* @param
	* @return
	*/
	virtual ~Fighter() {}
private:
	Fighter();
};

