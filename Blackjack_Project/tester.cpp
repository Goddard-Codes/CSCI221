/*
    Author: Evan A Goddard
    Date: 12/7/2025
    Purpose: Final project testing program
*/

#include "deck.hpp"
#include "node.hpp"
#include "card.hpp"
#include "queue.hpp"
#include "hand.hpp"
using namespace std;


int main() {
    Hand h = Hand();
    printf("Presort\n");
    Deck d = Deck();
    Card c = Card();
    c.setSuit('H');
    c.setRank("10");

    h.push_back(c);
    cout << "The amount of aces in the hand is " << h.get_ace() << endl;
    h.back().displayCard();
    cout << h.get_sum() << endl;
    Card cf = Card();
    cf.setRank("1");
    cf.setSuit('S');
    h.push_back(cf);
    cout << "Card added:" << endl;
    h.get_card(1).displayCard();
    h.decrement_10();
    cout << "The amount of aces in the hand is " <<  h.get_ace() << endl;
    cout << "The count is " << h.get_sum() << endl;
    
    Node n = Node(c);
    Queue q = Queue(); // constructors
    d.shuffle();
    d.printDeck();
    d.callsort(); // currently causes error
    printf("Postsort\n");
    d.printDeck();
    cout << "dealing" << endl;
    for (int i = 0; i < 53; i++) {
        try {
        q.enqueue(d.deal());
        }
        catch (const char *err) {
            cout << "Error, " << err; // should print once if deal works correctly
        }
    }
    cout << "attempting front when full\n";
    try {
        Card cn = q.front(); // should print once if deal works correctly
            cn.displayCard();
        }
        catch (const char *err) {
            cout << "Error, " << err; 
        }



    cout << "Checking print queue\n";
    q.printQueue();



    d.shuffle();
    cout << "Reshuffling\n";
    try {// should not give error since shuffle resets remaining to SIZE
        d.deal();
        }
        catch (const char *err) {
            cout << "Error, " << err;
        }


       //all queue methods here
    if (!q.isEmpty()) {
        cout << "isEmpty() works correctly when not empty\n";
    } 
    else {
        cout << "isEmpty() works incorrectly when not empty\n";
    }
    for (int i = 0; i < 53; i++) {
        try {
        q.dequeue();
        }
        catch (const char *err) {
            cout << "Error, " << err; // should print once if dequeue works correctly
        }
    }
    if (q.isEmpty()) {
        cout << "isEmpty() works correctly when empty\n";
    } 
    else {
        cout << "isEmpty() works incorrectly when empty\n";
    }
    cout << "attempting front when empty\n";
    try {
        Card cn1 = q.front(); 
            cn1.displayCard();
        }
        catch (const char *err) {
            cout << "Error, " << err; // should print once if dequeue works correctly
        }
    
    cout << c.getRank() << " of " << c.getSuit() << endl; // I am not testing irregular cases such as rank = 56 and suit = 'a' because the only time the card 
    //class is used is in the deck class which automatically creates Cards of regular suits and ranks
    c.displayCard();
    cout << c.getFaceVal() << endl;
    cout << c.getsortVal() << endl;
    // I am not testing irregular cases such as for node because it's only a helper class for queue
    n.getData().displayCard();
    if (n.getNext() == nullptr) {
        cout << "node class automatically sets next to nullptr good!\n";
    }
    Card cd = Card();
    cd.setSuit('C');
    cd.setRank("9");
    Node x = Node(cd);
    n.setNext(&x);
    cout << n.getNext() << endl; // should be a pointer
    n.getNext()->getData().displayCard(); // should display: 9 of C\n
    
    
    

    return 0;
}