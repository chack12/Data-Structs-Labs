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
	//TODO: Implement me !!
	throw "NIY";
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
	//TODO
}

int BlackJackHand::ScoreHand()
{
	//TODO
	return -1;
}


