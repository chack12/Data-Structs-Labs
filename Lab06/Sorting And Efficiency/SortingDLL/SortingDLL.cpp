// SortingDLL.cpp : Defines the exported functions for the DLL.
//

#include <iostream>
#include <vector>
#include "framework.h"
#include "SortingDLL.h"

// Make a copy of the private array within the function. Then sort the copy
// of the array.

std::vector<int> Sorting::Bubble(std::vector<int> myArray) {
	// Create copy of vector to make changes to
	std::vector<int> sortedArray = myArray;
	// Initialize count
	int count = 0;
	// Create object of sortingarrays
	SortingArrays sort;
	// Variable used to escape while loop
	bool sorted = false;
	// For loop iterating through whole array
	while (!sorted)	{
		// For loop iterating through whole array
		for (int i = 0; i < sortedArray.size() - 1; ++i)	{
			// Checks to see if the next value is larger than the previous
			if (sortedArray[i] > sortedArray[i+1])	{
				// Flips the values
				int temp = sortedArray[i+1];
				sortedArray[i+1] = sortedArray[i];
				sortedArray[i] = temp;
			}
		}
		// External function to check if the vector is sorted
		sorted = sort.isSorted(sortedArray);
	}
	return sortedArray;
}

std::vector<int> Sorting::Insertion(std::vector<int> myVector) {
	std::vector<int> sortedVector = myVector;
	int max = (myVector.size() * 2) + 1;
	bool flag = true;
	
	while (flag) {
		for (int i = 0; i < sortedVector.size() - 1; ++i) {
				for (int j = i + 1; j < sortedVector.size() - 1; ++i) {
					if (sortedVector[i] < sortedVector[j]) {
						
				}
			}

		}


	}
	return myArray;
}

std::vector<int> Sorting::Merge(std::vector<int> myArray) {
	return myArray;
}

std::vector<int> Sorting::Quick(std::vector<int> myArray) {
	return myArray;
}

std::vector<std::string> Sorting::Radix(std::vector<std::string> myArray) {
	return myArray;
}

// Array getters

std::vector<int> SortingArrays::GetArray10() {
	return array10;
}

std::vector<int> SortingArrays::GetArray100() {
	return array100;
}

std::vector<int> SortingArrays::GetArray500() {
	return array500;
}

std::vector<int> SortingArrays::GetArray5000() {
	return array5000;
}

std::vector<int> SortingArrays::GetArray25000() {
	return array25000;
}

bool SortingArrays::isSorted(std::vector<int> sortedVector)
{
	int count = 0;
	for (int i = 0; i < sortedVector.size() - 1; ++i) {
		if (sortedVector.at(i) <= sortedVector.at(i + 1)) {
			count++;
		}
		if (count == sortedVector.size() - 1) {
			 return true;
		}
	}
	return false;
}
