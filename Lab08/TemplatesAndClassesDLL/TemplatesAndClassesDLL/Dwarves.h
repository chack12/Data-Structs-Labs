#pragma once

#ifdef TEMPLATESANDCLASSESDLL_EXPORTS
#define TEMPLATESANDCLASSESDLL_API __declspec(dllexport)
#else
#define TEMPLATESANDCLASSESDLL_API __declspec(dllimport)
#endif

#include "IRace.h"
#include "IClass.h"
#include <iostream>

class TEMPLATESANDCLASSESDLL_API Dwarves : public IRace
{
public:
	/**
	* The constructor for Dwarves
	*
	* @param
	* @return
	*/
	Dwarves() : IRace(2, -1, -1, 0) {

	}

	/**
	* The constructor for Dwarves
	*
	* @param
	* @return
	*/
	virtual ~Dwarves();

private:
	Dwarves();
};