#include <iostream>
#include "stack.h"

using namespace std;

Stack::Stack(int size) {//Constructor(Stack Initialization)
    max_size = size;
    stack = new Element[max_size];
    top = -1;
}

Stack::~Stack() {//Destructor(Frees dynamically allocated array memory)
    delete[] stack;
}

void Stack::Push(Element item) {//Push(Add a value to the stack)
    if(IsFullS()) {
        cout << "Stack is full" << endl;
        return;
    }
    stack[++top] = item;
}

Element Stack::Pop() {//Pop(Return and remove the top value)
    if(IsEmptyS()) {
        cout << "Stack is empty" << endl;
        return (Element)0;
    }
    return stack[top--];
}

void Stack::Print() const {//Print all values in the stack
    if(IsEmptyS()) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack Data" << endl;
    for(int i = 0; i <= top; i++) {
        cout << i + 1 << ": " << stack[i] << endl;
    }
}

bool Stack::IsFullS() const {//Stack full check
    return (top == max_size - 1);
}

bool Stack::IsEmptyS() const {//Stack empty check
    return (top == -1);
}