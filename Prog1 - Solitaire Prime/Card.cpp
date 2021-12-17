#include <iostream>
#include "Card.h"
#include <string>
#include <iostream>
using namespace std;
Card::Card()
{
	suit = 'X';
	rank = 'X';
}
Card::Card(char r, char s) {
	suit = s;
	rank = r;
}
void Card::setCard(char r, char s) {
	suit = s;
	rank = r;
}
void Card::showCard() {
	string a = "";
	if (rank == 'A')
		a += " A";
	else if (rank == 'K')
		a += " K";
	else if (rank == 'Q')
		a += " Q";
	else if (rank == 'J')
		a += " J";
	else if (rank == 'T')
		a += "10";
	else
		a += " " + to_string((int)rank - 48);
	if (suit == 'S')
		a += "S";
	else if (suit == 'D')
		a += "D";
	else if (suit == 'H')
		a += "H";
	else if (suit == 'C')
		a += "C";
	cout << "<" << a << ">  ";

}
int Card::getValue() {
	if (rank == 'A')
		return 1;
	else if (rank == 'T' || rank == 'K' || rank == 'Q' || rank == 'J')
		return 10;
	else
		return (int)rank - 48;
}