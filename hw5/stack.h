#ifndef STACK_H
#define STACK_H

typedef int Element;

class Stack {
private:
    Element* stack;//Array to hold elements
    int top;//Top index of current stack
    int max_size;//Maximum stack size

public:
    Stack(int size);//Constructor
    ~Stack();//Destructor

    void Push(Element value);//Stack push
    Element Pop();//Stack pop
    void Print() const;//Stack data print
    bool IsFullS() const;//Stack full check
    bool IsEmptyS() const;//Stack empty check
};

#endif