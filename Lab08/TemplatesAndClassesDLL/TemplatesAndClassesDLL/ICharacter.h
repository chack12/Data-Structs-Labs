#include <iostream>
class ICharacter
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
	* The character's constructor
	*
	* @param
	* @return
	*/
	ICharacter() {}

	/**
	* The character's destructor
	*
	* @param
	* @return
	*/
	~ICharacter() {}
private:
	int hitPoints;
	std::string armorClass;
	int hitBonus;
	int initiativeBonus;
};

