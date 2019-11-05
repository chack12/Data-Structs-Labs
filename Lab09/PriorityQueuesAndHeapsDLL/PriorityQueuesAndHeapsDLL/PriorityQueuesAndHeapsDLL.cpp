// PriorityQueuesAndHeapsDLL.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "PriorityQueuesAndHeapsDLL.h"

PriorityQueuesWithQueue::PriorityQueuesWithQueue()
{
}

bool PriorityQueuesWithQueue::Remove(int value)
{
	// Removes the first location that the value is found
	for (int i = 0; i < 50; i++) {
		if (queue[i] == value) {
			for (int j = i + 1; j < 49; j++) {
				queue[i] = queue[j];
				i++;
			}
			queue[50] = -1;
			// If done correctly, returns true
			return true;
		}
	}
	// If value is not found, returns false
	return false;
}

bool PriorityQueuesWithQueue::Insert(int value)
{
	// ******** NOT FINSHED/NOT RIGHT ******** 
	/*int k = 1;
	// If value is smaller than first iterator
	if (value <= queue[0]) {
		for (int i = 0; i < 49; i++) {
			int cur = queue[i];
			int next = queue[i+1];
			queue[i + 1] = queue[i];
		}
		
		return true;
	}
	for (int j = 0; j < 49; j++) {
		// If value is smaller than second iterator
		if (value <= queue[k]) {

			k++;
		}
		else if (k == 50 && value > queue[k]) {
			k++;
		}
		else {
			k++;
		}
	}
	*/
	return false;
}

std::string PriorityQueuesWithQueue::PrintQueue()
{
	std::string output;
	return output;
}


PriorityQueuesWithHeap::PriorityQueuesWithHeap()
{
}

bool PriorityQueuesWithHeap::Remove(int value)
{
	return false;
}

bool PriorityQueuesWithHeap::Insert(int value)
{
	return false;
}

std::string PriorityQueuesWithHeap::PrintHeap()
{
	return false;
}
