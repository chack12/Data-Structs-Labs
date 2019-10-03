// ToStringDLL.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "ToStringDLL.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

//Returns the cards rank
int Card::GetRank() {
	return rank;
}

//Returns the card at the inputted index 
Card* Deck::CardAt(int index) {
	return deck[index];
}


//Returns the name of the player
std::string Player::GetName()
{
	return m_name;
}

//Adds the inputted card to the hand of the player
void Player::AddCardToHand(Card* card)
{
	m_listOfCards.push_back(card);
}

//Adds the card to the players stack
void Player::AddCardToStack(Card* card) {
	if (card->GetRank() == 1 || card->GetRank() - 1 == m_stackOfCards.back()->GetRank()) {
		m_stackOfCards.insert(m_stackOfCards.end(), card);
	}
}

//Gets the card assoicated with an input and removes it from the list
Card* Player::GetAndRemoveCard(int input) {
	for (int i = 0; i < m_listOfCards.size(); ++i) {
		if (m_listOfCards[i]->GetRank() == input) {
			Card* temp = m_listOfCards[i];
			m_listOfCards.erase(m_listOfCards.begin() + i);
			return temp;
		}
	}
}

//Shows the inputted card
Card* Player::GetCard(int input) {
	for (int i = 0; i < m_listOfCards.size(); ++i) {
		if (m_listOfCards[i]->GetRank() == input) {
			return m_listOfCards[i];
		}
	}

	Card* temp = new Card(0);

	return temp;
}

//Returns the size of the stack
int Player::GetStackSize() {
	return m_stackOfCards.size();
}

//Returns the card at the top of the stack
Card* Player::ShowTopOfStack() {
	Card* temp = m_stackOfCards[m_stackOfCards.size() - 1];
	return m_stackOfCards[m_stackOfCards.size() - 1];
}

//Returns the size of the hand
int Player::GetHandSize() {
	return m_listOfCards.size();
}

//Discards players deck
std::vector<Card*> Player::DiscardHand() {
	std::vector<Card*> tempListOfCards = m_listOfCards;

	m_listOfCards.clear();

	return tempListOfCards;
}

//Returns a string of what is in the hand
std::string Player::ShowHand() {
	std::stringstream ss;

	ss << "Hand: ";
	for (int i = 0; i < m_listOfCards.size(); ++i) {
		ss << m_listOfCards[i]->GetRank();
		ss << " ";
	}

	std::string temp = ss.str();
	temp.pop_back();

	return temp;
}

//Show the players stack
std::string Player::ShowStack() {
	std::stringstream ss;

	if (m_stackOfCards.size() == 0) {
		ss << "Stack: empty";

		return ss.str();
	}
	else {
		ss << "Stack: ";
		ss << "\n";

		for (int i = m_stackOfCards.size() - 1; i >= 0; --i) {
			ss << m_stackOfCards[i]->GetRank();
			ss << "\n";
		}

	}

	std::string temp = ss.str();
	temp.erase(temp.size() - 1, 1);

	return temp;
}

//Checks for win condition
bool Player::CheckForWin() {
	if (m_stackOfCards.size() == 13 && m_stackOfCards[12]->GetRank() == 13) {
		return true;
	}

	return false;
}

//Returns a card from the top of the pile
Card* Game::PullFromTopofPile() {
	Card* newCard = m_communityPile.front();
	m_communityPile.erase(m_communityPile.begin());
	return newCard;
}

//Adds discarded card to the bottom of the deck
void Game::PutToBottom(Card* card) {
	m_communityPile.push_back(card);
}

//Return the player
Player* Game::GetPlayer(int i) {
	if (i == 1) {
		return m_player1;
	}
	else {
		return m_player2;
	}
}

//Returns the card at the top of the community pile
Card* Game::GetTopOfPile() {
	return m_communityPile.front();
}


