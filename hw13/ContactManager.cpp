#include "ContactManager.h"
#include <fstream>
#include <sstream>
using namespace std;

string trim(string s){
    while (s.length() > 0 && (s[0] == ' ' || s[0] == '\t')){
        s = s.substr(1);
    }
    while (s.length() > 0 && (s[s.length() - 1] == ' ' || s[s.length() - 1] == '\t')){
        s = s.substr(0, s.length() - 1);
    }

    return s;
}

bool ContactManager::load(const string& filename){
    ifstream infile(filename);
    if(!infile.is_open()) return false;

    string line;
    while(getline(infile,line)){
        if(line.empty()) continue;

        stringstream ss(line);
        string name, birthday, email, phone_num;

        if (!getline(ss, name, ';')) continue;
        if (!getline(ss, birthday, ';')) continue;
        if (!getline(ss, email, ';')) continue;
        if (!getline(ss, phone_num, ';')) continue;

        name = trim(name);
        birthday = trim(birthday);
        email = trim(email);
        phone_num = trim(phone_num);

        Person* person = new Person{name, birthday, email, phone_num};

        persons.push_back(person);
        bstByName.insert(name, person);
        bstByBirthday.insert(birthday, person);
    }
    infile.close();
    return true;
}

bool ContactManager::save(const string& filename){
    ofstream outfile(filename);
    if (!outfile.is_open()) return false;

    for (Person* person : persons) {
        outfile << person->name << "; "
                << person->birthday << "; "
                << person->email << "; "
                << person->phone_num << "\n";
    }

    outfile.close();
    return true;
}

bool ContactManager::insert(Person* person) {
    if (person == nullptr) return false;
    if (bstByName.search(person->name) != nullptr || bstByBirthday.search(person->birthday) != nullptr) {
        return false;
    }
    persons.push_back(person);
    bstByName.insert(person->name, person);
    bstByBirthday.insert(person->birthday, person);

    return true;
}

bool ContactManager::removeByName(const string& name) {
    Person* person = bstByName.search(name);
    if (person == nullptr) {
        return false;
    }
    string birthday = person->birthday;
    bstByName.remove(name);
    bstByBirthday.remove(birthday);
    for (int i = 0; i < (int)persons.size(); i++) {
        if (persons[i] == person) {
            delete persons[i];
            persons.erase(persons.begin() + i);
            break;
        }
    }
    return true;
}

bool ContactManager::removeByBirthday(const string& birthday) {
    Person* person = bstByBirthday.search(birthday);
    if (person == nullptr) {
        return false;
    }
    string name = person->name;
    bstByBirthday.remove(birthday);
    bstByName.remove(name);
    for (int i = 0; i < (int)persons.size(); i++) {
        if (persons[i] == person) {
            delete persons[i];
            persons.erase(persons.begin() + i);
            break;
        }
    }
    return true;
}

Person* ContactManager::retrieveByName(const string& name) {
    Person* person = bstByName.search(name);
    return person;
}

Person* ContactManager::retrieveByBirthday(const string& birthday){
    Person* person = bstByBirthday.search(birthday);
    return person;
}

void ContactManager::printByName() {
    bstByName.inorder();
}

void ContactManager::printByBirthday() {
    bstByBirthday.inorder();
}

ContactManager::ContactManager(){
}

ContactManager::~ContactManager() {
    for (Person* p : persons) {
        delete p;
    }
    persons.clear();
}