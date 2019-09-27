#include "pch.h"
#include "CppUnitTest.h"
#include "..\RecursionList\RecursionList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTestPalindrome)
	{
	public:
		TEST_METHOD(Loop1)
		{
			PalindromeByLoop checker;

			Assert::IsTrue(checker.isPalindrome("racecar"));
			Assert::IsFalse(checker.isPalindrome("notapalindrome"));
			Assert::IsTrue(checker.isPalindrome("top spot"));
			Assert::IsFalse(checker.isPalindrome("Hello, world!"));
		}

		TEST_METHOD(Loop2)
		{
			PalindromeByLoop checker;

			Assert::IsTrue(checker.isPalindrome("a"));
			Assert::IsFalse(checker.isPalindrome("ab"));
			Assert::IsFalse(checker.isPalindrome(""));
		}

		TEST_METHOD(Recursion1)
		{
			PalindromeByLoop checker;

			Assert::IsTrue(checker.isPalindrome("racecar"));
			Assert::IsFalse(checker.isPalindrome("notapalindrome"));
			Assert::IsTrue(checker.isPalindrome("top spot"));
			Assert::IsFalse(checker.isPalindrome("Hello, world!"));
		}

		TEST_METHOD(Recursion2)
		{
			PalindromeByLoop checker;

			Assert::IsTrue(checker.isPalindrome("a"));
			Assert::IsFalse(checker.isPalindrome("ab"));
			Assert::IsFalse(checker.isPalindrome(""));
		}

		TEST_METHOD(Stack1)
		{
			PalindromeByLoop checker;

			Assert::IsTrue(checker.isPalindrome("racecar"));
			Assert::IsFalse(checker.isPalindrome("notapalindrome"));
			Assert::IsTrue(checker.isPalindrome("top spot"));
			Assert::IsFalse(checker.isPalindrome("Hello, world!"));
		}

		TEST_METHOD(Stack2)
		{
			PalindromeByLoop checker;

			Assert::IsTrue(checker.isPalindrome("a"));
			Assert::IsFalse(checker.isPalindrome("ab"));
			Assert::IsFalse(checker.isPalindrome(""));
		}

		TEST_METHOD(UserDefinedExceptionTest1)
		{

			std::string status = CallSimpleExceptionMethod(1);
			Assert::AreEqual(std::string("I got Exception 1"), status);

		}

		TEST_METHOD(UserDefinedExceptionTest2)
		{


			std::string status = CallSimpleExceptionMethod(2);
			Assert::AreEqual(std::string("I got Exception 2"), status);

		}

		TEST_METHOD(UserDefinedExceptionTest3)
		{

			std::string status = CallSimpleExceptionMethod(3);
			Assert::AreEqual(std::string("I got Exception 3"), status);

		}

		TEST_METHOD(UserDefinedExceptionTest4)
		{

			std::string status = CallSimpleExceptionMethod(4);
			Assert::AreEqual(std::string("I did not get an Exception"), status);

		}
	};
}
