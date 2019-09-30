#include "pch.h"
#include "CppUnitTest.h"
#include "../ToString/ToString.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ToString
{
	TEST_CLASS(ToStringUnitTest)
	{
	public:
		
		TEST_METHOD(CardClass1)
		{
			Deck Deck;

			Card Card1 = Card("Heart", 2);
			Card Card2 = Card("Diamond", 12);


			Assert::AreEqual(2, Card1.GetRank());
			Assert::AreEqual(12, Card1.GetRank());

			Assert::AreEqual("Heart", Card1.GetSuit());
			Assert::AreEqual("Diamond", Card2.GetSuit());

			
		}

		TEST_METHOD(CardClass2)
		{
			Deck Deck;

			Card Card1 = Card("Club", 9);
			Card Card2 = Card("Diamond", 10);


			Assert::AreEqual(9, Card1.GetRank());
			Assert::AreEqual(10, Card1.GetRank());

			Assert::AreEqual("Club", Card1.GetSuit());
			Assert::AreEqual("Diamond", Card2.GetSuit());


		}

		TEST_METHOD(CardClass3)
		{
			Deck Deck;

			//Checking to make sure cards cannot be out of 1-13
			Card Card1 = Card("Spade", 15);
			Assert::Fail();

		}

		TEST_METHOD(DeckClass)
		{
			Card Card1 = Card("Heart", 1);
			Deck Deck1;
			Assert::AreEqual(Card1, Deck1.Front());


		}

		TEST_METHOD(PlayerCalss)
		{



		}

		TEST_METHOD(GameClass)
		{



		}
	};
}
