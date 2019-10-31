#pragma once

#ifdef TEMPLATESANDCLASSESDLL_EXPORTS
#define TEMPLATESANDCLASSESDLL_API __declspec(dllexport)
#else
#define TEMPLATESANDCLASSESDLL_API __declspec(dllimport)
#endif

#include "IClass.h"

class TEMPLATESANDCLASSESDLL_API Wizard : public IClass
{
public:
	/**
	* The constructor for the wizard
	*
	* @param
	* @return
	*/
	Wizard(IRace* myRace) : IClass(myRace) {
		canAttackBackRow = true;
		hitPoints = 6;
		armorClass = 2;
		hitBonus = 4;
		initiativeBonus = 2;
	}

	/**
	* The destructor for the wizard
	*
	* @param
	* @return
	*/
	virtual ~Wizard() {}
private:
	Wizard();
};

