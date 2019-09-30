// ToString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>
#include <iostream>
#include <string>
#include <queue>
#include <vector>

class Card
{
public:
	//Card constructor
	Card(std::string mySuit, int myRank) {
		suit = mySuit;
		rank = myRank;
	}

	//Card deconstructor
	~Card() {}

	//Returns the cards rank
	int GetRank() const {
		return rank;
	}

	//Returns the cards suit
	std::string GetSuit() {
		return suit;
	}

private:
	std::string suit;
	int rank;
};

class Deck
{
public:
	//Deck constructor
	Deck() {
		std::string suits[4] = {"Heart", "Diamond", "Club", "Spade"};
		int ranks[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };

		for (int i = 0; i < 52; ++i) {
			deck.push(Card(suits[i / 13], ranks[i % 13]));
		}
	}

	//Returns the front card 
	Card* Front() {
		return &deck.front();
	}

	//Removes the top card from the deck (queue)
	void Pop() {
		deck.pop();
	}

private:
	std::queue<Card> deck;
};

class Player
{
public:
	//Player constructor
	Player(std::string name)
	{
		m_name = name;
	}

	//Returns the name of the player
	std::string GetName() const
	{
		return m_name;
	}

	//Player deconstructor
	virtual ~Player()
	{
		std::cout << "Deleting " << m_name << std::endl;

		for (int i = 0; i < m_stackOfCards.size(); ++i) {
			delete m_stackOfCards.front();
		}

		for (int i = 0; i < m_listOfCards.size(); ++i) {
			delete m_listOfCards.front();
		}
	}

	//Adds the inputted card to the hand of the player
	void AddCardToHand(const Card* card)
	{
		m_listOfCards.push_back(card);
	}

	//Adds the card to the players stack
	void AddCardToStack(const Card* card) {
		if (card->GetRank() - 1 == m_stackOfCards.front()->GetRank()) {
			m_stackOfCards.push_front(card);
		}
	}

	//Discards a card from the player's stack
	const Card* DiscardCard(const Card* card) {
		return card;
	}

	//Discards players deck
	std::list<const Card*> DiscardHand()	{
		return m_listOfCards;
	}

private:
	std::string m_name;
	std::list<const Card*> m_stackOfCards;
	std::list<const Card*> m_listOfCards;
};

class Game
{
public:
	//Game constructor
	Game()
	{
		m_player1 = new Player("Player1");
		m_player2 = new Player("Player2");

		//Add cards from the Deck to the masterCardList
		for (int i = 0; i < 52; ++i) {
			m_masterCardList.push_back(deck.Front());
			deck.Pop();
		}

		//Move cards from the masterCardList to the communityPile
		for (int i = 0; i < 52; ++i) {
			int position = rand() % m_masterCardList.size();
			m_communityPile.push_back(m_masterCardList[position]);
			m_masterCardList.erase(m_masterCardList.begin() + position);
		}
	}

	//Game deconstructor
	~Game()
	{
		delete m_player1;
		delete m_player2;
		
		for (Card* card : m_communityPile) {
			delete card;
		}
	}

	//Returns a card from the top of the pile
	Card* PullFromPile() {
		Card* newCard = m_communityPile.front();
		m_communityPile.erase(m_communityPile.begin());
		return newCard;
	}

	//Adds discarded card to the bottom of the deck
	void PutToBottom(Card* card) {
		m_communityPile.push_back(card);
	}

private:
	Player* m_player1;
	Player* m_player2;
	Deck deck;
	std::vector<Card*> m_communityPile;
	std::vector<Card*> m_masterCardList;
};


int main()
{
	std::list<const Player*> stackOfPeople;
	Player* p1 = new Player("Huey 1");
	Player* p2 = new Player("Louie 2");
	Player* p3 = new Player("Dewey 3");

	stackOfPeople.push_front(p1);
	stackOfPeople.push_front(p2);
	stackOfPeople.push_front(p3);

	for (const Player* p : stackOfPeople)
	{
		std::string name = p->GetName();
		std::cout << name << " " << std::endl;
	}
	std::cout <<  std::endl;


	std::list<const Player*> queueOfPeople;

	queueOfPeople.push_back(p1);
	queueOfPeople.push_back(p2);
	queueOfPeople.push_back(p3);

	for (const Player* p : queueOfPeople)
	{
		std::string name = p->GetName();
		std::cout << name << " " << std::endl;
	}

	std::cout << "calling pop methods" << std::endl;
	stackOfPeople.pop_front();
	queueOfPeople.pop_front();

	for (const Player* p : stackOfPeople)
	{
		std::string name = p->GetName();
		std::cout << name << " " << std::endl;
	}
	std::cout << std::endl;

	for (const Player* p : queueOfPeople)
	{
		std::string name = p->GetName();
		std::cout << name << " " << std::endl;
	}

	std::cout << "calling clear methods" << std::endl;
	stackOfPeople.clear();
	queueOfPeople.clear();
	std::cout << "calling delete" << std::endl;
	delete p1;
	delete p2;
	delete p3;

    return 0;
}

