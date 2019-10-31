//The race interface

#pragma once

#ifdef TEMPLATESANDCLASSESDLL_EXPORTS
#define TEMPLATESANDCLASSESDLL_API __declspec(dllexport)
#else
#define TEMPLATESANDCLASSESDLL_API __declspec(dllimport)
#endif

class TEMPLATESANDCLASSESDLL_API IRace
{
public:
	/**
	* Change the number of hit points
	*
	* @param
	* @return
	*/
	int GetHitPointMod();

	/**
	* Changes the armor class
	*
	* @param
	* @return
	*/
	int GetArmorClassMod();

	/**
	* Changes the hit bonus
	*
	* @param
	* @return
	*/
	int GetHitBonusMod();

	/**
	* Changes the initiative bonus
	*
	* @param
	* @return
	*/
	int GetInitiativeBonus();

	/**
	* The race's constructor
	*
	* @param
	* @return
	*/
	IRace(int newHitPointMod, int newArmorClassMod, int newHitBonusMod, int newInitiativeBonus) : hitPointMod(newHitPointMod), armorClassMod(newArmorClassMod),
		hitBonusMod(newHitBonusMod), initiativeBonus(newInitiativeBonus)
	{ }
	
	/**
	* The race's default constructor
	*
	* @param
	* @return
	*/
	IRace() : hitPointMod(0), armorClassMod(0), hitBonusMod(0), initiativeBonus(0) {}

	/**
	* The race's destructor
	*
	* @param
	* @return
	*/
	~IRace() {}
protected:
	int hitPointMod;
	int armorClassMod;
	int hitBonusMod;
	int initiativeBonus;
};


