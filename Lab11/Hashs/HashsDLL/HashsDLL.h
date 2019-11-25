// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the HASHSDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// HASHSDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef HASHSDLL_EXPORTS
#define HASHSDLL_API __declspec(dllexport)
#else
#define HASHSDLL_API __declspec(dllimport)
#endif

#include <vector>

// This class is exported from the dll
class HASHSDLL_API HashTable {
public:
	/**
	* The default constructor
	*
	* @param
	* @return
	*/
	HashTable() {
		hashList.resize(100);

		for (int i = 0; i < 100; ++i) {
			hashList.at(i) = -1;
		}
	}

	/**
	* The default constructor
	*
	* @param
	* @return
	*/
	HashTable(int size) {
		hashList.resize(size);

		for (int i = 0; i < size; ++i) {
			hashList.at(i) = -1;
		}
	}

	/**
	* Add item
	*
	* @param
	* @return
	*/
	void addItem(int val);

	/**
	* Removes item based on value sent
	*
	* @param
	* @return
	*/
	Hash* removeItem(int val);

	/**
	* Get item based on value sent
	*
	* @param
	* @return
	*/
	Hash* getItem(int val);

	/**
	* Get length of list/vector
	*
	* @param
	* @return			
	*/
	int getLength();

	/**
	* The default constructor
	*
	* @param
	* @return
	*/
	~HashTable();


private:
	std::vector<Hash*> hashList;
	/**
	* accepts an int and returns an int
	*
	* @param		hashVal
	* @return		val
	*/
	int hash(int hashVal);
};

class HASHSDLL_API Hash {
public:
	/**
	* Checks to see if the datas are the same
	* == overloader
	* @param		hashVal
	* @return		val
	*/
	Hash operator == (Hash h) 
	{ 
		return (h.data == data && h.key == key);
	} 
private:
	int key;
	int data;
}