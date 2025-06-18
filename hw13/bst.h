#ifndef BST_H
#define BST_H

#include "person.h"
#include <string>
using namespace std;

class BST {
    struct Node {
        string key;//Key for searching
        Person* person;//Pointer to the contact data
        Node* left;//Pointer to the left child
        Node* right;//Pointer to the right child
    };

    Node* root;//Root node of the tree
private:
    void inorderTraversal(Node* node);//helper function
public:
    BST();//Constructor
    void insert(string key, Person* person);//Insert a new node
    Person* search(string key);//Search by key
    void remove(string key);//Remove a node by key
    void inorder();//Inorder traversal
    ~BST();//Destructor
    void destroyTree(Node* node);//helper
};

#endif