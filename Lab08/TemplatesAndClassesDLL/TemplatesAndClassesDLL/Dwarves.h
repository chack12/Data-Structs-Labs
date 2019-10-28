#pragma once

#ifdef TEMPLATESANDCLASSESDLL_EXPORTS
#define TEMPLATESANDCLASSESDLL_API __declspec(dllexport)
#else
#define TEMPLATESANDCLASSESDLL_API __declspec(dllimport)
#endif

#include "IRace.h"
#include "IClass.h"
#include <iostream>

class Dwarves : public IRace
{
public:
	Dwarves(IRace* race) : IRace(race) {

	}
	virtual ~Dwarves();

protected:
	Dwarves();
};