#pragma once
#ifndef DECK_H
#define DECK_H
#include "Card.h"
class Deck {
private:
	Card storage[52];
	int top = 0;
	int index;
public:
	Deck();
	void refreshDeck();
	Card deal();
	void shuffle();
	int CardsLeft();
	void showDeck();
};
#endif 