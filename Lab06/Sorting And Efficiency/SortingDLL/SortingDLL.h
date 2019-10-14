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

#include <ctime>
#include <stdlib.h>

class SORTINGDLL_API ISortingDLL {
public:
	ISortingDLL() {
		srand(time(NULL));

		for (int i = 0; i < 10; ++i) {
			array10[i] = rand() % 21;
		}

		for (int i = 0; i < 100; ++i) {
			array100[i] = rand() % 101;
		}

		for (int i = 0; i < 500; ++i) {
			array500[i] = rand() % 501;
		}

		for (int i = 0; i < 5000; ++i) {
			array5000[i] = rand() % 5001;
		}

		for (int i = 0; i < 25000; ++i) {
			array25000[i] = rand() % 25001;
		}
	}

private:
	int array10[10];
	int array100[100];
	int array500[500];
	int array5000[5000];
	int array25000[25000];
};

class SORTINGDLL_API Sorting : public ISortingDLL {
public:
	bool Bubble();
	bool Insertion();
	bool Merge();
	bool Quick();
	bool Radix()
};
