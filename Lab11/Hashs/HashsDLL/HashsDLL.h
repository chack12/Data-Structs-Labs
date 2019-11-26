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
class HASHSDLL_API Node {
public:
	/**
	* Returns the data for the node
	* 
	* @param		
	* @return			data for the node
	*/
	int getData();

	/**
	* Sets the data for the node
	*
	* @param	val		the new data
	* @return
	*/
	void setData(int val);

	/**
	* Returns the key of the node
	*
	* @param
	* @return			the key of the node
	*/
	int getKey();

	/**
	* Sets the key of the node
	*
	* @param	val		the new key
	* @return
	*/
	void setKey(int val);
	
	/**
	* Checks to see if the datas and keys are the same
	* == overloader
	* @param		hashVal
	* @return		val
	*/
	bool operator == (Node n) {
		return (n.data == data && n.key == key);
	}

	/**
	* Blank constructor
	*
	* @param
	* @return
	*/
	Node();

	/**
	* Constructor
	*
	* @param
	* @return
	*/
	Node(int myKey, int myData) {
		key = myKey;
		data = myData;
	}
private:
	int key;
	int data;
};
// This class is exported from the dll
class HASHSDLL_API HashTable {
public:
	/**
	* Add a node
	*
	* @param	node	the node you want to add
	* @return
	*/
	bool addItem(int val, int key);

	/**
	* Removes node based on value sent
	*
	* @param	key		the key for the node
	* @return			the node
	*/
	Node* removeItem(int key);

	/**
	* Get node based on the key
	*
	* @param	key		the key for the node
	* @return			the node
	*/
	Node* getNode(int key);

	/**
	* Get length of list/vector
	*
	* @param
	* @return			the length
	*/
	int getLength();

	/**
	* The default constructor
	*
	* @param
	* @return
	*/
	HashTable() {
		hashTable.resize(100);

		for (int i = 0; i < 100; ++i) {
			hashTable[i] = nullptr;
		}
	}

	/**
	* Constructor
	*
	* @param
	* @return
	*/
	HashTable(int size) {
		hashTable.resize(size);

		for (int i = 0; i < size; ++i) {
			hashTable[i] = nullptr;
		}
	}

	/**
	* Destructor
	*
	* @param
	* @return
	*/
	~HashTable() {
		for (int i = 0; i < hashTable.size(); ++i) {
			delete hashTable[i];
		}
	}


private:
	std::vector<Node*> hashTable;
	/**
	* Takes the modulus of the maximum size of the table
	*
	* @param	val		the inputted value
	* @return			an int
	*/
	int hash(int val);
};