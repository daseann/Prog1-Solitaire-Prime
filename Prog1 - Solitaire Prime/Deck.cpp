#include "Deck.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include<time.h>
using namespace std;
Deck::Deck()
{
	char rank[] = { 'A','2','3','4','5','6','7','8','9','T','J','Q','K' };
	char suit[] = { 'S','H','D','C' };
	index = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			storage[index++].setCard(rank[j], suit[i]);
		}
	}
}

void Deck::refreshDeck()
{
	char rank[] = { 'A','2','3','4','5','6','7','8','9','T','J','Q','K' };
	char suit[] = { 'S','H','D','C' };
	index = 0;
	top = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			storage[index++].setCard(rank[j], suit[i]);
		}
	}
}

Card Deck::deal()
{
	if (top < 52)
		return storage[top++];
	else
		return Card();
}

void Deck::shuffle()
{
	srand(time(0));
	for (int i = 0; i < 5000; i++)
	{
		int x = rand() % 52;
		int y = rand() % 52;
		Card temp = storage[x];
		storage[x] = storage[y];
		storage[y] = temp;
	}

}

int Deck::CardsLeft()
{
	return 52 - top;
}

void Deck::showDeck()
{
	index = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			storage[index++].showCard();
			cout << " ";
		}
		cout << endl;
	}
}
