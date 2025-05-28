#include "BST.h"
#include <iostream>

BST::BST(){
    root = nullptr;
}

void BST::add(int key, string value){
    root = insert(root, key, value);
}

Node* BST::insert(Node* node, int key, string value){
    if(node == nullptr){
        Node* newNode = new Node(key, value);
        return newNode;
    }
    if(key<node->key){
        node->left = insert(node->left, key, value);
    }else if(key>node->key){
        node->right = insert(node->right, key, value);
    }else{
        cout << key << " is already in the tree" << endl;
        return node;
    }
}

void BST::print(){
    inorder(root);
}

void BST::inorder(Node* node){
    if(node == nullptr){
        return;
    }
    inorder(node->left);
    cout << "(" << node->key << ", " << node->value << ")" << endl;
    inorder(node->right);
}

void BST::remove(int key) {
    bool found = false;
    root = removeNode(root, key, found);
    if (!found) {
        cout << key << " is not in the tree" << endl;
    }
}

Node* BST::removeNode(Node* node, int key, bool& found){
    if(node == nullptr){
        found = false;
        return nullptr;
    }
    if(node->key < key){
        node->left=removeNode(node->left,key,found);
    }else if(node->key > key){
        node->right=removeNode(node->right,key,found);
    }else{
        if(node->left == nullptr && node->right == nullptr){
            delete node;
            found = true;
            return nullptr;
        }else if((node ->left == nullptr && node -> right != nullptr)||(node->right == nullptr && node->left != nullptr)){
            Node* child = (node->left != nullptr) ? node->left:node->right;
            found = true;
            return child;
        }else{
            Node* minNode = findMin(node->right);
            node -> key = minNode -> key;
            node -> value = minNode -> value;
            node -> right = removeNode(node ->right,minNode -> key, found);
            found = true;
            return node;
        }
    }
    return node;
}

Node* BST::findMin(Node* node) {
    while (node && node->left) {
        node = node->left;
    }
    return node;
}