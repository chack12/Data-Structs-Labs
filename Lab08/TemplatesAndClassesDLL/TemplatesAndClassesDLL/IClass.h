#pragma once

#ifdef TEMPLATESANDCLASSESDLL_EXPORTS
#define TEMPLATESANDCLASSESDLL_API __declspec(dllexport)
#else
#define TEMPLATESANDCLASSESDLL_API __declspec(dllimport)
#endif

#include <iostream>

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
	std::string GetArmorClass();

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
	* Class enumerator
	*
	* @param
	* @return
	*/
	enum classEnum {
		Wizard,
		Rogue,
		Fighter,
		Cleric
	};

	/**
	* The constructor for the node
	*
	* @param
	* @return
	*/
	IClass();

	/**
	* The destructor for the node
	*
	* @param
	* @return
	*/
	~IClass();
protected:
	classEnum myClass;
	bool canAttackBackRow;
	int hitPoints;
	std::string armorClass;
	int hitBonus;
	int initiativeBonus;
};
