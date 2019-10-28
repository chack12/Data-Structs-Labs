//The race interface

#pragma once

class IRace
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
	void InitiativeBonus();

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
private:

};


