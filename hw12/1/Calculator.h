#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>

#define TYPE_NUMBER 0
#define TYPE_OPERATOR 1

using namespace std;

struct Element {
    int type;
    double number;
    char op;
};

//Calculator class: handles input, conversion, evaluation
class Calculator {
public:
    void run();//Start calculator

private:
    string getInput();//Get input
    string infixToPostfix(const string&);//Convert to postfix
    double evaluatePostfix(const string&);//Calculate result
    int getPrecedence(char op);//Operator precedence
    bool isOperator(char c);//Check operator
};

#endif