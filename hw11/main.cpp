#include <iostream>
#include <string>
#include <cstring>
#include "contact.h"
using namespace std;

#define MAX_NUM 1000//Maximum number of contacts

Person inputPerson() {//Function to input a new Person from user input
    Person p;//Struct to hold contact information
    string name, dob, email, phone;

    cout << "Enter name: ";
    cin.ignore();//Clear any leftover newline from previous input
    getline(cin, name);//Read full name with spaces
    strcpy(p.name, name.c_str());

    cout << "Enter birthday (yyyymmdd): ";
    getline(cin, dob);//Birthday as a continuous 8-digit string
    //Extract year, month, and day from substring
    p.dob.year = stoi(dob.substr(0, 4));
    p.dob.month = stoi(dob.substr(4, 2));
    p.dob.day = stoi(dob.substr(6, 2));

    cout << "Enter email: ";
    getline(cin, email);
    strcpy(p.email, email.c_str());

    cout << "Enter phone number: ";
    getline(cin, phone);
    strcpy(p.phone, phone.c_str());

    return p;//Return the filled-in Person object
}

int main() {
    string file_name;//File name for loading contact data
    Contact* contacts = new Contact(MAX_NUM);//Create Contact object on heap
    //Load contacts from file
    cout << "File name of contact data: ";
    cin >> file_name;

    contacts->load(file_name);//Load data from file
    contacts->print();//Print loaded contacts

    int choice;//Menu selection variable
    while (true) {
        cout << "\nChoose an option:" << endl;
        cout << "1. Insert new contact" << endl;
        cout << "2. Delete contact by name" << endl;
        cout << "3. Search by name" << endl;
        cout << "4. Search by email" << endl;
        cout << "5. Sort by name" << endl;
        cout << "6. Sort by birthday" << endl;
        cout << "7. Print all contacts" << endl;
        cout << "8. Save to file" << endl;
        cout << "0. Exit" << endl;
        cout << "> ";
        cin >> choice;//Get user selection

        switch (choice) {
            case 1: {//Add a new contact
                Person newPerson = inputPerson();//Prompt user for new contact info
                contacts->insert(newPerson);//Add to the list
                break;
            }
            case 2: {//Delete a contact by name
                string name;
                cout << "Enter name to delete: ";
                cin.ignore();//Clear buffer
                getline(cin, name);//Get full name
                contacts->deleteByName(name);//Attempt deletion
                break;
            }
            case 3: {//Search for a contact by name
                string name;
                cout << "Enter name to search: ";
                cin.ignore();
                getline(cin, name);
                contacts->retrieveByName(name);//Search and display
                break;
            }
            case 4: {//Search for a contact by email
                string email;
                cout << "Enter email to search: ";
                cin.ignore();
                getline(cin, email);
                contacts->retrieveByEmail(email);//Search and display
                break;
            }
            case 5://Sort the contacts alphabetically by name
                contacts->sortByName();
                break;
            case 6://Sort the contacts by birthdate
                contacts->sortByBirthday();
                break;
            case 7://Display all contacts
                contacts->print();
                break;
            case 8: {//Save current contact list to a file
                string save_file;
                cout << "Enter filename to save: ";
                cin.ignore();
                getline(cin, save_file);
                contacts->save(save_file);//Save to file (with .txt auto-append)
                break;
            }
            case 0://Exit the program
                cout << "Exiting..." << endl;
                delete contacts;//Free dynamically allocated memory
                return 0;//Terminate program
            default://Handle invalid menu option
                cout << "Invalid option. Try again." << endl;
        }
    }
}