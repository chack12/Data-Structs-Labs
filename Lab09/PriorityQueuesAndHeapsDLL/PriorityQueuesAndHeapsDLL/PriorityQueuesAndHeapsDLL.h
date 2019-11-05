// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the PRIORITYQUEUESANDHEAPSDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// PRIORITYQUEUESANDHEAPSDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef PRIORITYQUEUESANDHEAPSDLL_EXPORTS
#define PRIORITYQUEUESANDHEAPSDLL_API __declspec(dllexport)
#else
#define PRIORITYQUEUESANDHEAPSDLL_API __declspec(dllimport)
#endif

#include <iostream>

class PRIORITYQUEUESANDHEAPSDLL_API PriorityQueuesWithQueue {
public:
	/**
	* The constructor for the priority queue with queue
	*
	* @param
	* @return
	*/
	PriorityQueuesWithQueue();
	
	/**
	* Removes a value in the array
	*
	* @param	value		value wanting to be removed
	* @return				conditional
	*/
	bool Remove(int value);
	
	/**
	* Inserts a value into the array
	*
	* @param	value		value wanting to be inserted
	* @return				conditional
	*/
	bool Insert(int value);
	
	/**
	* Prints out the queue
	*
	* @param
	* @return				output of queue
	*/
	std::string PrintQueue();
private:
	int queue[50];
};

class PRIORITYQUEUESANDHEAPSDLL_API PriorityQueuesWithHeap {
public:
	/**
	* The constructor for the priority queue with queue
	*
	* @param
	* @return
	*/
	PriorityQueuesWithHeap();

	/**
	* Removes a value in the array
	*
	* @param	value		value wanting to be removed
	* @return				conditional
	*/
	bool Remove(int value);

	/**
	* Inserts a value into the array
	*
	* @param	value		value wanting to be inserted
	* @return				conditional
	*/
	bool Insert(int value);

	/**
	* Prints out the queue
	*
	* @param
	* @return				output of queue
	*/
	std::string PrintHeap();
private:
	int queue[50];
};