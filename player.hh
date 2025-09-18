#pragma once

#include "cardDeck.hh"

class Player {
	Deck cards;

public:
	Player()
	{
	}

	~Player()
	{
		cards.~Deck();
	}

	Card playCard()
	{
		return cards.dealCard();
	}

	void takeCard(Deck deck)
	{
		Card card = deck.dealCard();
		cards.takeCard(card);
	}

	void printCards()
	{
		cards.printDeck();	
	}

};