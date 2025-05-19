//Constants for element type
#define TYPE_NUMBER 0
#define TYPE_OPERATOR 1

//Struct to store either a number or operator
struct Element {
    int type;
    double number;
    char op;
};

//Simple stack class for Element
class Stack {
private:
    Element* data;
    int topIndex;
    int capacity;

public:
    Stack(int size = 100);//Constructor
    ~Stack();//Destructor

    void push(Element value);//Add element
    Element pop();// Remove and return top
    Element top() const;//Return top without removing
    bool isEmpty() const;
    bool isFull() const;
};