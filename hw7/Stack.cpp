#include "Stack.h"
#include <iostream>

Stack::Stack(){//Set top to null to represent an empty stack
    top = nullptr;
}

Stack::~Stack(){
    Node* current = top;
    while(current != nullptr){
        Node* next = current->next;//Save next node
        delete current;//Delete current node
        current = next;//Move to next
    }
    top = nullptr;
}

void Stack::push(string name, string id, string email){//Push a new node onto the stack
    Node* newNode = new Node;
    newNode->name = name;
    newNode->id = id;
    newNode->email = email;
    newNode->next = top;
    top = newNode;
}

Node* Stack::pop(){//Remove and return the top node from the stack
    if(isEmpty()){
        return nullptr;
    }

    Node* temp = top;
    top = top->next;
    return temp;
}

bool Stack::isEmpty(){//Check if the stack is empty by verifying that top is null
    return top == nullptr;
}