//
// Created by Tushar Asthana  on 2/14/23.
//

#ifndef QUEUE_H
#define QUEUE_
#include "Node.h"
#include <iostream>

using std::cout, std::endl;

/*
 * Queue class
 * All Nodes will point to the Node below
 */
template<typename Object>
class Queue {
private:
    Node<Object>* front;
    Node<Object>* back;



public:
    // Constructor
    Queue() {
        // Start with an empty Queue
        front = nullptr;
        back = nullptr;
    }

    // De-constructor aka destructor
    // This method will automatically be called
    // at the end of the lifetime of the object
    ~Queue() {
        // Make sure no heap allocation
        while (front != nullptr) {
            dequeue();
        }
        cout << "" << endl;
        cout << "No memory leaks!" << endl;
    }

    // enqueue (add a value to the Queue)
    void enqueue(Object item) {
        // Store the item in a Node in heap memory
        Node<Object>* newNodePtr = new Node<Object>(item);
        // Have the new Node point to front
        // The new Node becomes front
        if (front == nullptr && back == nullptr)
        {
            front = newNodePtr;
            back = newNodePtr;
        }
        else
        {
            back->setNext(newNodePtr);
            back = newNodePtr;
        }
    }

    // dequeue (remove a value from the Queue)
    // Returns the value being popped
    Object dequeue() {
        // Check that there is a Node to dequeue
        if (front == nullptr) {
            // The Queue is empty
            return Object();
        }
        // Create a copy of the value to be returned
        Object item = front->getItem();
        // Store a copy of front
        Node<Object>* topCopy = front;
        // Update front
        front = front->getNext();
        // Delete the Node from heap memory
        delete topCopy;
        // Return the value being popped
        return item;
    }

    // Search for an item in the Queue
    // Return true if the item is in the Queue
    // Return false otherwise
    bool search(Object item) const {
        Node<Object>* topCopy = front;
        while (topCopy != nullptr) {
            if (topCopy->getItem() == item) {
                return true;
            }
            topCopy = topCopy->getNext();
        }
        return false;
    }

    // Print (list all the values in the Queue)
    void print() const {
        cout << "Front of Queue" << endl;
        cout << "____________" << endl;
        Node<Object>* topCopy = front;
        while (topCopy != nullptr) {
            cout << topCopy->getItem() << endl;
            topCopy = topCopy->getNext();
        }
        cout << "________________" << endl;
        cout << "Bottom of Queue" << endl;
    }
};

#endif
