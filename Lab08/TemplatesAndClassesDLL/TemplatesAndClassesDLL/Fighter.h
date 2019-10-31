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
	* The constructor for the node
	*
	* @param
	* @return
	*/
	Fighter(IRace* myRace) : IClass(myRace) {
		//Fillin nubers here
		canAttackBackRow;
		hitPoints;
		armorClass;
		hitBonus;
		initiativeBonus;
	}

	/**
	* The destructor for the node
	*
	* @param
	* @return
	*/
	virtual ~Fighter();
private:
	Fighter();
};

