#include "ICharacter.h"
#include "framework.h"

IRace ICharacter::GetRace() {
	return myRace;
}

void ICharacter::SetRace(IRace newRace) {
	myRace = newRace;
}

IClass ICharacter::GetClass() {
	return myClass;
}

void ICharacter::SetClass(IClass newClass) {
	myClass = newClass;
}