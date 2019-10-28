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
	void HitPointModification();

	/**
	* Changes the armor class
	*
	* @param
	* @return
	*/
	void ArmorClassModification();

	/**
	* Changes the hit bonus
	*
	* @param
	* @return
	*/
	void HitBonusModification();

	/**
	* Changes the initiative bonus
	*
	* @param
	* @return
	*/
	void InitiativeBonusModification();

	/**
	* The race's constructor
	*
	* @param
	* @return
	*/
	IRace() {}

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


