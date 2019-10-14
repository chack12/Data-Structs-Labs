#include "pch.h"
#include "CppUnitTest.h"
#include "../SortingDLL/SortingDLL.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingUnitTest
{
	TEST_CLASS(SortingUnitTest)
	{
	public:
		
		TEST_METHOD(Bubble)
		{
			Sorting sort;

			//Initialize a sorted and unsorted vector of same size with same values.
			std::vector<int> unsortedVector = {3, 2, 4, 5, 1, 6, 9, 0, 8, 7};
			std::vector<int> sortedVector = { 0, 1, 2, 3, 4, 5, 6, 7, 8 ,9};


			// Asserting that the Bubble sort will equal the sortedVector initialized.
			Assert::AreEqual(sort.Bubble(unsortedVector), sortedVector);

		}

		TEST_METHOD(Insertion)
		{
			Sorting sort;

			// Iniitalize a sorted and unsorted vector of same size with same values.
			std::vector<int> unsortedVector = { 3, 2, 4, 5, 1, 6, 9, 0, 8, 7};
			std::vector<int> sortedVector = { 0, 1, 2, 3, 4, 5, 6, 7, 8 , 9};

			// Asserting that the Insertion sort will equal the sortedVector initialized.
			Assert::AreEqual(sort.Insertion(unsortedVector), sortedVector);
			
		}

		TEST_METHOD(Merge)
		{
			Sorting sort;

			//Initialize a sorted and unsorted vector of same size with same values.
			std::vector<int> unsortedVector = { 3, 2, 4, 5, 1, 6, 9, 0, 8, 7 };
			std::vector<int> sortedVector = { 0, 1, 2, 3, 4, 5, 6, 7, 8 ,9 };


			// Asserting that the Merge sort will equal the sortedVector initialized.
			Assert::AreEqual(sort.Merge(unsortedVector), sortedVector);
			
		}

		TEST_METHOD(Quick)
		{
			Sorting sort;

			//Initialize a sorted and unsorted vector of same size with same values.
			std::vector<int> unsortedVector = { 3, 2, 4, 5, 1, 6, 9, 0, 8, 7 };
			std::vector<int> sortedVector = { 0, 1, 2, 3, 4, 5, 6, 7, 8 ,9 };


			// Asserting that the Quick sort will equal the sortedVector initialized.
			Assert::AreEqual(sort.Quick(unsortedVector), sortedVector);

		}

		TEST_METHOD(Radix)
		{
			Sorting sort;

			//Initialize a sorted and unsorted vector of same size with same values.
			std::vector<std::string> unsortedVector = {"012", "013", "010" "014", "009", "001", "005", "101", "600", "500"};
			std::vector<std::string> sortedVector = {"001", "005", "009", "010", "012", "013", "014", "101", "500", "600"};


			// Asserting that the Merge sort will equal the sortedVector initialized.
			Assert::AreEqual(sort.Radix(unsortedVector), sortedVector);

		}
	};
}
