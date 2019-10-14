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
	int max = 50001;
	
	// For loop iterating through whole array
	while (sortedArray.size() - 1 < max)	{
		for (int i = 0; i < sortedArray.size() - 1; ++i)	{
			if (sortedArray[i] > sortedArray[i+1])	{
				if (sortedArray[i] > sortedArray.size() - 1)	{
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
	}
}

std::vector<int> Sorting::Insertion(std::vector<int> myArray) {
}

std::vector<int> Sorting::Merge(std::vector<int> myArray) {
}

std::vector<int> Sorting::Quick(std::vector<int> myArray) {
}

std::vector<int> Sorting::Radix(std::vector<std::string> myArray) {
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