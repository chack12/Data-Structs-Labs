#pragma once
#include <vector>

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
	void addChar(const ItemType& newCharacter) {

		// For Back row of Party.
		if (backRow.size() < 1) {
			backRow.push_back(newCharacter);
		}
		else {
			std::cout << "Your Party's back row is full." << std::endl;
		}

		// For Front row of Party

		if (frontRow.size() < 1) {
			frontRow.push_back(newCharacter);
		}
		else {
			std::cout << "Your Party's front row is full." << std::endl;
		}
	}
	
private:
	std::vector<ItemType> frontRow;
	std::vector<ItemType> backRow;
};

#include "Party.cpp"