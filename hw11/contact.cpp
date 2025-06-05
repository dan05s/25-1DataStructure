#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <fstream>
#include "contact.h"
#include <iostream>

using namespace std;

void Contact::load(string file_name){//Load contact data from a file into the array
    char c_str[1024];
    strcpy(c_str, file_name.c_str());

    ifstream fin(c_str);//Opening a file using c_str
    if(!fin.is_open()){//Print error message when file opening fails
        printf("Cannot open %s\n", c_str);
        return;
    }

    string line;
    while(getline(fin, line)){//Read line by line from a file
        if (line.empty()) continue;//Skip blank lines
        char buffer[256];//An array of strings to store one line
        strncpy(buffer, line.c_str(), sizeof(buffer));//Copy string to char*
        buffer[sizeof(buffer) - 1] = '\0';//Add NULL character at the end

        persons[total_num++] = str2person(trim(buffer));//Convert data to a Person structure and store it in an array
    }

    fin.close();//file close
}

void Contact::save(string filename) {//Save contact data to a file in specified format
    if (filename.size() < 4 || filename.substr(filename.size() - 4) != ".txt") {//Append ".txt" if not present
        filename += ".txt";
    }

    ofstream fout(filename);

    if (!fout.is_open()) {
        cout << "Cannot open file for writing: " << filename << endl;
        return;
    }

    for (int i = 0; i < total_num; ++i) {
        fout << persons[i].name << "; "
             << persons[i].dob.year;
        if (persons[i].dob.month < 10) fout << "0";
        fout << persons[i].dob.month;
        if (persons[i].dob.day < 10) fout << "0";
        fout << persons[i].dob.day << "; "
             << persons[i].email << "; "
             << persons[i].phone << endl;
    }

    fout.close();
    cout << "Contacts saved to " << filename << " successfully." << endl;
}

void Contact::insert(Person p) {//Insert a new contact into the list
    if (total_num >= capacity) {
        cout << "Contact list is full!" << endl;
        return;
    }

    for (int i = 0; i < total_num; ++i) {//Check for duplicate name
        if (strcmp(persons[i].name, p.name) == 0) {
            cout << "A contact with the same name already exists: " << p.name << endl;
            return;
        }
    }

    persons[total_num++] = p;
    cout << "Contact added: " << p.name << endl;
}

void Contact::deleteByName(string name) {//Delete a contact by name
    bool found = false;

    for (int i = 0; i < total_num; ++i) {
        if (name == persons[i].name) {
            for (int j = i; j < total_num - 1; ++j) {//Shift elements left to remove the target
                persons[j] = persons[j + 1];
            }
            total_num--;
            found = true;
            cout << "Contact deleted: " << name << endl;
            break;
        }
    }

    if (!found) {
        cout << "Contact not found: " << name << endl;
    }
}

void Contact::retrieveByName(string name) {//Search and display a contact by name
    bool found = false;

    for (int i = 0; i < total_num; ++i) {
        if (name == persons[i].name) {
            cout << "Contact found:" << endl;
            cout << "Name: " << persons[i].name << endl;
            cout << "Birthday: " 
                 << persons[i].dob.year;
            if (persons[i].dob.month < 10) cout << "0";
            cout << persons[i].dob.month;
            if (persons[i].dob.day < 10) cout << "0";
            cout << persons[i].dob.day << endl;
            cout << "Email: " << persons[i].email << endl;
            cout << "Phone: " << persons[i].phone << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Contact not found: " << name << endl;
    }
}

void Contact::retrieveByEmail(string email) {//Search and display a contact by email
    bool found = false;

    for (int i = 0; i < total_num; ++i) {
        if (email == persons[i].email) {
            cout << "Contact found:" << endl;
            cout << "Name: " << persons[i].name << endl;
            cout << "Birthday: "
                 << persons[i].dob.year;
            if (persons[i].dob.month < 10) cout << "0";
            cout << persons[i].dob.month;
            if (persons[i].dob.day < 10) cout << "0";
            cout << persons[i].dob.day << endl;
            cout << "Email: " << persons[i].email << endl;
            cout << "Phone: " << persons[i].phone << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Contact not found with email: " << email << endl;
    }
}

void Contact::sortByName() {//Sort contacts by name in ascending order
    for (int i = 0; i < total_num - 1; ++i) {
        for (int j = i + 1; j < total_num; ++j) {
            if (strcmp(persons[i].name, persons[j].name) > 0) {
                Person temp = persons[i];
                persons[i] = persons[j];
                persons[j] = temp;
            }
        }
    }
    cout << "Contacts sorted by name." << endl;
}

void Contact::sortByBirthday() {//Sort contacts by birthday
    for (int i = 0; i < total_num - 1; ++i) {
        for (int j = i + 1; j < total_num; ++j) {
            Date d1 = persons[i].dob;
            Date d2 = persons[j].dob;

            if (d1.year > d2.year ||
               (d1.year == d2.year && d1.month > d2.month) ||
               (d1.year == d2.year && d1.month == d2.month && d1.day > d2.day)) {
                Person temp = persons[i];
                persons[i] = persons[j];
                persons[j] = temp;
            }
        }
    }
    cout << "Contacts sorted by birthday." << endl;
}

void Contact::print(){//Print all contact information
    for(int i=0; i<total_num; ++i) {
        printf("[%s][%04d%02d%02d][%s][%s]\n",
            persons[i].name,
            persons[i].dob.year,
            persons[i].dob.month,
            persons[i].dob.day,
            persons[i].email,
            persons[i].phone
        );
    }
}

char* Contact::trim(char* s) {
    if (!s) return NULL;//Return if NULL
    while (isspace(*s)) s++;//Remove leading whitespace
    char* end = s + strlen(s) - 1;//Set pointer to end of string
    while (end > s && isspace(*end)) end--;
    *(end + 1) = '\0';
    return s;
}

Date Contact::str2date(char* str) {
    Date date;
    char temp[10];//Temporary array to store date information

    strncpy(temp, str, 4);//Copy 4-digit year from string
    temp[4] = '\0';
    date.year = atoi(temp);//Convert string to number and store year

    strncpy(temp, str + 4, 2);
    temp[2] = '\0';
    date.month = atoi(temp);

    strncpy(temp, str + 6, 2);
    temp[2] = '\0';
    date.day = atoi(temp);

    return date;
}

Person Contact::str2person(char* line) {
    Person p;
    char* token;
    int i = 0;

    token = strtok(line, ";");//Split strings based on semicolon
    while (token) {
        switch (i) {
            case 0: strcpy(p.name, trim(token)); break;
            case 1: p.dob = str2date(trim(token)); break;
            case 2: strcpy(p.email, trim(token)); break;
            case 3: strcpy(p.phone, trim(token)); break;
        }
        token = strtok(NULL, ";");//Move to next token
        i++;
    }
    return p;
}