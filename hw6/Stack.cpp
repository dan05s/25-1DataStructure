#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor: allocate memory and initialize top index
Stack::Stack(int size) {
    capacity = size;
    data = new Element[capacity]; // Allocate memory for stack
    topIndex = -1;                // Stack starts empty
}

// Destructor: free allocated memory
Stack::~Stack() {
    delete[] data;
}

// Push an element onto the stack
void Stack::push(Element value) {
    if (isFull()) {
        cout << "Stack is full" << endl;
        return;
    }
    data[++topIndex] = value; // Place value and move top index up
}

// Pop the top element and return it
Element Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        exit(1); // Exit if stack is empty
    }
    return data[topIndex--]; // Return and remove top
}

// Return the top element without removing it
Element Stack::top() const {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        exit(1); // Exit if stack is empty
    }
    return data[topIndex];
}

// Check if stack has no elements
bool Stack::isEmpty() const {
    return topIndex == -1;
}

// Check if stack is full
bool Stack::isFull() const {
    return topIndex == capacity - 1;
}