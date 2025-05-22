#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>

using namespace std;

struct Node {//Structure representing a single node in the stack
    string name;
    string id;
    string email;
    Node* next;//points to the node that was pushed before this one
};

class Stack {
private:
    Node* top;//pointer to the top node in the stack
public:
    Stack();//constructor
    ~Stack();//destructor to clean up memory
    void push(string name, string id, string email);//Push a new node with given data onto the stack
    bool isEmpty();//Check if the stack is empty
    Node* pop();//Pop the top node from the stack and return its pointer
};

#endif