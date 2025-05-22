#include <iostream>
#include <fstream>
#include "Stack.h"
using namespace std;

int main() {
    string fname;
    cout << "Enter file name: ";//Ask user to enter the input file name
    cin >> fname;

    ifstream fin;
    fin.open(fname.c_str());//Open the file with the given name

    if(fin.fail()){//Check if the file failed to open
        cout << "Cannot open file." << endl;
        return 1;
    }

    Stack s;//This creates an empty stack. The constructor initializes the top pointer to null, indicating that the stack has no elements yet.
    string line;

    while(getline(fin, line)){//Read each line from the file

        //Find the positions of the first and second commas
        int c1 = line.find(',');
        int c2 = line.find(',', c1 + 1);

        if(c1 == -1 || c2 == -1){//Skip lines that don't have two commas
            continue;
        }

        //Extract name, id, and email from the line
        string name = line.substr(0, c1);
        string id = line.substr(c1 + 1, c2 - c1 - 1);
        string email = line.substr(c2 + 1);

        s.push(name, id, email);//Push the extracted data onto the stack
    }

    fin.close();//Close the file after reading

    while(!s.isEmpty()){//Pop and print each item from the stack in reverse order
        Node* p = s.pop();//Remove the top node first because the stack returns elements in reverse order
        cout << p->id << ", " << p->name << ", " << p->email << endl;
        delete p;//Free memory of the popped node
    }

    return 0;
}