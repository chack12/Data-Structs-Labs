#include "pch.h"
#include "CppUnitTest.h"
#include "../ToStringDLL/ToStringDLL.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ToStringTest
{
	TEST_CLASS(ToStringUnitTest)
	{
	public:

		TEST_METHOD(CardClass1)
		{
			Deck deck;

			Card Card1 = Card(2);
			Card Card2 = Card(12);


			Assert::AreEqual(2, Card1.GetRank());
			Assert::AreEqual(12, Card2.GetRank());


		}

		TEST_METHOD(CardClass2)
		{
			Deck deck;

			Card Card1 = Card(9);
			Card Card2 = Card(10);


			Assert::AreNotEqual(2, Card1.GetRank());
			Assert::AreNotEqual(1, Card2.GetRank());

		}

		TEST_METHOD(CardClass3)
		{
			Deck Deck;

			//Checking to make sure cards cannot be out of 1-13.
			Card Card1 = Card(69);
			Assert::AreNotSame(69, Card1.GetRank());

			Card Card2 = Card(-69);
			Assert::AreNotSame(69, Card2.GetRank());
		}

		TEST_METHOD(DeckClass)
		{
			// Card* Card1 = new Card(1);
			// Deck Deck1;
			// Assert::AreEqual(Card1, Deck1.Front());


		}

		TEST_METHOD(PlayerClass)
		{
			Game game1;
			Player player1 = "Chris";
			Player player2 = "Derek";

			//Checking for player names matching and not matching respectively. 
			Assert::AreEqual(std::string("Chris"), player1.GetName());
			Assert::AreNotEqual(std::string("Derekk"), player2.GetName());

			Card* tempPlayer1 = game1.GetTopOfPile();
			game1.GetPlayer(1)->AddCardToHand(game1.PullFromTopofPile());
			Assert::AreSame(tempPlayer1->GetRankString(), game1.GetPlayer(1)->ShowHandString());
			
			/*Checking for players pulling the correct card and outputting the correct 
			string from private vector */
			//Assert::AreEqual(, player1.ShowHandString());
			// Assert::AreNotEqual(std::string("4"), player2.ShowHandString());


			// Assert::IsTrue((bool)"Chris", (bool)player1.~Player());
		}

		/*TEST_METHOD(GameClass)
		{
			Game game;
			Deck deck;
			Card card1 = Card(1);
			//Player player1;
			// Player player2;

		}*/
	};
}
