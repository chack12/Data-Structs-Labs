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

			//Checking for cards pulled to be equal.

			Card Card1 = Card(2);
			Card Card2 = Card(12);
			Assert::AreEqual(2, Card1.GetRank());
			Assert::AreEqual(12, Card2.GetRank());

			//Checking for cards pulled not equal

			Card Card3 = Card(9);
			Card Card4 = Card(10);
			Assert::AreNotEqual(2, Card3.GetRank());
			Assert::AreNotEqual(1, Card4.GetRank());
			

			//Checking to make sure cards cannot be out of 1-13.
			Card Card5 = Card(69);
			Card Card6 = Card(-69);
			Assert::AreNotSame(69, Card5.GetRank());
			Assert::AreNotSame(69, Card6.GetRank());
		}

		TEST_METHOD(DeckClass)
		{
			// Deck Deck1;
			//Assert::AreEqual(Deck1.Front()->GetRank());
		}

		TEST_METHOD(PlayerClass)
		{
			Game game1;
			Player player1 = "Chris";
			Player player2 = "Derek";

			//Checking for player names matching and not matching respectively. 
			Assert::AreEqual(std::string("Chris"), player1.GetName());
			Assert::AreNotEqual(std::string("Derekk"), player2.GetName());
			
			/*Checking for players pulling the correct card and outputting the correct 
			string from private vector */
			Card* tempPlayer1 = game1.GetTopOfPile();
			game1.GetPlayer(1)->AddCardToHand(game1.PullFromTopofPile());
			Assert::AreSame(tempPlayer1->GetRankString(), game1.GetPlayer(1)->ShowHandString());
			player1.~Player();
			player2.~Player();
			game1.~Game();

		}

		TEST_METHOD(GameClass)
		{

			Game game;
			Player* player1 = game.GetPlayer(1);
			Player* player2 = game.GetPlayer(2);

			player1->AddCardToHand(game.PullFromTopofPile());
			player2->AddCardToHand(game.PullFromTopofPile());


			//Checking that card was actually added to top of hand.
			Assert::IsTrue(player1->GetHandSize() > 0);
			Assert::IsFalse(player2->GetHandSize() > 1);

		}
	};
}
