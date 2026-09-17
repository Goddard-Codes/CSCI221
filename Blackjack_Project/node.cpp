/*
    Author: Evan Goddard
    Purpose: Final Project
    Date: 12/4/2025 - 12/15/2025
*/
#include <cstddef>
#include "node.hpp"

Node::Node(Card cn) {
        c = cn; //the initialized data is set as the head
        next = nullptr; //the next node is set as NULL, as there is no next node yet.
        }

        Card Node::getData() { //function that return data of a given node.
                return c;
        }
        Node::~Node() {
                next = nullptr;
        }
        Node * Node::getNext() { // pointer that gets the next node
                return next;
        }

        void Node::setData(Card cn) { // sets data in node
                c = cn;
        }

        void Node::setNext(Node *newnext) {
                next = newnext;
        }
