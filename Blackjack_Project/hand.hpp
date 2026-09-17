/*
    Author: Evan A Goddard
    Date: 12/14/25 - 12/15/25
    Purpose: Final Project
*/

#ifndef _HAND_H_
#define _HAND_H_

#include "card.hpp"
#include <vector>

class Hand {
    private:
        vector<Card> hand;
        int sum;
        int effective_aces;
    public:
        Hand();
        void push_back(Card c);
        void decrement_10();
        int get_ace();
        int get_sum();
        Card get_card(int index);
        Card back();
};



#endif