#include "pch.h"
#include "CppUnitTest.h"
#include "../HashsDLL/HashsDLL.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HashsUnitTest
{
	TEST_CLASS(HashsUnitTest)
	{
	public:
		
		TEST_METHOD(AddItem1)
		{
			HashTable test(5);
			Assert::IsFalse(test.addItem(7,7));
			Assert::IsTrue(test.addItem(5,1));
			Assert::IsTrue(test.addItem(4,2));
			Assert::IsTrue(test.addItem(3,2));
			Assert::IsTrue(test.addItem(2,4));
			Assert::IsTrue(test.addItem(1,3));

		}
		TEST_METHOD(AddItem2)
		{
			HashTable test(5);
			Assert::IsTrue(test.addItem(5,1));
			Assert::IsTrue(test.addItem(4,2));
			Assert::IsTrue(test.addItem(3,3));
			Assert::IsTrue(test.addItem(2,4));
			Assert::IsTrue(test.addItem(1,5));
			Assert::IsFalse(test.addItem(0,4));
		}
		TEST_METHOD(RemoveItem1)
		{
			HashTable test(5);
			Assert::IsTrue(test.addItem(5,1));
			Assert::IsTrue(test.removeItem(1));
			Assert::IsTrue(test.addItem(4,2));
			Assert::IsTrue(test.addItem(3,5));
			Assert::IsTrue(test.removeItem(5));
			Assert::IsTrue(test.removeItem(2));
		}
		TEST_METHOD(RemoveItem2)
		{
			HashTable test(5);
			Assert::IsFalse(test.removeItem(7));
			Assert::IsFalse(test.removeItem(4));
			Assert::IsTrue(test.addItem(5,1));
			Assert::IsTrue(test.removeItem(1));
			Assert::IsTrue(test.addItem(4,2));
			Assert::IsTrue(test.removeItem(2));
			Assert::IsFalse(test.removeItem(3));
		}
		TEST_METHOD(GetNode1)
		{
			HashTable test(5);
			Assert::IsTrue(test.addItem(5, 1));
			Assert::IsTrue(test.addItem(4, 2));
			Assert::AreEqual(test.getNode(1)->getData(),5);
			Assert::AreEqual(test.getNode(2)->getData(),4);
		}
		TEST_METHOD(GetNode2)
		{
			HashTable test(5);
			Assert::IsTrue(test.addItem(5, 1));
			Assert::IsTrue(test.addItem(4, 2));
			if (test.getNode(3) == nullptr) {
				Assert::IsTrue(true);
			}
			else {
				Assert::IsTrue(false);
			}
			Assert::AreEqual(test.getNode(2)->getData(), 4);
		}
		TEST_METHOD(GetLength1)
		{
			HashTable test;
			Assert::AreEqual(test.getLength(), 100);
		}
		TEST_METHOD(GetLength2)
		{
			HashTable test(5);
			Assert::AreEqual(test.getLength(), 5);
		}
		TEST_METHOD(Hash1)
		{
		}
		TEST_METHOD(Hash2)
		{
		}
	};
}
