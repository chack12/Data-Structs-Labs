#pragma once


#ifdef TEMPLATESANDCLASSESDLL_EXPORTS
#define TEMPLATESANDCLASSESDLL_API __declspec(dllexport)
#else
#define TEMPLATESANDCLASSESDLL_API __declspec(dllimport)
#endif

#include "IRace.h"
#include "IClass.h"
#include <iostream>

class TEMPLATESANDCLASSESDLL_API Halflings : public IRace
{
public:
	/**
	* The constructor for Halflings
	*
	* @param
	* @return
	*/
	Halflings() : IRace(1, 1, 0, -1) {

	}

	/**
	* The destructor for Halflings
	*
	* @param
	* @return
	*/
	virtual ~Halflings() {}
};