// Lab01DLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Lab01DLL.h"


// This is the constructor of a class that has been exported.
// see Lab01DLL.h for the class definition
Card::Card(suit_t suit, int rank): m_suit(suit), m_rank(rank), m_dealt(false)
{
    
}


Deck::Deck()
{
	init_deck();
}

Card Deck::GetCard(int index)
{
	return m_deck[index];
}

Card Deck::GetCard(suit_t suit, int rank)
{
	// Checks to see if rank is between 1 and 13 and if the suit is between 0 and 3
	if ((rank < 14 && rank >= 1) && (suit < 4 && suit >= 0 )) {
		//Returns the correct card
		return Card(suit, rank);
	}
	else {
		//Throws an error for a card out of range
		throw "Card out of range";
	}
		
}

/**
* Initialize the deck so that all cards exist, and are not yet dealt.
*/
void Deck::init_deck() 
{
	int pos = 0;
	for (int s = 0; s < 4; s++) {
		for (int rank = 1; rank <= 13; rank++) 
		{
			m_deck.push_back(Card((suit_t)s, rank));
			pos++;
		}
	}
}

BlackJackHand::BlackJackHand()
{
	
}

void BlackJackHand::AddCard(Card c)
{
	//Adds the card to the hand
	m_hand.push_back(c);
}

int BlackJackHand::ScoreHand()
{
	//Initialize score to 0
	int score = 0;

	//For loop that loops through as many times as the size of the hand
	for (int i = 0; i < m_hand.size(); i++) {
		//If the card is a number card
		if (m_hand.at(i).GetRank() < 11 && m_hand.at(i).GetRank() != 1) {
			//Add the number value of the card to the score
			score += m_hand.at(i).GetRank();
		}
		//If the card is a face card
		else if (m_hand.at(i).GetRank() > 10) {
			//Add 10 to the score
			score += 10;
		}
		//If the card is an ACE
		else {
			//Add 11 to the score if the score doesn't go over 21
			if (score < 11) {
				//Add 11 to the score
				score += 11;
			}
			//Add 1 to the score if 11 would go over 21
			else{
				//Add 1 to the score
				score += 1;
			}
		}
	}

	//Check to see if the score is over 21
	if (score > 21) {
		//Return a -1 if the score is over 21
		return -1;
	}
	else {
		//If the score is valid return the score
		return score;
	}
}


