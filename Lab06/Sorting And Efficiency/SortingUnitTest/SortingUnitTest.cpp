#include "pch.h"
#include "CppUnitTest.h"
#include "../SortingDLL/SortingDLL.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingUnitTest
{
	TEST_CLASS(SortingUnitTest)
	{
	public:
		
		TEST_METHOD(Bubble)
		{
			Sorting sort;

			SortingArrays arrays;

			Assert::IsTrue(sort.Bubble(arrays.GetArray10()));
			Assert::IsTrue(sort.Bubble(arrays.GetArray100()));
			Assert::IsTrue(sort.Bubble(arrays.GetArray500()));
			Assert::IsTrue(sort.Bubble(arrays.GetArray5000()));
			Assert::IsTrue(sort.Bubble(arrays.GetArray25000()));
		}

		TEST_METHOD(Insertion)
		{
			Sorting sort;

			SortingArrays arrays;

			Assert::IsTrue(sort.Insertion(arrays.GetArray10()));
			Assert::IsTrue(sort.Insertion(arrays.GetArray100()));
			Assert::IsTrue(sort.Insertion(arrays.GetArray500()));
			Assert::IsTrue(sort.Insertion(arrays.GetArray5000()));
			Assert::IsTrue(sort.Insertion(arrays.GetArray25000()));
		}

		TEST_METHOD(Merge)
		{
			Sorting sort;

			SortingArrays arrays;

			Assert::IsTrue(sort.Merge(arrays.GetArray10()));
			Assert::IsTrue(sort.Merge(arrays.GetArray100()));
			Assert::IsTrue(sort.Merge(arrays.GetArray500()));
			Assert::IsTrue(sort.Merge(arrays.GetArray5000()));
			Assert::IsTrue(sort.Merge(arrays.GetArray25000()));
		}

		TEST_METHOD(Quick)
		{
			Sorting sort;

			SortingArrays arrays;

			Assert::IsTrue(sort.Quick(arrays.GetArray10()));
			Assert::IsTrue(sort.Quick(arrays.GetArray100()));
			Assert::IsTrue(sort.Quick(arrays.GetArray500()));
			Assert::IsTrue(sort.Quick(arrays.GetArray5000()));
			Assert::IsTrue(sort.Quick(arrays.GetArray25000()));
		}

		TEST_METHOD(Radix)
		{
			Sorting sort;
			SortingArrays arrays;
			std::stringstream ss;

			std::vector<std::string> sArray10;
			std::vector<std::string> sArray100;
			std::vector<std::string> sArray500;
			std::vector<std::string> sArray5000;
			std::vector<std::string> sArray25000;

			std::vector<int> array10 = arrays.GetArray10();
			std::vector<int> array100 = arrays.GetArray100();
			std::vector<int> array500 = arrays.GetArray500();
			std::vector<int> array5000 = arrays.GetArray5000();
			std::vector<int> array25000 = arrays.GetArray25000();

			for (int i = 0; i < 10; ++i) {
				ss << array10[i];
				if (array10[i] < 10) {
					ss << "0" + array10[i];
				}
				sArray10[i] = ss.str();
			}

			for (int i = 0; i < 100; ++i) {
				ss << array100[i];
				if (array100[i] < 10) {
					ss << "00" + array100[i];
				}
				else if (array100[i] < 100) {
					ss << "0" + array100[i];
				}
				sArray100[i] = ss.str();
			}

			for (int i = 0; i < 500; ++i) {
				ss << array500[i];
				if (array500[i] < 10) {
					ss << "00" + array500[i];
				}
				else if (array500[i] < 100) {
					ss << "0" + array500[i];
				}
				sArray500[i] = ss.str();
			}

			for (int i = 0; i < 5000; ++i) {
				ss << array5000[i];
				if (array5000[i] < 10) {
					ss << "000" + array5000[i];
				}
				else if (array5000[i] < 100) {
					ss << "00" + array5000[i];
				}
				else if (array5000[i] < 1000) {
					ss << "0" + array5000[i];
				}
				sArray5000[i] = ss.str();
			}

			for (int i = 0; i < 25000; ++i) {
				ss << array25000[i];
				if (array25000[i] < 10) {
					ss << "0000" + array25000[i];
				}
				else if (array25000[i] < 100) {
					ss << "000" + array25000[i];
				}
				else if (array25000[i] < 1000) {
					ss << "00" + array25000[i];
				}
				else if (array25000[i] < 10000) {
					ss << "0" + array25000[i];
				}
				sArray25000[i] = ss.str();
			}

			Assert::IsTrue(sort.Radix(sArray10));
			Assert::IsTrue(sort.Radix(sArray100));
			Assert::IsTrue(sort.Radix(sArray500));
			Assert::IsTrue(sort.Radix(sArray5000));
			Assert::IsTrue(sort.Radix(sArray25000));
		}
	};
}
