// SortingEXE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <string>
#include <sstream>
#include <vector>
#include "../SortingDLL/SortingDLL.h"
typedef std::chrono::high_resolution_clock Clock;

int main()
{
	//Intialize all the variables
	Sorting sort;
	SortingArrays arrays;
	std::stringstream ss;

	//Create copies of the arrays so that the sorting doesnt override them
	std::vector<int> tempArray10 = arrays.GetArray10();
	std::vector<int> tempArray100 = arrays.GetArray100();
	std::vector<int> tempArray500 = arrays.GetArray500();
	std::vector<int> tempArray5000 = arrays.GetArray5000();
	std::vector<int> tempArray25000 = arrays.GetArray25000();
	
	//**********
	//* Bubble *
	//**********
	auto t1 = Clock::now();
	sort.Bubble(arrays.GetArray10());
	auto t2 = Clock::now();
	std::cout << "Bubble size 10: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;
	
	t1 = Clock::now();
	sort.Bubble(arrays.GetArray100());
	t2 = Clock::now();
	std::cout << "Bubble size 100: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;

	t1 = Clock::now();
	sort.Bubble(arrays.GetArray500());
	t2 = Clock::now();
	std::cout << "Bubble size 500: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;

	t1 = Clock::now();
	sort.Bubble(arrays.GetArray5000());
	t2 = Clock::now();
	std::cout << "Bubble size 5000: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;

	t1 = Clock::now();
	sort.Bubble(arrays.GetArray25000());
	t2 = Clock::now();
	std::cout << "Bubble size 25000: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;

	std::cout << std::endl;

	//*************
	//* Insertion *
	//*************
	t1 = Clock::now();
	sort.Insertion(arrays.GetArray10());
	t2 = Clock::now();
	std::cout << "Insertion size 10: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;

	t1 = Clock::now();
	sort.Insertion(arrays.GetArray100());
	t2 = Clock::now();
	std::cout << "Insertion size 100: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;

	t1 = Clock::now();
	sort.Insertion(arrays.GetArray500());
	t2 = Clock::now();
	std::cout << "Insertion size 500: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;

	t1 = Clock::now();
	sort.Insertion(arrays.GetArray5000());
	t2 = Clock::now();
	std::cout << "Insertion size 5000: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;

	t1 = Clock::now();
	sort.Insertion(arrays.GetArray25000());
	t2 = Clock::now();
	std::cout << "Insertion size 25000: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;

	std::cout << std::endl;

	//*********
	//* Merge *
	//*********
	tempArray10 = arrays.GetArray10();
	tempArray100 = arrays.GetArray100();
	tempArray500 = arrays.GetArray500();
	tempArray5000 = arrays.GetArray5000();
	tempArray25000 = arrays.GetArray25000();

	t1 = Clock::now();
	sort.Merge(tempArray10, 0, tempArray10.size() - 1);
	t2 = Clock::now();
	std::cout << "Merge size 10: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;

	t1 = Clock::now();
	sort.Merge(tempArray100, 0, tempArray100.size() - 1);
	t2 = Clock::now();
	std::cout << "Merge size 100: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;

	t1 = Clock::now();
	sort.Merge(tempArray500, 0, tempArray500.size() - 1);
	t2 = Clock::now();
	std::cout << "Merge size 500: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;

	t1 = Clock::now();
	sort.Merge(tempArray5000, 0, tempArray5000.size() - 1);
	t2 = Clock::now();
	std::cout << "Merge size 5000: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;

	t1 = Clock::now();
	sort.Merge(tempArray25000, 0, tempArray25000.size() - 1);
	t2 = Clock::now();
	std::cout << "Merge size 25000: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;

	std::cout << std::endl;

	//*********
	//* Quick *
	//*********
	tempArray10 = arrays.GetArray10();
	tempArray100 = arrays.GetArray100();
	tempArray500 = arrays.GetArray500();
	tempArray5000 = arrays.GetArray5000();
	tempArray25000 = arrays.GetArray25000();

	t1 = Clock::now();
	sort.Quick(tempArray10, 0, arrays.GetArray10().size() - 1);
	t2 = Clock::now();
	std::cout << "Quick size 10: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;

	t1 = Clock::now();
	sort.Quick(tempArray100, 0, arrays.GetArray100().size() - 1);
	t2 = Clock::now();
	std::cout << "Quick size 100: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;

	t1 = Clock::now();
	sort.Quick(tempArray500, 0, arrays.GetArray500().size() - 1);
	t2 = Clock::now();
	std::cout << "Quick size 500: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;

	t1 = Clock::now();
	sort.Quick(tempArray5000, 0, arrays.GetArray5000().size() - 1);
	t2 = Clock::now();
	std::cout << "Quick size 5000: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;

	t1 = Clock::now();
	sort.Quick(tempArray25000, 0, arrays.GetArray25000().size() - 1);
	t2 = Clock::now();
	std::cout << "Quick size 25000: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;
	
	std::cout << std::endl;

	//*********
	//* Radix *
	//*********
	std::vector<std::string> sArray10;
	std::vector<std::string> sArray100;
	std::vector<std::string> sArray500;
	std::vector<std::string> sArray5000;
	std::vector<std::string> sArray25000;

	//Creating string vectors the same size as the orginal vectors
	sArray10.resize(arrays.GetArray10().size());
	sArray100.resize(arrays.GetArray100().size());
	sArray500.resize(arrays.GetArray500().size());
	sArray5000.resize(arrays.GetArray5000().size());
	sArray25000.resize(arrays.GetArray25000().size());

	std::vector<int> array10 = arrays.GetArray10();
	std::vector<int> array100 = arrays.GetArray100();
	std::vector<int> array500 = arrays.GetArray500();
	std::vector<int> array5000 = arrays.GetArray5000();
	std::vector<int> array25000 = arrays.GetArray25000();

	//Padding zeros on the vectors so that the are all the same length
	for (int i = 0; i < 10; ++i) {
		if (array10[i] < 10) {
			ss << "0";
			ss<< array10[i];
			sArray10[i] = ss.str();
		}
		else {
			ss << array10[i];
			sArray10[i] = ss.str();
		}
		
		ss.str("");
	}

	for (int i = 0; i < 100; ++i) {
		if (array100[i] < 10) {
			ss << "00";
			ss << array100[i];
			sArray100[i] = ss.str();
		}
		else if (array100[i] < 100) {
			ss << "0";
			ss<< array100[i];
			sArray100[i] = ss.str();
		}
		else {
			ss << array100[i];
			sArray100[i] = ss.str();
		}
		
		ss.str("");
	}

	for (int i = 0; i < 500; ++i) {
		if (array500[i] < 10) {
			ss << "00";
			ss << array500[i];
			sArray500[i] = ss.str();
		}
		else if (array500[i] < 100) {
			ss << "0";
			ss << array500[i];
			sArray500[i] = ss.str();
		}
		else {
			ss << array500[i];
			sArray500[i] = ss.str();
		}

		ss.str("");
	}

	for (int i = 0; i < 5000; ++i) {
		if (array5000[i] < 10) {
			ss << "000";
			ss << array5000[i];
			sArray5000[i] = ss.str();
		}
		else if (array5000[i] < 100) {
			ss << "00";
			ss << array5000[i];
			sArray5000[i] = ss.str();
		}
		else if (array5000[i] < 1000) {
			ss << "0";
			ss << array5000[i];
			sArray5000[i] = ss.str();
		}
		else {
			ss << array5000[i];
			sArray5000[i] = ss.str();
		}

		ss.str("");
	}

	for (int i = 0; i < 25000; ++i) {
		if (array25000[i] < 10) {
			ss << "0000";
			ss << array25000[i];
			sArray25000[i] = ss.str();
		}
		else if (array25000[i] < 100) {
			ss << "000";
			ss << array25000[i];
			sArray25000[i] = ss.str();
		}
		else if (array25000[i] < 1000) {
			ss << "00";
			ss << array25000[i];
			sArray25000[i] = ss.str();
		}
		else if (array25000[i] < 10000) {
			ss << "0";
			ss << array25000[i];
			sArray25000[i] = ss.str();
		}
		else {
			ss << array25000[i];
			sArray25000[i] = ss.str();
		}

		ss.str("");
	}

	t1 = Clock::now();
	sort.Radix(sArray10);
	t2 = Clock::now();
	std::cout << "Radix size 10: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;

	t1 = Clock::now();
	sort.Radix(sArray100);
	t2 = Clock::now();
	std::cout << "Radix size 100: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;

	t1 = Clock::now();
	sort.Radix(sArray500);
	t2 = Clock::now();
	std::cout << "Radix size 500: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;

	t1 = Clock::now();
	sort.Radix(sArray5000);
	t2 = Clock::now();
	std::cout << "Radix size 5000: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;

	t1 = Clock::now();
	sort.Radix(sArray25000);
	t2 = Clock::now();
	std::cout << "Radix size 25000: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;

	return 0;
}