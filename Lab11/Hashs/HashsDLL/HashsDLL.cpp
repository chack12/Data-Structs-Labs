// HashsDLL.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "HashsDLL.h"
#include <vector>

//Hashtable functions
bool HashTable::addItem(int val, int key) {
	//Create temp node with value of key and value
	Node* temp = new Node(key, val);
	//Set the hash index
	int index = hash(key);

	//While loop to iterate through hash table
	while (true) {
		//If the index goes out of bounds, item is not in hash table
		if (index >= hashTable.size()) {
			//Returns false since item is not in table
			return false;
		}
		//If the hast table index equals nullptr
		else if (hashTable[index] == nullptr) {
			//Sets the hash table index equal to the temp node
			hashTable[index] = temp;
			//Returns true that it inserted a node
			return true;
		}
		else {
			//Increments index
			index++;
		}
	}
}

Node* HashTable::removeItem(int key) {
	//Set hash index based on key
	int index = hash(key);

	//While loop to iterate through hash table
	while (true) {
		//If index goes out of the hashtable
		if (index >= hashTable.size()) {
			//Item not in table, returns nullptr
			return nullptr;
		}
		//Check to see if the node is empty or not
		else if (hashTable[index] == nullptr) {
			index++;
		}
		// if hash table index is equal to key
		else if (hashTable[index]->getKey() == key) {
			//Get a copy of the node that is being removed
			Node* temp = hashTable[index];
			//Set hash table index equal to nullptr
			hashTable[index] = nullptr;

			//Return the removed node
			return temp;
		}
		else {
			//Increase the idex
			index++;
		}
	}
	
}

Node* HashTable::getNode(int key) {
	//Get the index by using the hash function
	int index = hash(key);

	while (true) {
		//If the index has gone over the size of the hash table
		if (index >= hashTable.size()) {
			//Return a nullptr
			return nullptr;
		}
		//Check to see if the node is empty or not
		else if (hashTable[index] == nullptr) {
			index++;
		}
		//If the given key and the key at that index are the same
		else if (hashTable[index]->getKey() == key) {
			//Return the node
			return hashTable[index];
		}
		else {
			//Increase the index
			index++;
		}
	}
}

int HashTable::getLength() {
	//Initialize the count to 0
	int count = 0;

	//Iterate through the whole hashTable
	for (int i = 0; i < hashTable.size(); ++i) {
		//If the spot in the hash table is not empty
		if (hashTable[i] != nullptr) {
			//Increase the count
			count++;
		}
	}

	return count;
}

int HashTable::hash(int key) {
	//Calculates the hash
	return hashTable.size() % key;
}

//Node functions
int Node::getData() {
	//Returns the data of the node
	return data;
}
void Node::setData(int val) {
	//Sets the data of the node
	data = val;
}

int Node::getKey() {
	//Returns the key of the node
	return key;
}

void Node::setKey(int val) {
	//Sets the key of the node
	key = val;
}
