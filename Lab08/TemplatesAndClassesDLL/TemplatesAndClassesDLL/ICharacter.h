//The character interface

#pragma once

#ifdef TEMPLATESANDCLASSESDLL_EXPORTS
#define TEMPLATESANDCLASSESDLL_API __declspec(dllexport)
#else
#define TEMPLATESANDCLASSESDLL_API __declspec(dllimport)
#endif

#include <iostream>
#include "IRace.h"
#include "IClass.h"

class TEMPLATESANDCLASSESDLL_API ICharacter : public IRace, public IClass
{
public:

	/**
	* The function to get the Character's Race.
	*
	* @param
	* @return			the character's race
	*/
	IRace GetRace();
	
	/**
	* The setter for Character's Race
'	*
	* @param	myRace		the race you want to set
	* @return
	*/
	void SetRace(IRace myRace);

	/**
	* The getter for Character's Class
'	*
	* @param	myClass		the race you want to set
	* @return
	*/
	IClass GetClass();

	/**
	* The setter for Character's class
'	*
	* @param	myClass		the class you want to set
	* @return
	*/
	void SetClass(IClass myClass);
	
	/**
	* The character's constructor
	*
	* @param
	* @return
	*/
	ICharacter(IRace newRace, IClass newClass) {
		myRace = newRace;
		myClass = newClass;
	}

	/**
	* The character's destructor
	*
	* @param
	* @return
	*/
	~ICharacter() {}
protected:
	IRace myRace;
	IClass myClass;
};

