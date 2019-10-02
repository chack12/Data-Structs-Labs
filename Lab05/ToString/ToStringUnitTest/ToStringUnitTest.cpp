#include "pch.h"
#include "CppUnitTest.h"
#include "../ToStringDLL/ToStringDLL.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ToStringTest
{
	TEST_CLASS(ToStringUnitTest)
	{
	public:
		TEST_METHOD(CardClass)
		{
			//Test GetRank()
			Card card1 = Card(2);
			Card card2 = Card(12);

			Assert::AreEqual(2, card1.GetRank());
			Assert::AreEqual(12, card2.GetRank());
		}

		TEST_METHOD(DeckClass)
		{
			//Test CardAt()
			Deck deck;
		}

		TEST_METHOD(PlayerClass)
		{
			//Test GetName()
			//Test AddCardToHand()
			//Test AddCardToStack()
			//Test ShowHand()
			//Test ShowStack()

			Deck Deck;
			Player player1 = "Chris";
			Player player2 = "Derek";

			//Checking for player names matching and not matching respectively. 
			Assert::AreEqual(std::string("Chris"), player1.GetName());
			Assert::AreNotEqual(std::string("Derekk"), player2.GetName());

			player1.AddCardToHand(Deck.CardAt(0));
			player2.AddCardToHand(Deck.CardAt(0));

			/*Checking for players pulling the correct card and outputting the correct 
			string from private vector */
			Assert::AreEqual(std::string("1"), player1.ShowHandString());
			Assert::AreNotEqual(std::string("4"), player2.ShowHandString());
		}

		TEST_METHOD(GameClass)
		{



		}
	};
}
