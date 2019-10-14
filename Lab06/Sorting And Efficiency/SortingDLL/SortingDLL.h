// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the SORTINGDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// SORTINGDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef SORTINGDLL_EXPORTS
#define SORTINGDLL_API __declspec(dllexport)
#else
#define SORTINGDLL_API __declspec(dllimport)
#endif

#include <iostream>
#include <ctime>
#include <vector>
#include <stdlib.h>

class SORTINGDLL_API Sorting {
public:
	std::vector<int> Bubble(std::vector<int> myArray);
	std::vector<int> Insertion(std::vector<int> myArray);
	std::vector<int> Merge(std::vector<int> myArray);
	std::vector<int> Quick(std::vector<int> myArray);
	std::vector<int> Radix(std::vector<std::string> myArray);
};

class SORTINGDLL_API SortingArrays {
public:
	SortingArrays() {
		srand(time(NULL));

		for (int i = 0; i < 10; ++i) {
			array10.push_back(rand() % 21);
		}

		for (int i = 0; i < 100; ++i) {
			array100.push_back(rand() % 101);
		}

		for (int i = 0; i < 500; ++i) {
			array500.push_back(rand() % 501);
		}

		for (int i = 0; i < 5000; ++i) {
			array5000.push_back(rand() % 5001);
		}

		for (int i = 0; i < 25000; ++i) {
			array25000.push_back(rand() % 25001);
		}
	}

	std::vector<int> GetArray10();
	std::vector<int> GetArray100();
	std::vector<int> GetArray500();
	std::vector<int> GetArray5000();
	std::vector<int> GetArray25000();

private:
	std::vector<int> array10;
	std::vector<int> array100;
	std::vector<int> array500;
	std::vector<int> array5000;
	std::vector<int> array25000;
};
