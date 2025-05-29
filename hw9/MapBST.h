#ifndef MAPBST_H
#define MAPBST_H

#include <string>
#include "MapNode.h"
using namespace std;

class MapBST {
private:
    MapNode* root;
    MapNode* insert(MapNode* node, string key, string value);//Helper function for inserting a node
    MapNode* find(MapNode* node, const string& key);//Helper function for finding a node
public:
    MapBST();//Constructor
    void insert(string key, string value);//Insert key-value pair into BST
    bool find(string key, string& value);//Find target word for a source word. Returns true and sets 'value' if found
};

#endif