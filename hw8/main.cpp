#include <iostream>
#include <sstream>
#include "BST.h"
using namespace std;

int main(){
    BST tree;//Create an empty Binary Search Tree
    string line;//To store user input line

    while(true){
        getline(cin,line);//Read a full line from user
        if(line.empty()){//Skip empty lines
            continue;
        }

        stringstream ss(line);//Convert line to stringstream to parse command
        char cmd;
        int key;
        string value;

        ss >> cmd;//Read the command character
        if(cmd == 'q'){
            break;
        }else if(cmd == 'a'){
            ss >> key >> value;
            tree.add(key,value);
        }else if(cmd == 'd'){
            ss >> key;
            tree.remove(key);
        }else if(cmd == 'p'){
            tree.print();//Print BST in-order
        }
    }
    return 0;
}