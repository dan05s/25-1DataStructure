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
    vector<Person*> persons;
    BST bstByName;
    BST bstByBirthday;

public:
    ContactManager();
    ~ContactManager();

    bool load(const string& filename);
    bool save(const string& filename);

    bool insert(Person* person);
    bool removeByName(const string& name);
    bool removeByBirthday(const string& birthday);

    Person* retrieveByName(const string& name);
    Person* retrieveByBirthday(const string& birthday);

    void printByName();
    void printByBirthday();
};

#endif