// SortingDLL.cpp : Defines the exported functions for the DLL.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "framework.h"
#include "SortingDLL.h"

//**********************
// * Sorting Functions *
//**********************

//Bubble Sort
std::vector<int> Sorting::Bubble(std::vector<int> myArray) {
	// Create copy of vector to make changes to
	std::vector<int> sortedArray = myArray;
	// Initialize count
	int count = 0;
	// Variable used to escape while loop
	bool sorted = false;
	// For loop iterating through whole array
	while (!sorted)	{
		// For loop iterating through whole array
		for (int i = 0; i < sortedArray.size() - 1; ++i)	{
			// Checks to see if the next value is larger than the previous
			if (sortedArray[i] > sortedArray[i + 1])	{
				// Flips the values
				int temp = sortedArray[i + 1];
				sortedArray[i + 1] = sortedArray[i];
				sortedArray[i] = temp;
			}
		}
		// External function to check if the vector is sorted
		sorted = isSorted(sortedArray);
	}

	return sortedArray;
}

//Insertion Sort
std::vector<int> Sorting::Insertion(std::vector<int> myArray) {
	// Iterates through the array starting at the second element in the array
	for (int i = 1; i < myArray.size(); ++i) {
		// Setting next item equal to the second item in the array 
		int nextItem = myArray[i];
		// Setting the insertion index to i
		int insertIndex = i;

		// While insertion index is greater than 0 and the element in the array before the insertion index
		// are greater than the nextItem (the item at the insertion index), the loop will continue to run
		// There is a while loop because if the value at insertion index needs to be moved multiple places to the
		// left, the loop will move it multiple times until it is either the smallest element in the array
		// or the element before it is too small
		while ((insertIndex > 0) && (myArray[insertIndex - 1] > nextItem)) {
			// If the above is true, the array at the insertion index will be set equal to the element
			// before the insertion index
			myArray[insertIndex] = myArray[insertIndex - 1];
			// Decrement insertion index
			insertIndex--;
		}

		// Once the while loop stops, sets the element at the insertion index to the next Item value,
		// (sets the element at interation index to the value of the element that was moved)
		myArray[insertIndex] = nextItem;
	}

	return myArray;
}

//Merge Sort
std::vector<int> Sorting::Merge(std::vector<int> &myArray, int first, int last) {
	// If the right iterator is greater than the left iterator
	if (first < last) {
		// Find midpoint of the array
		int mid = (first + last) / 2;

		// Recursively calling functions 
		// One for left side of midpoint
		Merge(myArray, first, mid);
		// One for the right side of the midpoint
		Merge(myArray, mid + 1, last);
		// 
		Merger(myArray, first, mid, last);
	}

	return myArray;
}

//Quick Sort
std::vector<int> Sorting::Quick(std::vector<int> &myArray, int first, int last) {
	if (first < last) {
		int pivot = Partition(myArray, first, last);

		Quick(myArray, first, pivot - 1);
		Quick(myArray, pivot + 1, last);
	}

	return myArray;
}

//Raxdix Sort
std::vector<std::string> Sorting::Radix(std::vector<std::string> myArray) {
	//Creates a temporary vector
	std::vector<std::string> temp;
	//Creates a stringstream
	std::stringstream ss;

	//Iterate through the number of digits
	for (int digit = myArray[0].size() - 1; digit >= 0; --digit) {
		//Iterate from 0 to 9
		for (int number = 0; number < 10; ++number) {
			//Iterate through all the elements
			for (int element = 0; element < myArray.size(); ++element) {
				//If the specific digit on the given element is equal to the number
				//add it to the temp array
				if (myArray[element][digit] - 48 == number) {
					temp.push_back(myArray[element]);
				}
			}
		}

		//If the temp array has all the items in it replace the orginal array
		if (temp[0] != "") {
			myArray = temp;
		}

		//Clear the temp array
		temp.clear();
	}

	return myArray;
}

//********************
//* Helper Functions *
//********************

void Sorting::Merger(std::vector<int>& myArray, int first, int mid, int last) {
	// Creates temp array and sets it to the size of the array being inputted
	std::vector<int> temp;
	temp.resize(myArray.size());
	
	// First array, first element value
	int first1 = first;
	// First array, last element value
	int last1 = mid;
	// Second array, first element value
	int first2 = mid + 1;
	// Second array, last element value
	int last2 = last;

	// Setting index value to the first element of the first array
	int index = first1;

	// While the first element in the first array is less than the last element in the first array
	// and the first element in the second array is less than the last element in the second array
	while ((first1 <= last1) && (first2 <= last2)) {
		// If the first element of the first array is less than the first element of the second array
		if (myArray[first1] <= myArray[first2]) {
			// Setting the temp array at the index to the value of the location of the first iterator of the first array
			temp[index] = myArray[first1];
			// Move the first iterator of the first array to the second element
			first1++;
		}
		else {
			// Setting the temp array at the index to the value of the location of the first iterator of the second array
			temp[index] = myArray[first2];
			// Move the first iterator of the second array to the second element
			first2++;
		}
		// Moves the temp iterator from the first element to the second element
		index++;
	}

	// While the first iterator of the first array is less than the last iterator of the first array
	while (first1 <= last1) {
		// Setting the temp array at the index to the value of the first iterator of the first array
		temp[index] = myArray[first1];
		// Increase first iterator of first array
		first1++;
		// Increase the index iterator
		index++;
	}

	// While the first iterator of the second array is less than the last iterator of the second array
	while (first2 <= last2) {
		// Setting the temp array at the index to the value of the first iterator of the second array
		temp[index] = myArray[first2];
		// Increase second iterator of second array
		first2++;
		// Increase the index iterator
		index++;
	}

	// Sets temp array equal to the actual array to complete the sort
	for (index = first; index <= last; ++index) {
		myArray[index] = temp[index];
	}
}

//Swaps the elements in the vector of the given indeces
void Sorting::Swap(std::vector<int>& myArray, int index1, int index2) {
	//Copy the element at index1
	int temp = myArray[index1];
	//Replace the element at index1 with the element at index2
	myArray[index1] = myArray[index2];
	//Replace the element at index2 with the copied element from index1
	myArray[index2] = temp;
}

int Sorting::Partition(std::vector<int>& myArray, int first, int last) {
	//Setting the pivot point at the last element
	int pivot = myArray[last];
	int left = first - 1;

	//Iterating the right pointer starting at the far left
	for (int right = first; right <= last; ++right) {
		//If the element at the right pointer is less than the pivot
		//increase the left pointer and swap the left and right element
		if (myArray[right] < pivot) {
			left++;
			Swap(myArray, left, right);
		}
	}

	//Swap the left + 1 and the last element
	Swap(myArray, left + 1, last);

	//Return the new pivot point
	return left + 1;
}

//Checks to see if the vector is sorted or not
bool Sorting::isSorted(std::vector<int> sortedVector) {
	//Initialize count to 0
	int count = 0;

	//Iterate through the whole vector
	for (int i = 0; i < sortedVector.size() - 1; ++i) {
		//If element at index i is less than the element at the index i + 1
		//increase the count
		if (sortedVector[i] <= sortedVector[i + 1]) {
			count++;
		}
		//If it counted the size of the vector then all the elements are sorted
		//in ascending order
		if (count == sortedVector.size() - 1) {
			return true;
		}
	}
	
	return false;
}

//*****************
//* Array getters *
//*****************

//Returns a copy of the array with 100 items
std::vector<int> SortingArrays::GetArray10() {
	return array10;
}

//Returns a copy of the array with 100 items
std::vector<int> SortingArrays::GetArray100() {
	return array100;
}

//Returns a copy of the array with 500 items
std::vector<int> SortingArrays::GetArray500() {
	return array500;
}

//Returns a copy of the array with 5000 items
std::vector<int> SortingArrays::GetArray5000() {
	return array5000;
}

//Returns a copy of the array with 25000 items
std::vector<int> SortingArrays::GetArray25000() {
	return array25000;
}