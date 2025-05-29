#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "MapBST.h"
using namespace std;

int main() {
    string textFileName, mapFileName;
    string line;

    cout << "Enter input text filename: ";
    cin >> textFileName;//Enter text file name

    cout << "Enter map file filename: ";
    cin >> mapFileName;//Enter map file name

    ifstream mapFile(mapFileName);//Open the map file
    if (!mapFile) {
        cerr << "Failed to open map file." << endl;
        return 1;
    }

    MapBST mapTree;//Create a binary search tree to store the word mappings

    ifstream textFile(textFileName);//Open the text file
    if (!textFile) {
        cerr << "Failed to open text file." << endl;
        return 1;
    }

    while(getline(mapFile,line)){//Read each line from the map file and insert into the BST
        int pos = line.find(":");
        if(pos!=string::npos){
            string key=line.substr(0,pos);
            string value = line.substr(pos+1);
            mapTree.insert(key,value);
        }
    }

    while(getline(textFile,line)){//Read each line from the input text file
        stringstream ss(line);
        string word;
        while(ss>>word){//Process each word in the line
            string mapped;
            if(mapTree.find(word,mapped)){//Replace word if mapping exists
                cout<<mapped<<" ";
            }else{
                cout<<word<<" ";
            }
        }
        cout << endl;
    }

    return 0;
}