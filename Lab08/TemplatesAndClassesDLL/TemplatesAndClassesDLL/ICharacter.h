#pragma once
#include <iostream>

class ICharacter
{
public:
	int GetHitPoints();
	std::string GetArmorClass();
	int GetHitBonus();
	ICharacter();
	~ICharacter();
private:
	int hitPoints;
	std::string armorClass;
	int hitBonus;

};

