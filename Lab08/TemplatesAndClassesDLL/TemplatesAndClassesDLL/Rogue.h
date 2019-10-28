#pragma once

#ifdef TEMPLATESANDCLASSESDLL_EXPORTS
#define TEMPLATESANDCLASSESDLL_API __declspec(dllexport)
#else
#define TEMPLATESANDCLASSESDLL_API __declspec(dllimport)
#endif

class TEMPLATESANDCLASSESDLL_API Rogue
{
public:
	/**
	* The constructor for the node
	*
	* @param
	* @return
	*/
	Rogue();

	/**
	* The destructor for the node
	*
	* @param
	* @return
	*/
	~Rogue();
private:
};

