/*
    Author: Evan Goddard
    Purpose: Final Project
    Date: 12/4/2025 - 12/15/2025
*/
#ifndef _NODE_H_
#define _NODE_H_

// node.hpp for HW 18 ... holding integers
#include "card.hpp"
class Node {
    //defines integer data, and next as a pointer.
    private:
        Card c; //data each node
        Node *next; //pointer to the next node

    public:
        Node(Card cn); 
        ~Node();
        Card getData(); 

        Node *getNext(); 

        void setData(Card cn); 
        
        void setNext(Node *newnext); 
        
}; // end Node class


#endif // _NODE_H_
