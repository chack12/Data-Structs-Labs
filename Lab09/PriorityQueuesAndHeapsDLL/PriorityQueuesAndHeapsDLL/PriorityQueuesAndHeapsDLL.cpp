// PriorityQueuesAndHeapsDLL.cpp : Defines the exported functions for the DLL.
//

#include <iostream>
#include <algorithm>
#include <sstream>
#include "framework.h"
#include "PriorityQueuesAndHeapsDLL.h"

//******************************
//* Priory Queue using a Queue *
//******************************
bool PriorityQueuesWithQueue::Remove(int value) {
	// Removes the first location that the value is found
	for (int i = 0; i < size; i++) {
		if (i == size - 1 && queue[i] == value) {
			queue[i] = NULL;
		}
		else if (queue[i] == value) {
			//Move all the values over
			for (int j = i + 1; j < size - 1; j++) {
				queue[i] = queue[j];
				i++;
			}
			queue[size - 1] = NULL;
			// If done correctly, returns true
			return true;
		}
	}
	// If value is not found, returns false
	return false;
}

bool PriorityQueuesWithQueue::Insert(int value) {
	if (queue[size - 1] != NULL) {
		for (int i = 0; i < size; ++i) {
			//Finding an empty space
			if (queue[i] == NULL) {
				//Setting the new value in the queue and then sorting the queue
				queue[i] = value;
				std::sort(queue, queue + size);

				return true;
			}
		}
	}

	//Priority queue is full
	return false;
}

std::string PriorityQueuesWithQueue::PrintQueue() {
	std::stringstream ss;

	for (int i = 0; i < size; ++i) {
		ss << queue[i];
		ss << " ";
	}

	std::string temp = ss.str();
	temp.pop_back();

	return temp;
}

//*****************************
//* Priory Queue using a Heap *
//*****************************
bool PriorityQueuesWithHeap::Remove(int value) {
	return false;
}

bool PriorityQueuesWithHeap::Insert(int value) {
	return false;
}

std::string PriorityQueuesWithHeap::PrintHeap() {

}
