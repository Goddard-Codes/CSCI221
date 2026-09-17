/*
    Author: Evan A Goddard
    Date: 12/4/2025 - 12/15/2025
    Purpose final project
*/
#include <cstddef>
#include "queue.hpp"
#include <iostream>


// note this is complete I will use this class to track card counting in typical fashion of blackjack
    Queue::Queue() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    // destructor .. delete all the nodes and recycle memory
    Queue::~Queue()// destructors
        {
            Node * n = head;
            Node * next = nullptr;
            while (n != nullptr) {
                next = n->getNext();
                delete n;
                n= next;
            }
            head = nullptr;
            tail = nullptr;
        }
    
    bool Queue::isEmpty() {
        if (head == nullptr)
        {
            return true;
        }
        return false;
    }
    int Queue::getCount() {
        return count;
    }
    // you will need to create a new Node (see the node class in a separate file and use
    // the Node constructor just as we did when both classes were in the same file)
    void Queue::enqueue(Card cn)// enqueue
    {
        Node * n = new Node(cn);
        if (n== nullptr) {
            throw "The new Node wasn't successfully created\n";
        }
        if (this->isEmpty()) {
            head = n;
            tail = n;
        }
        else {
            tail->setNext(n);
            tail = n;
        }
        string rank = cn.getRank();
        if (rank == "K" || rank == "Q" || rank == "J" || rank == "10" || rank == "1") {
            count --;
        }
        else if (rank == "2" || rank == "3" || rank == "4" || rank == "5" || rank == "6") {
            count ++;
        }



        
    }

    void Queue::reset() {
        while (!this->isEmpty()) {
            this->dequeue();
        }
        count = 0;
    }
    // check to be sure the queue is not already empty!
    // returns the value in the head node, changes where head points,
    //  and deletes the memory used by the formerly first Node
    Card Queue::dequeue() {
        if (head == nullptr) {
            throw "this is an empty queue!\n";
        }
        Card to_return = head->getData();
        Node * n = head;
        head = head->getNext();
        if (head == nullptr) {
            tail = nullptr;
        }
        delete n;
        return to_return;
    }

    // check to be sure the queue is not empty!    
    // returns the value in the head node
    // does not change the queue
    Card Queue::front() {
        if (this->isEmpty()) {
            throw "this is an empty queue\n";
        }
        return head->getData();
    }
    
    // error message if the queue is empty
    // otherwise, print the whole queue from head to tail

    void Queue::printQueue() { // uses queue traversal irregular but just for testing purposes
        Node * n = head;
        while (n != nullptr) {
            cout << n->getData().getRank() << " of " << n->getData().getSuit() << "\n";
            n = n->getNext();
        }
    }