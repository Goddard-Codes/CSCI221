/*
    Author: Evan A Goddard
    Date: 12/14/25 - 12/15/25
    Purpose: Final Project
*/

#include "hand.hpp"
        
        Hand::Hand() {
            sum = 0;
            effective_aces = 0;
        }
        void Hand::push_back(Card c) {
            hand.push_back(c);
            if (c.getRank() == "1") {
                effective_aces++;
            }
            sum+= c.getFaceVal();
        } 
        void Hand::decrement_10() {
            if (effective_aces > 0) {
                effective_aces--;
                sum-=10;
            }
        }
        
        int Hand::get_ace() {
            return effective_aces;
        }
        int Hand::get_sum() {
            return sum;
        }
        Card Hand::get_card(int index) {
            return hand[index];
        }
        Card Hand::back() {
            return hand.back();
        }
