#include "MapNode.h"

MapNode::MapNode(string k, string v) {//Constructor definition for MapNode
    key = k;
    value = v;
    left = nullptr;
    right = nullptr;
}