#include "DList.h"

using namespace std;

DList::DList(){
    head = nullptr;
}

DList::~DList() {
    delete_list(head);
}

void DList::delete_list(list_node* node_ptr){
    while(node_ptr != nullptr){
        list_node* next = node_ptr->link;
        delete node_ptr;
        node_ptr = next;
    }
}

list_node* DList::Retrieve(string data){
    list_node* current = head;
    while (current != nullptr) {
        if (current->data == data) {
        return current;
        }
        current = current->link;
    }
    return nullptr;
}

list_node* DList::Retrieve(int index){
    list_node* current = head;
    int cur_index = 0;
    while (current != nullptr && cur_index != index) {
        current = current->link;
        cur_index ++;
    }
    return current;
}

void DList::Insert(string data){
    list_node* new_node = new list_node;
    new_node -> data = data;
    new_node->link = head;
    head = new_node;
}

void DList::Delete(string data){
    list_node* current = head;
    list_node* prev = nullptr;

    while (current != nullptr && current->data != data) {
        prev = current;
        current = current->link;
    }

    if (current == nullptr) return;

    if (prev == nullptr) {
        head = current->link;
    } else {
        prev->link = current->link;
    }
    delete current;
}

void DList::Invert(){
    list_node* current = head;
    list_node* prev = nullptr;

    while (current != nullptr) {
        list_node* next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void DList::Print(){
    list_node* current = head;
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    while (current != nullptr){
        cout << current->data << endl;
        current = current -> link;
    }
    cout << "End" << endl;
}

bool DList::IsEmpty(){
    list_node* current = head;
    if(head == nullptr){
        return true;
    }else{
        return false;
    }
}