//Charlie Truong
//CECS 282-01
//Prog 1 - Solitaire Prime
// September 13th, 2021
// I certify that this program is my own original work. I did not copy any part of this program from 
// any other source. I further certify that I typed each and every line of code in this program.
#include "Card.h"
#include "Deck.h"
#include <string>
#include<iostream>
using namespace std;
bool isPrime(int);
int main() {
	Deck myDeck;
	int count = 0;
	int sum = 0;
	int option;
	cout << "Welcome to Solitaire Prime!\n";
	while (true) {
		cout << "\n1)  New Deck\n";
		cout << "2)  Display Deck\n";
		cout << "3)  Shuffle Deck\n";
		cout << "4)  Play Solitaire Prime\n";
		cout << "5)  Exit\n";
		cout << "What operation do you wish to perform?    ";
		cin >> option;
		if (option == 1) {
			myDeck.refreshDeck();
		}
		else if (option == 2) {
			myDeck.showDeck();
		}
		else if (option == 3) {
			myDeck.shuffle();
		}
		else if (option == 4) {
			cout << "\nPlaying Solitaire Prime!!!\n\n";
			for (int i = 0; i < 52; i++) {
				Card myCard = myDeck.deal();
				sum += myCard.getValue();
				myCard.showCard();
				if (isPrime(sum)) {
					cout << "Prime: " << sum << endl;
					sum = 0;
					count++;
					continue;
				}
				else {
					continue;
				}
			}
			if (sum == 0) {
				cout << "Winner in " << count << " piles!";
			}
			else {
				cout << "Loser";
			}
			count = 0;
			sum = 0;
			cout << endl;
		}
		else if (option == 5) {
			return false;
		}
		else {
			cout << "Invalid option. Enter one of the two options:  ";
			cin >> option;
		}
	}

	getchar();
	getchar();
	return 0;

}
bool isPrime(int x) {
	if (x == 1)
		return false;
	else {
		if (x % 2 == 0) {
			return false;
		}
		for (int i = 3; i * i <= x; i += 2) {
			if (x % i == 0) {
				return false;
			}
			return true;
		}
	}
}