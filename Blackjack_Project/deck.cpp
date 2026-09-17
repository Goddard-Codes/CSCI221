/*
    Author: Evan Goddard
    Date: 12/1/25 - 12/15/25
    Purpose: Final Project
*/

#include "deck.hpp"


    Deck::Deck() {
        deck.reserve(SIZE);
        srand(time(0)); // seed rand
        for (int i =0; i < SUIT; i++) {
            for (int j = 0; j < RANK; j++) {
                deck[i*13+j].setSuit(suits[i]);
                deck[i*13+j].setRank(rank[j]);
            }
        }
    }

    int Deck::getRemaining() {
        return remaining;
    }

    void Deck::shuffle() { // O(n^2)
        remaining = SIZE;               //allows the game to be reset as well and all cards can be played with after
        vector<Card> v;
        v.reserve(SIZE);
        for (int i =0; i < SIZE; i++) {
            v.push_back(deck[i]);
        } // create a vector that is the same as the initial deck
        
        int c = 51;
        int place;
        while (c >= 0){
            place =  rand() % (c+1);
            deck[c] = v[place];
            v.erase(v.begin() + place);
            c--;
        } // take out items randomly and remove that item from the vector to get a random deck

        /*
        for (int i = SIZE -1; i >=0; i--) {
            int j = rand() % (i+1);
            int temp = deck[i];
            deck[i] = deck[j];
            deck[j] = temp;
        }
        */
    }

    Card Deck::deal() {
        if (remaining <= 0) {
            throw "the deck is already empty!\n";
        }
        Card c = deck[remaining-1];
        remaining--;
        return c;
    }

    void Deck::sortDeckOrder(vector<Card> &v, int left, int right) { // sortDeckOrder is implemented in merge sort fashion
        if (left < right) {
            int mid = left + (right - left)/2;
            sortDeckOrder(v, left, mid);
            sortDeckOrder(v, mid+1, right); // continue to split up the vector until there is only one item in the vector
        }
        else {
            return;
        }
        //else return??

        int mid = left + (right - left)/2; // is this needed
        int size_l= mid - left+1; //get sizes of the vectors about to be created
        int size_r = right-mid;
        vector<Card> lef(size_l), righ(size_r);

        for (int i = 0; i < size_l; i++) {
            lef[i] = v[left + i];
        }                                   // copy items into new vectors
        for (int k = 0; k < size_r; k++) {
            righ[k] = v[mid + 1 + k];
        }



        int i = 0;
        int j = 0;
        int k = left;
        while (i < size_l && j < size_r) { // copy back
            if (lef[i].getsortVal() < righ[j].getsortVal()) { // don't use <= because no equal sortvals 
                v[k] = lef[i]; 
                i++;
            }
            else {
                v[k] = righ[j];
                j++;
            }
            k++;
        }

        //now add back in straglers from the vector that gets finished last
        while (i < size_l) {
            v[k] = lef[i];
            k++;
            i++;
        }

        while (j < size_r) {
            v[k] = righ[j];
            k++;
            j++;
        }


    }
    void Deck::callsort() {
        //could add buffer to reduce memory down from O(nlogn) to O(1)
        this->sortDeckOrder(deck, 0, SIZE-1);
    }
    void Deck::printDeck() {
        for (int i = 0; i < SIZE; i++) {
            cout << deck[i].getRank() << " of " << deck[i].getSuit() << endl;
        }
    }