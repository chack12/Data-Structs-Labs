#pragma once

#ifdef TEMPLATESANDCLASSESDLL_EXPORTS
#define TEMPLATESANDCLASSESDLL_API __declspec(dllexport)
#else
#define TEMPLATESANDCLASSESDLL_API __declspec(dllimport)
#endif

#include <iostream>
#include "IRace.h"

class TEMPLATESANDCLASSESDLL_API IClass {
public:
	/**
	* Returns the number of hit points
	*
	* @param
	* @return                  the number of hit points
	*/
	virtual int GetHitPoints();

	/**
	* Returns the armor class
	*
	* @param
	* @return                  the armor class
	*/
	virtual int GetArmorClass();

	/**
	* Returns the hit bonus
	*
	* @param
	* @return                  the hit bonus
	*/
	virtual int GetHitBonus();

	/**
	* Returns initiative bonus
	*
	* @param
	* @return                  the initiative bonus
	*/
	virtual int GetInitiativeBonus();

	/**
	* The constructor for the IClass
	*
	* @param
	* @return
	*/
	IClass(IRace* newRace) : race(newRace), canAttackBackRow(false), hitPoints(10), armorClass(1), hitBonus(1), initiativeBonus(1)
	{ }

	/**
	* The default constructor for the IClass
	*
	* @param
	* @return
	*/
	IClass() : race(nullptr), canAttackBackRow(false), hitPoints(10), armorClass(1), hitBonus(1), initiativeBonus(1)
	{ }

	/**
	* The destructor for the IClass
	*
	* @param
	* @return
	*/
	virtual ~IClass() {}
protected:
	bool canAttackBackRow;
	int hitPoints;
	int armorClass;
	int hitBonus;
	int initiativeBonus;
	IRace* race;
};
