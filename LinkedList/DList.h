// DList.h
#ifndef DLIST_H
#define DLIST_H

#include <iostream>
#include <string>

using namespace std;

typedef struct t_list_node {
    string data;
    struct t_list_node *link;
} list_node;

class DList {
private:
    list_node *head;

public:
    DList();
    ~DList();
    void delete_list(list_node* node_ptr); // for ~DList
    list_node* Retrieve(string data);
    list_node* Retrieve(int index);
    void Insert(string data);
    void Delete(string data);
    void Invert();
    void Print();
    bool IsEmpty();
};

#endif // DLIST_H