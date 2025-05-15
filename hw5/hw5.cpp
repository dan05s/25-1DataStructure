#include <iostream>
#include "stack.h"

using namespace std;

int main() {//main function
    Stack *stack = new Stack(5);
    stack->Push(1);
    stack->Push(3);
    stack->Print();

    cout << "Pop: " << stack->Pop() << endl;
    stack->Print();

    delete stack;

    return 0;
}

Stack::Stack(int size){//Constructor(Stack Initialization)
    maxsize = size;
    data = new int[maxsize];
    top = -1;
}

Stack::~Stack() {//Destructor(Frees dynamically allocated array memory)
    delete[] data;
}


void Stack::Push(int value){//Push(Add a value to the stack)
    if(top >= maxsize -1){//If the stack is full
        cout << "Stack is full" << endl;
        return;
    }
    data[++top] = value;//Increment top and save value
}

int Stack::Pop(){//Pop(Return and remove the top value)
    if(top <= -1){//If the stack is empty
        cout << "Stack is empty" << endl;
        return -1;
    }
    return data[top--];//Decrease top after returning the value
}

void Stack::Print(){//Print all values ​​in the stack
    if(top <= -1){
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack Data" << endl;
    for(int i=0;i<top+1;i++){
        cout << i+1 << ": " << data[i] <<endl;
    }
}
