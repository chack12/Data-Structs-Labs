#include "pch.h"
#include "CppUnitTest.h"
#include "../ToStringDLL/ToStringDLL.cpp"

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
			Deck Deck;
			Player player1 = "Chris";
			Player player2 = "Derek";

			//Checking for player names matching and not matching respectively. 
			Assert::AreEqual(std::string("Chris"), player1.GetName());
			Assert::AreNotEqual(std::string("Derekk"), player2.GetName());

			player1.AddCardToHand(Deck.Front());
			player2.AddCardToHand(Deck.Front());

			/*Checking for players pulling the correct card and outputting the correct 
			string from private vector */
			Assert::AreEqual(std::string("1"), player1.ShowHandString());
			Assert::AreNotEqual(std::string("4"), player2.ShowHandString());


			// Assert::IsTrue(NULL, player1.~Player());
		}

		TEST_METHOD(GameClass)
		{



		}
	};
}
