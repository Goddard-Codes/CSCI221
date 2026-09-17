/*
    Author: Evan Goddard
    Purpose: Final Project
    Date: 12/4/2025 - 12/15/2025
*/


#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <iostream>
#include "node.hpp"


using namespace std;

// Queue class
class Queue {
private:
    Node * head;
    Node * tail;
    int count;
    
public:
	// constructor
	// set the head and tail to appropriate valuess
    Queue();
    void reset();
    int getCount();
    // destructor .. delete all the nodes and recycle memory
    ~Queue();// destructor
        
    
    bool isEmpty();
    
    // you will need to create a new Node (see the node class in a separate file and use
    // the Node constructor just as we did when both classes were in the same file)
    void enqueue(Card cn);// enqueue
    
    // check to be sure the queue is not already empty!
    // returns the value in the head node, changes where head points,
    //  and deletes the memory used by the formerly first Node
    Card dequeue();

    // check to be sure the queue is not empty!    
    // returns the value in the head node
    // does not change the queue
    Card front();
    
    // error message if the queue is empty
    // otherwise, print the whole queue from head to tail
    void printQueue();
};

#endif // _QUEUE_H_
