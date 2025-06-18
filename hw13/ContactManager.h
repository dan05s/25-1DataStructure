#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include <string>
#include <vector>
#include "person.h"
#include "bst.h"

using std::string;
using std::vector;

class ContactManager {
private:
    vector<Person*> persons;//Stores all contacts in a list (vector of pointers)
    BST bstByName;//BST to search/sort contacts by name
    BST bstByBirthday;//BST to search/sort contacts by birthday

public:
    ContactManager();//Constructor
    ~ContactManager();//Destructor

    bool load(const string& filename);//Load contacts from a file
    bool save(const string& filename);//Save contacts to a file

    bool insert(Person* person);//Add a new contact
    bool removeByName(const string& name);//Remove contact by name
    bool removeByBirthday(const string& birthday);//Remove contact by birthday

    Person* retrieveByName(const string& name);//Find contact by name
    Person* retrieveByBirthday(const string& birthday);//Find contact by birthday

    void printByName();//Print all contacts sorted by name
    void printByBirthday();//Print all contacts sorted by birthday
};

#endif