#ifndef MAPNODE_H
#define MAPNODE_H

#include <string>
using namespace std;

class MapNode {//This class defines a node used in the binary search tree for word mapping
public:
    string key;//The word to search for
    string value;//The word to replace with
    MapNode* left;//Pointer to the left child node
    MapNode* right;//Pointer to the right child node

    MapNode(string k, string v);//Constructor to initialize the node with key and value
};

#endif