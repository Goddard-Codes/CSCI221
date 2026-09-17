/*
    Author: Evan Goddard
    Date: 12/1/25 - 12/15/25
    Purpose: Final Project
*/



#ifndef _CARD_H_
#define _CARD_H_

#include <iostream>
#include <string>
using namespace std;
class Card {
	private:
		string rank;
		char suit;
		int sortVal;
		int rankVal(); // private because this is only a helper method for sortval
	
	public:
		Card();
		Card(string face_val, char suit);
		
		void setSuit(char s);
		
		void setRank(string r);
		
		string getRank();
		
		char getSuit();
		
		int getFaceVal();
		
		
		void displayCard();

		int getsortVal();

};

#endif