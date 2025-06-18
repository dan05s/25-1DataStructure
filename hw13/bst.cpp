#include "bst.h"
#include "person.h"
#include <iostream>

BST::BST(){//Constructor
    root = nullptr;
}

void BST::insert(string key, Person* person){//Inserts a new node with the given key and person data
    Node* new_node = new Node;
    new_node -> person = person;
    new_node -> key = key;
    new_node->left =nullptr;
    new_node->right=nullptr;
    Node* current = root;
    Node* parent = nullptr;
     if(root == nullptr){//If the tree is empty, set the new node as root
            root = new_node;
            new_node -> left = nullptr;
            new_node -> right = nullptr;
            return;
        }
    while(current != nullptr){//Find the correct position for the new node
        parent = current;
        string currentKey = current -> key;
        if(new_node -> key < current -> key){
            current = current -> left;
        }
        else if(new_node -> key > current -> key){
            current = current -> right;
        }else{
            delete new_node;
            return;
        }
    }
    if(key < parent -> key){//Link the new node to the parent
        parent->left = new_node;
    }else{//Key already exists, do not insert duplicates
        parent->right = new_node;
    }
}

Person* BST::search(string key){//Searches for a node by key and returns the associated Person*
    Node* current = root;
    while (current != nullptr) {
        if (key < current->key) {
            current = current->left;
        } else if (key > current->key) {
            current = current->right;
        } else {
            return current->person;
        }
    }
    return nullptr;
}

void BST::inorder(){//Searches for a node by key and returns the associated Person*
    inorderTraversal(root);
}

void BST::inorderTraversal(Node* node){//Helper function: inorder traversal
    if (node == nullptr) return;
    inorderTraversal(node->left);
    cout << node->person->name << "; "
         << node->person->birthday << "; "
         << node->person->email << "; "
         << node->person->phone_num << endl;
    inorderTraversal(node->right);
}

void BST::remove(string key){//Removes a node with the given key from the BST
    if(root==nullptr) return;
    Node* current = root;
    Node* parent = nullptr;
    while(current!=nullptr && current->key != key){//Search for the node to remove and its parent
        parent = current;
         if(key<current->key){
            current = current -> left;
        }else{
            current = current -> right;
        }
    }
    if(current == nullptr){//If key not found, do nothing
        return;
    }
    if(current->left == nullptr && current->right==nullptr){//Case 1: Node is a leaf (no children)
        if(current == root){
            root = nullptr;
        }else if(parent->left == current){
            parent->left=nullptr;
        }else{
            parent->right=nullptr;
        }
        delete current;
    }
    else if(current->left==nullptr || current->right==nullptr){//Case 2: Node has one child
        Node* child = (current->left!=nullptr)? current->left : current->right;
        if(current == root){
            root = child;
        }else if(parent->left == current){
            parent->left = child;
        }else{
            parent ->right = child;
        }
        delete current;
    }
    else{//Case 3: Node has two children.
        //Find the inorder successor
        Node* minNodeParent = current;
        Node* minNode = current -> right;
        while(minNode->left!=nullptr){
            minNodeParent = minNode;
            minNode = minNode->left;
        }
        //Copy successor's data to current node
        current->key = minNode->key;
        current->person=minNode->person;
        //Delete the successor node
        if(minNodeParent->left == minNode){
            minNodeParent->left = minNode->right;
        }else{
            minNodeParent->right=minNode->right;
        }
        delete minNode;
    }
}

BST::~BST(){//destructor
    destroyTree(root);
}

void BST::destroyTree(Node* node){//helper(Using recursive functions)
    if (node == nullptr) return;
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}