#pragma once
#include <vector>
#include "ICharacter.h"

#ifdef TEMPLATESANDCLASSESDLL_EXPORTS
#define TEMPLATESANDCLASSESDLL_API __declspec(dllexport)
#else
#define TEMPLATESANDCLASSESDLL_API __declspec(dllimport)
#endif

template<class ItemType>
class TEMPLATESANDCLASSESDLL_API Party
{
public:
	/**
	* The party constructor
	*
	* @param
	* @return
	*/
	Party() {}

	/**
	* Adds a character to the party
	*
	* @param	newCharacter	character to add
	* @return
	*/
	void addChar(const ItemType& newCharacter);
	
private:
	std::vector<ItemType> frontRow;
	std::vector<ItemType> backRow;
};

#include "Party.cpp"