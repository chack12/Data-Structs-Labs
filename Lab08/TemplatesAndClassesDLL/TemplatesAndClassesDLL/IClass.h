#pragma once

#ifdef TEMPLATESANDCLASSESDLL_EXPORTS
#define TEMPLATESANDCLASSESDLL_API __declspec(dllexport)
#else
#define TEMPLATESANDCLASSESDLL_API __declspec(dllimport)
#endif

#include <iostream>
#include "IRace.h"

class TEMPLATESANDCLASSESDLL_API IClass
{
public:
	/**
	* Returns the number of hit points
	*
	* @param
	* @return                  the number of hit points
	*/
	int GetHitPoints();

	/**
	* Returns the armor class
	*
	* @param
	* @return                  the armor class
	*/
	int GetArmorClass();

	/**
	* Returns the hit bonus
	*
	* @param
	* @return                  the hit bonus
	*/
	int GetHitBonus();

	/**
	* Returns initiative bonus
	*
	* @param
	* @return                  the initiative bonus
	*/
	int GetInitiativeBonus();

	/**
	* The constructor for the node
	*
	* @param
	* @return
	*/
	IClass(IRace* newRace) {
		race = newRace;
		canAttackBackRow = false;
		hitPoints = 10;
		armorClass = 1;
		hitBonus = 1;
		initiativeBonus = 1;
	}

	/**
	* The destructor for the node
	*
	* @param
	* @return
	*/
	~IClass() { }
protected:
	bool canAttackBackRow;
	int hitPoints;
	int armorClass;
	int hitBonus;
	int initiativeBonus;
	IRace* race;
};
