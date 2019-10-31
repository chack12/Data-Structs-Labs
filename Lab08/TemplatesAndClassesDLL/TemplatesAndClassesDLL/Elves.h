#pragma once

#ifdef TEMPLATESANDCLASSESDLL_EXPORTS
#define TEMPLATESANDCLASSESDLL_API __declspec(dllexport)
#else
#define TEMPLATESANDCLASSESDLL_API __declspec(dllimport)
#endif

#include "IRace.h"
#include "IClass.h"
#include <iostream>

class Elves	: public IRace
{
public: 
	Elves() : IRace(/*numbers*/) {

	}

	virtual ~Elves();

protected:
	Elves();
};
