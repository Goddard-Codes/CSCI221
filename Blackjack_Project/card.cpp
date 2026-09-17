/*
    Author: Evan Goddard
    Date: 12/1/25 - 12/15/25
    Purpose: Final Project
*/
#include "card.hpp"

int Card::rankVal() {
	if (rank == "10") {
		return 10;
	}
	char r0 = rank.at(0); // convert the rank to char to do ASCII comparison
	if (r0 > 47 && r0 < 58) {
		return r0 - '0';
	}
	else if (r0 == 'J') {
		return 11;
	}
	else if (r0 == 'Q') {
		return 12;
	}
	return 13;
	
}
// unused because of deck costructor
Card::Card() {
	rank = "";
	suit = '\0';
}
		
		// no error checking .... yet
		Card::Card(string face_val, char suit) {
			rank = face_val;
			this->suit = suit;
			sortVal = this->getsortVal(); 
		}

		void Card::setSuit(char s) {
			suit = s;
		}
		
		void Card::setRank(string r) {
			rank = r;
		}
		
		string Card::getRank() {
			return rank;
		}
		
		char Card::getSuit() {
			return suit;
		}
		
		int Card::getFaceVal() {
			if (rank == "J") 
				return 10;
			else if (rank == "Q") 
				return 10;
			else if (rank == "K")
				return 10;
			else if (rank == "1") 
				return 11;
			else
				return stoi(rank);
		}
		
		
		void Card::displayCard() {
			if (rank == "1") {
				cout << "A of ";
			} else {
				cout << rank << " of "; 
			}
			cout << suit << endl;
		}

		int Card::getsortVal() { // sorts cards in the following order A-K seperated by suit. Suit order: first spades, second clubs, third diamonds, fourth hearts
			int i;
			if (suit == 'S'){
				i = 0;
			}
			else if (suit == 'C') {
				i = 1;
			}
			else if (suit == 'D') {
				i=2;
			}
			else  {
				i=3;
			}
			int j = this->rankVal();
			return (i *13) + j;
		}
