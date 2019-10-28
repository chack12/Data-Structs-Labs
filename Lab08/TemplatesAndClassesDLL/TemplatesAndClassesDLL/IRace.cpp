#include "IRace.h"
#include "framework.h"

int IRace::GetHitPointMod() {
	return hitBonusMod;
}

int IRace::GetArmorClassMod() {
	return armorClassMod;
}

int IRace::GetHitBonusMod() {
	return hitBonusMod;
}

int IRace::GetInitiativeBonus() {
	return initiativeBonus;
}