#include "MapBST.h"
#include <string>

MapBST::MapBST(){//Constructor
    root = nullptr;
}

MapNode* MapBST::insert(MapNode* node, string key, string value){//Recursive helper function to insert a new node into the tree
    if(node == nullptr){
        return new MapNode(key,value);
    }
    if(key < node -> key){
        node->left = insert(node->left, key, value);
    }else if(key > node -> key){
        node->right = insert(node->right, key, value);
    }
    return node;
}

MapNode* MapBST::find(MapNode* node, const string& key){//Recursive helper function to find a node by key
    if(node == nullptr){
        return node;
    }
    if(key == node -> key){
        return node;
    }
    if(key < node -> key){
        return find(node -> left, key);
    }else{
        return find(node -> right, key);
    }
}

void MapBST::insert(string key, string value){//Add a (key, value) pair into the tree
    root = insert(root ,key, value);
}

bool MapBST::find(string key, string& value){//Search for a key and return its value
    MapNode* result = find(root, key);
    if (result == nullptr) {
        return false;
    }
    value = result->value;
    return true;
}
