#pragma once

#ifdef TEMPLATESANDCLASSESDLL_EXPORTS
#define TEMPLATESANDCLASSESDLL_API __declspec(dllexport)
#else
#define TEMPLATESANDCLASSESDLL_API __declspec(dllimport)
#endif

#include "IRace.h"
#include "IClass.h"
#include <iostream>

class TEMPLATESANDCLASSESDLL_API Elves	: public IRace
{
public:
	/**
	* The constructor for Elves
	*
	* @param
	* @return
	*/
	Elves() : IRace(1, 0, 1, -1) {

	}

	/**
	* The destructor for Elves
	*
	* @param
	* @return
	*/
	virtual ~Elves();
};
