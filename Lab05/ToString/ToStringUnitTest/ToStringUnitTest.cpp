#include "pch.h"
#include "CppUnitTest.h"
#include "../ToStringDLL/ToStringDLL.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ToStringTest
{
	TEST_CLASS(ToStringUnitTest)
	{
	public:
		TEST_METHOD(CardClass)
		{
			//Creating the cards with specific ranks
			Card card1 = Card(2);
			Card card2 = Card(12);
			Card card3 = Card(4);

			//Testing to see if the cards return the correct ranks
			Assert::AreEqual(2, card1.GetRank());
			Assert::AreEqual(12, card2.GetRank());
			Assert::AreNotEqual(23, card3.GetRank());
		}

		TEST_METHOD(DeckClass)
		{
			Deck deck;

			//When the deck creates the cards they are ordered 1 to 13 and repeated up to 52
			Assert::AreEqual(1, deck.CardAt(0)->GetRank());
			Assert::AreEqual(13, deck.CardAt(12)->GetRank());
			Assert::AreNotEqual(13, deck.CardAt(1)->GetRank());
		}

		TEST_METHOD(PlayerClass)
		{
			Deck Deck;
			Player player1 = "Chris";
			Player player2 = "Derek";

			//Checking for player names matching and not matching respectively. 
			Assert::AreEqual(std::string("Chris"), player1.GetName());
			Assert::AreNotEqual(std::string("Derekk"), player2.GetName());

			player1.AddCardToHand(Deck.CardAt(0));
			player2.AddCardToHand(Deck.CardAt(0));

			//Checking for players pulling the correct card and outputting the correct 
			//string from private vector
			Assert::AreEqual(std::string("Hand: 1"), player1.ShowHand());
			Assert::AreNotEqual(std::string("Hand: 4"), player2.ShowHand());
		}

		TEST_METHOD(GameClass)
		{
			Game game;

			//Get a copy of the card from the top
			Card* card = game.GetTopOfPile();

			//Check to see if the copy is equal to the function that actually pulls the card from the top
			Assert::AreEqual(card->GetRank(), game.PullFromTopofPile()->GetRank());
		}
	};
}
