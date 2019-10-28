#pragma once

#ifdef TEMPLATESANDCLASSESDLL_EXPORTS
#define TEMPLATESANDCLASSESDLL_API __declspec(dllexport)
#else
#define TEMPLATESANDCLASSESDLL_API __declspec(dllimport)
#endif

class TEMPLATESANDCLASSESDLL_API Cleric
{
public:
	/**
	* The constructor for the node
	*
	* @param
	* @return
	*/
	Cleric();

	/**
	* The destructor for the node
	*
	* @param
	* @return
	*/
	~Cleric();
private:
};

