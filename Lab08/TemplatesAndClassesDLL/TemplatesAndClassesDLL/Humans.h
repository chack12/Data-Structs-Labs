#pragma once

#ifdef TEMPLATESANDCLASSESDLL_EXPORTS
#define TEMPLATESANDCLASSESDLL_API __declspec(dllexport)
#else
#define TEMPLATESANDCLASSESDLL_API __declspec(dllimport)
#endif

#include "IRace.h"
#include "IClass.h"
#include <iostream>

class TEMPLATESANDCLASSESDLL_API Humans : public IRace
{
public:
	/**
	* The constructor for Humans
	*
	* @param
	* @return
	*/
	Humans() : IRace(0, -1, 0, 1) {

	}

	/**
	* The destructor for Humans
	*
	* @param
	* @return
	*/
	virtual ~Humans();
};