//	LinkedBag340.cpp
//	Created by: CSC340

#include "LinkedBag.h"
#include <random>
#include <string>
#include <stdexcept>
#include <functional>

using namespace std;

// Function designed to remove the second node in the linked bag, this is done through
// checking if the second node actually exists, and deleting it if it exists.  
template<typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340() {

    Node<ItemType>* second = headPtr->getNext();
    headPtr->setNext(second->getNext());

    delete second;
    second = nullptr;

    itemCount--;
    return true;

}

// Function designed to add an item to the end of the linked bag, takes in a constant
// ItemType reference.  
template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& item) {

    Node<ItemType>* temp = new Node<ItemType>(item);

    Node<ItemType>* current = headPtr;

    while (current->getNext() != nullptr) {

        current = current->getNext();

    }

    current->setNext(temp); 

    itemCount++;
    return true;

}

// Function designed to get the current size of the linked bag through iteration, no helper
// function is required for this task.  
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const {

    int count = 0;
    Node<ItemType>* current = headPtr;

    while (current != nullptr) {

        count++;
        current = current->getNext();

    }

    return count;

}

// Initialization of helper function which takes in a Node<ItemType> pointer to be used from the
// head pointer to get the current size of the bag
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>* node) const {

    if (node == nullptr) { return 0; }

    return 1 + getCurrentSize340RecursiveHelper(node->getNext());

}

// Retrieves the current size recursively of the linked bag using a function call of the helper
// function
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {

    return getCurrentSize340RecursiveHelper(headPtr);

}

// getCurrentSize340RecursiveNoHelper uses a lambda expression to perform recursion to get
// the size of the LinkedBag.  
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {

    function<int(Node<ItemType>*)> numFunc = [&](Node<ItemType>* node) {

        if (node == nullptr) { return 0; }

        return 1 + numFunc(node->getNext());

    };

    return numFunc(headPtr);

}

// Initialization of helper function which takes in a Node<ItemType> pointer to be used from the
// head pointer, as well as a constant ItemType reference variable, to get the frequency of 
// items inside of the bag.  
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>* node, const ItemType& item) const {

    if (node == nullptr) { return 0; }

    int num = (node->getItem() == item) ? 1 : 0;
    return num + getFrequencyOf340RecursiveHelper(node->getNext(), item);

}

// Retrieves the frequency of items in the bag recursively using a function call to the helper 
// function.  
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& item) const {

    return getFrequencyOf340RecursiveHelper(headPtr, item);

}

// getFrequencyOf340RecursiveNoHelper takes in a constant ItemType reference of name item
// and uses a lambda expression to perform recursion to get the frequency of the items in
// the LinkedBag.  
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType& item) const {

    function<int(Node<ItemType>*)> numFunc = [&](Node<ItemType>* node) {

        if (node == nullptr) { return 0; }

        int num = (node->getItem() == item) ? 1 : 0;
        return num + numFunc(node->getNext());

    };

    return numFunc(headPtr);

}

// Uses functions from the random library to create a random integer which is in range, 
// as well as using iteration to remove a random node from the linked bag.  
template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340() {

    // Initialize the random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, itemCount - 1);

    // Uses index to generate a random integer that falls in the range of the list
    int index = dis(gen);

    Node<ItemType>* current = headPtr;
    Node<ItemType>* previous = nullptr;

    for (int i = 0; i < index; ++i) {

        previous = current;
        current = current->getNext();

    }

    ItemType item = current->getItem();

    if (previous == nullptr) { headPtr = current->getNext(); }
    else { previous->setNext(current->getNext()); }

    // Cleanup
    delete current;
    current = nullptr;
    
    itemCount--;
    return item;

}

template class LinkedBag<int>;
template class LinkedBag<double>;
template class LinkedBag<string>;