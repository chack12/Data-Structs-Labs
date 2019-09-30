#include "pch.h"
#include "CppUnitTest.h"
#include "../ToString/ToString.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ToStringTest
{
	TEST_CLASS(ToStringUnitTest)
	{
	public:

		TEST_METHOD(CardClass1)
		{
			Deck Deck;

			Card Card1 = Card(2);
			Card Card2 = Card(12);


			Assert::AreEqual(2, Card1.GetRank());
			Assert::AreEqual(12, Card1.GetRank());


		}

		TEST_METHOD(CardClass2)
		{
			Deck Deck;

			Card Card1 = Card(9);
			Card Card2 = Card(10);


			Assert::AreEqual(9, Card1.GetRank());
			Assert::AreEqual(10, Card1.GetRank());

		}

		TEST_METHOD(CardClass3)
		{
			Deck Deck;

			//Checking to make sure cards cannot be out of 1-13
			Card Card1 = Card(15);
			Assert::Fail();

		}

		TEST_METHOD(DeckClass)
		{
			Card* Card1 = &Card(1);
			Deck Deck1;
			Assert::AreEqual(Card1, Deck1.Front());


		}

		TEST_METHOD(PlayerClass)
		{
			Player player1 = "Chris";
			Assert::AreEqual("Chris", player1.GetName);
			Assert::AreEqual("", player1.~Player());
		}

		TEST_METHOD(GameClass)
		{



		}
	};
}
