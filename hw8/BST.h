#ifndef BST_H
#define BST_H

#include <string>
using namespace std;

class Node {
public:
    int key;//key
    string value;//String value to be stored in the node
    Node* left;//Left child node(small key)
    Node* right;//Right child node(big key)

    Node(int k, string v) {//Constructor
        key = k;
        value = v;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* root;//root node
    Node* insert(Node* node, int key, string value);//Recursive function to insert a new node

    Node* removeNode(Node* node, int key, bool& found);//A recursive function that deletes a node. found returns whether the deletion was successful.
    Node* findMin(Node* node);//Find the node with the minimum key in a given subtree
    void inorder(Node* node);//Output (key, value) pairs through inorder traversal

public:
    BST();//Constructor
    void add(int key, string value);
    void remove(int key);
    void print();
};

#endif