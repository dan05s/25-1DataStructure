#include "ContactManager.h"
#include <fstream>
#include <sstream>
using namespace std;

string trim(string s){//Remove leading and trailing spaces or tabs from a string
    while (s.length() > 0 && (s[0] == ' ' || s[0] == '\t')){
        s = s.substr(1);//Remove first character if it is space or tab
    }
    while (s.length() > 0 && (s[s.length() - 1] == ' ' || s[s.length() - 1] == '\t')){
        s = s.substr(0, s.length() - 1);//Remove last character if it is space or tab
    }

    return s;//Return trimmed string
}

bool ContactManager::load(const string& filename){//Load contacts from a file and build two BSTs: by name and by birthday
    ifstream infile(filename);//Open input file
    if(!infile.is_open()) return false;//Return false if file cannot be opened

    string line;
    while(getline(infile,line)){//Read file line by line
        if(line.empty()) continue;//Skip empty lines

        stringstream ss(line);
        string name, birthday, email, phone_num;
        //Extract fields separated by ';'
        if (!getline(ss, name, ';')) continue;
        if (!getline(ss, birthday, ';')) continue;
        if (!getline(ss, email, ';')) continue;
        if (!getline(ss, phone_num, ';')) continue;
        //Trim spaces and tabs from each field
        name = trim(name);
        birthday = trim(birthday);
        email = trim(email);
        phone_num = trim(phone_num);
        //Create a new Person object dynamically
        Person* person = new Person{name, birthday, email, phone_num};
        //Store pointer in vector
        persons.push_back(person);
        //Insert into BSTs with keys name and birthday
        bstByName.insert(name, person);
        bstByBirthday.insert(birthday, person);
    }
    infile.close();//Close the file
    return true;//Load successful
}

bool ContactManager::save(const string& filename){//Save all contacts from vector to a file
    ofstream outfile(filename);//Open output file
    if (!outfile.is_open()) return false;//Return false if file cannot be opened
    //Write each contact in the required format
    for (Person* person : persons) {
        outfile << person->name << "; "
                << person->birthday << "; "
                << person->email << "; "
                << person->phone_num << "\n";
    }

    outfile.close();//Close the file
    return true;//Save successful
}

bool ContactManager::insert(Person* person) {//Insert a new contact if not already existing (by name or birthday)
    if (person == nullptr) return false;//Check for null pointer
    if (bstByName.search(person->name) != nullptr || bstByBirthday.search(person->birthday) != nullptr) {//Check if name or birthday already exists in BSTs
        return false;//Duplicate found, insertion fails
    }
    //Add to vector and both BSTs
    persons.push_back(person);
    bstByName.insert(person->name, person);
    bstByBirthday.insert(person->birthday, person);

    return true;//Insertion successful
}

bool ContactManager::removeByName(const string& name) {//Remove a contact by name from vector and both BSTs
    Person* person = bstByName.search(name);//Find person by name
    if (person == nullptr) {
        return false;//Not found
    }
    string birthday = person->birthday;//Get birthday for second BST removal
    bstByName.remove(name);//Remove from BST by name
    bstByBirthday.remove(birthday);//Remove from BST by birthday
    for (int i = 0; i < (int)persons.size(); i++) {//Remove from vector and free memory
        if (persons[i] == person) {
            delete persons[i];//Delete dynamically allocated Person
            persons.erase(persons.begin() + i);//Remove pointer from vector
            break;
        }
    }
    return true;//Removal successful
}

bool ContactManager::removeByBirthday(const string& birthday) {//Remove a contact by birthday from vector and both BSTs
    Person* person = bstByBirthday.search(birthday);//Find person by birthday
    if (person == nullptr) {
        return false;
    }
    string name = person->name;//Get name for second BST removal
    bstByBirthday.remove(birthday);//Remove from BST by birthday
    bstByName.remove(name);//Remove from BST by name
    for (int i = 0; i < (int)persons.size(); i++) {//Remove from vector and free memory
        if (persons[i] == person) {
            delete persons[i];//Delete dynamically allocated Person
            persons.erase(persons.begin() + i);//Remove pointer from vector
            break;
        }
    }
    return true;//Removal successful
}

Person* ContactManager::retrieveByName(const string& name) {//Retrieve a Person pointer by name from BST
    Person* person = bstByName.search(name);
    return person;
}

Person* ContactManager::retrieveByBirthday(const string& birthday){//Retrieve a Person pointer by birthday from BST
    Person* person = bstByBirthday.search(birthday);
    return person;
}

void ContactManager::printByName() {//Print all contacts in order by name (inorder traversal of BST by name)
    bstByName.inorder();
}

void ContactManager::printByBirthday() {//Print all contacts in order by birthday (inorder traversal of BST by birthday)
    bstByBirthday.inorder();
}

ContactManager::ContactManager(){//Constructor
}

ContactManager::~ContactManager() {//Destructor
    for (Person* p : persons) {
        delete p;
    }
    persons.clear();
}