#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

struct Person{  
    string name;
    string birthday;
    string email;
    string phone_num;

    Person();//Constructor
    Person(string n, string b, string e, string p);//Full field initialization constructor
};

#endif