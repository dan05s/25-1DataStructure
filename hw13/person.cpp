#include "person.h"

Person::Person(){//Initialize all fields with empty strings
    name = "";
    birthday = "";
    email = "";
    phone_num = "";
}

Person::Person(string n, string b, string e, string p){//Initialize all fields with given values
    name = n;
    birthday = b;
    email = e;
    phone_num = p;
}