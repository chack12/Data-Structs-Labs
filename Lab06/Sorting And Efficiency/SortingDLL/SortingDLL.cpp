// SortingDLL.cpp : Defines the exported functions for the DLL.
//

#include <iostream>
#include <vector>
#include "framework.h"
#include "SortingDLL.h"

// Make a copy of the private array within the function. Then sort the copy
// of the array.

std::vector<int> Sorting::Bubble(std::vector<int> myArray) {
	std::vector<int> sortedArray = myArray;
	int max = sortedArray.size() * 2 + 1;
	int count = 0;
	SortingArrays sort;
	bool sorted = false;
	// For loop iterating through whole array
	while (!sorted)	{
		count = 0;
		for (int i = 0; i < sortedArray.size() - 1; ++i)	{
			if (sortedArray[i] > sortedArray[i+1])	{
				if (sortedArray[i] > sortedArray.size() - 1) {
					max = sortedArray[i];
				}
				int temp = sortedArray[i+1];
				sortedArray[i+1] = sortedArray[i];
				sortedArray[i] = temp;
			}
			else {
				if (sortedArray[i] > sortedArray.size() - 1)	{
					max = sortedArray[i+1];
				}
			}
		}
		sorted = sort.isSorted(sortedArray);
	}
	return sortedArray;
}

std::vector<int> Sorting::Insertion(std::vector<int> myArray) {
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
