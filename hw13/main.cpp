#include <iostream>
#include "ContactManager.h"

using namespace std;

int main() {
    ContactManager cm;

    while (true) {
        cout << "\n===== Contact Manager Menu =====\n";
        cout << "1. Load contacts from file\n";
        cout << "2. Save contacts to file\n";
        cout << "3. Insert new contact\n";
        cout << "4. Remove contact by name\n";
        cout << "5. Remove contact by birthday\n";
        cout << "6. Retrieve contact by name\n";
        cout << "7. Retrieve contact by birthday\n";
        cout << "8. Print contacts by name\n";
        cout << "9. Print contacts by birthday\n";
        cout << "0. Exit\n";
        cout << "Select option: ";

        int option;
        cin >> option;
        cin.ignore();

        if (option == 0) break;

        switch(option) {
            case 1: {
                string filename;
                cout << "Enter filename to load: ";
                getline(cin, filename);
                if (cm.load(filename)) cout << "Load successful.\n";
                else cout << "Failed to load file.\n";
                break;
            }
            case 2: {
                string filename;
                cout << "Enter filename to save: ";
                getline(cin, filename);
                if (cm.save(filename)) cout << "Save successful.\n";
                else cout << "Failed to save file.\n";
                break;
            }
            case 3: {
                string name, birthday, email, phone;
                cout << "Enter name: "; getline(cin, name);
                cout << "Enter birthday: "; getline(cin, birthday);
                cout << "Enter email: "; getline(cin, email);
                cout << "Enter phone number: "; getline(cin, phone);

                Person* p = new Person{name, birthday, email, phone};
                if (cm.insert(p)) cout << "Contact inserted.\n";
                else {
                    cout << "Insert failed (possibly duplicate).\n";
                    delete p;
                }
                break;
            }
            case 4: {
                string name;
                cout << "Enter name to remove: ";
                getline(cin, name);
                if (cm.removeByName(name)) cout << "Contact removed.\n";
                else cout << "Contact not found.\n";
                break;
            }
            case 5: {
                string birthday;
                cout << "Enter birthday to remove: ";
                getline(cin, birthday);
                if (cm.removeByBirthday(birthday)) cout << "Contact removed.\n";
                else cout << "Contact not found.\n";
                break;
            }
            case 6: {
                string name;
                cout << "Enter name to retrieve: ";
                getline(cin, name);
                Person* p = cm.retrieveByName(name);
                if (p != nullptr) {
                    cout << p->name << "; " << p->birthday << "; " << p->email << "; " << p->phone_num << '\n';
                } else {
                    cout << "Contact not found.\n";
                }
                break;
            }
            case 7: {
                string birthday;
                cout << "Enter birthday to retrieve: ";
                getline(cin, birthday);
                Person* p = cm.retrieveByBirthday(birthday);
                if (p != nullptr) {
                    cout << p->name << "; " << p->birthday << "; " << p->email << "; " << p->phone_num << '\n';
                } else {
                    cout << "Contact not found.\n";
                }
                break;
            }
            case 8:
                cm.printByName();
                break;
            case 9:
                cm.printByBirthday();
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    }

    cout << "Exiting program.\n";
    return 0;
}