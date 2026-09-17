/*
    Author: Evan Goddard
    Date: 12/1/25 - 12/15/25
    Purpose: Final Project
*/

#ifndef _DECK_H_
#define _DECK_H_

#define SIZE 52
#define SUIT 4
#define RANK 13

#include "card.hpp"
#include <vector>

class Deck {
    private:
        vector<Card> deck;
        int remaining;
        char suits[SUIT] = {'S','C','D','H'};
        string rank[RANK] = {"1","2","3","4","5","6","7","8","9","10", "J", "Q", "K"};
        void sortDeckOrder(vector<Card> &v, int left, int right);
    public:
        Deck();
        int getRemaining();
        void shuffle();
        Card deal();
        void callsort();
        void printDeck(); 


};

#endif 