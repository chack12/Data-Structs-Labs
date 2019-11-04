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
#include <vector>

class PRIORITYQUEUESANDHEAPSDLL_API PriorityQueuesWithQueue {
public:
	PriorityQueuesWithQueue(void) {}
	bool Remove(int value);
	bool Insert(int value);
	std::string PrintQueue();
private:
	std::vector<int> queue;
};

class PRIORITYQUEUESANDHEAPSDLL_API PriorityQueuesWithHeap {
public:
	PriorityQueuesWithHeap(void) {}
	bool Remove(int value);
	bool Insert(int value);
	std::string PrintHeap();
private:
	std::vector<int> tree;
};