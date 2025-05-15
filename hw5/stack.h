#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int* data;//Array to hold int data
    int top;//Top index of current stack
    int maxsize;//Maximum stack size

public:
    Stack(int size);//Constructor
    ~Stack();//Destructor

    void Push(int value);//Stack push
    int Pop();//Stack pop
    void Print();//Stack print
};

#endif