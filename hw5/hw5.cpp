#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    Stack *stack = new Stack(5);//Create a stack with a maximum size of 5
    stack->Push(1);//Push 1 onto the stack
    stack->Push(3);//Push 2 onto the stack
    stack->Print();//Push 3 onto the stack

    cout << "Pop: " << stack->Pop() << endl;//Pop the top value from the stack and print it
    stack->Print();//Print contents of the stack after popping

    delete stack;//Free the dynamically allocated memory

    return 0;
}