#include "Calculator.h"
#include <iostream>
#include <sstream>
#include <cctype>
#include <stack>

using namespace std;

//Main method to run the calculator
void Calculator::run() {
    string infix = getInput();              //Step 1: Get infix expression from user
    string postfix = infixToPostfix(infix); //Step 2: Convert infix to postfix
    double result = evaluatePostfix(postfix);//Step 3: Evaluate postfix expression
    cout << "Result: " << result << endl;   //Step 4: Print the result
}

//Get input expression from user
string Calculator::getInput() {
    string expr;
    cout << "Enter an expression: ";
    getline(cin, expr);//Read the whole line, including spaces
    return expr;
}

//Convert an infix expression to postfix (Reverse Polish Notation)
string Calculator::infixToPostfix(const string& infix) {
    stack<Element> opStack;//Stack for operators(use STL)
    string postfix = "";//Resulting postfix expression
    istringstream iss(infix);//Used to read one character at a time
    char token;

    while (iss >> token) {//Read each character (token)
        if (isdigit(token) || token == '.') {// If the token is part of a number, add it to postfix

            postfix += token;

            
            if (iss.peek() != '.' && !isdigit(iss.peek()))//If the next character is not digit or dot, add space (number ends)
                postfix += ' ';
        }
        else if (token == '(') {//Push '(' to the stack
            Element e;
            e.type = TYPE_OPERATOR;
            e.op = '(';
            opStack.push(e);
        }
        else if (token == ')') {
            //Pop operators from the stack until '(' is found
            while (!opStack.empty() && opStack.top().op != '(') {
                postfix += opStack.top().op;
                postfix += ' ';
                opStack.pop();
            }
            if (!opStack.empty()) opStack.pop();//Discard the '('
        }
        else if (isOperator(token)) {//Pop higher or equal precedence operators before pushing the new one
            while (!opStack.empty() &&
                   getPrecedence(opStack.top().op) >= getPrecedence(token)) {
                postfix += opStack.top().op;
                postfix += ' ';
                opStack.pop();
            }

            //Push current operator
            Element e;
            e.type = TYPE_OPERATOR;
            e.op = token;
            opStack.push(e);
        }
    }

    //Pop any remaining operators
    while (!opStack.empty()) {
        postfix += opStack.top().op;
        postfix += ' ';
        opStack.pop();
    }

    return postfix;
}

//Evaluate a postfix expression and return the result
double Calculator::evaluatePostfix(const string& postfix) {
    stack<Element> valStack;//Stack to store numbers(Use STL)
    istringstream iss(postfix);//Used to read tokens (numbers or operators)
    string token;

    while (iss >> token) {//Read each token
        if (isdigit(token[0]) || (token[0] == '-' && token.length() > 1)) {//If the token is a number, convert to double and push
            Element e;
            e.type = TYPE_NUMBER;
            e.number = stod(token);//stod = string to double
            valStack.push(e);
        }
        else if (isOperator(token[0])) {//If it's an operator, pop two operands
            double b = valStack.top().number; valStack.pop();//Right operand
            double a = valStack.top().number; valStack.pop();//Left operand
            double result = 0;

            //Perform the operation
            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            //Push the result back to the stack
            Element e;
            e.type = TYPE_NUMBER;
            e.number = result;
            valStack.push(e);
        }
    }

    //Final result is the only value on the stack
    return valStack.top().number;
}

//Return precedence of operator: higher value = higher precedence
int Calculator::getPrecedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

//Check if a character is a valid operator
bool Calculator::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}