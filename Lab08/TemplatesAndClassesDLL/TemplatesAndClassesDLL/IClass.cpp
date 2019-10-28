#include "IClass.h"
#include "framework.h"

int IClass::GetHitPoints() {
	return race->GetHitPointMod() + hitPoints;
}

int IClass::GetArmorClass() {
	return race->GetArmorClassMod() + armorClass;
}

int IClass::GetHitBonus() {
	return race->GetHitBonusMod() + hitBonus;
}

int IClass::GetInitiativeBonus() {
	return race->GetInitiativeBonus() + initiativeBonus;
}