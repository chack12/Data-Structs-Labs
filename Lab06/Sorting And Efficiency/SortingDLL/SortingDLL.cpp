// SortingDLL.cpp : Defines the exported functions for the DLL.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "framework.h"
#include "SortingDLL.h"

// Make a copy of the private array within the function. Then sort the copy
// of the array.

std::vector<int> Sorting::Bubble(std::vector<int> myArray) {
	std::vector<int> sortedArray = myArray;
	int max = 50001;
	int temp = sortedArray.at(sortedArray.size() - 1);
	// For loop iterating through whole array
	while (temp < max)	{
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
	std::vector<std::string> temp;
	std::stringstream ss;

	int count = 0;

	//Iterate through the number of digits
	for (int digit = myArray[0].size() - 1; digit >= 0; --digit) {
		//Iterate through the number of elements
		for (int number = 0; number < 10; ++number) {
			for (int element = 0; element < myArray.size(); ++element) {
				//Iterate through the different numbers and group them
				if (myArray[element][digit] - 48 == number) {
					temp.push_back(myArray[element]);
				}
			}
		}

		if (temp[0] != "") {
			myArray = temp;
		}

		temp.clear();
	}

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