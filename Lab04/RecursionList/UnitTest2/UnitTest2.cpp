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
	};
}
