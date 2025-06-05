#include "merge_sort.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

using namespace std;

int main() {
    WordFreq list[MAX_WORDS];
    int size = 0;

    string filename;
    cin >> filename;
    ifstream fin(filename);

    if (!fin) {
        cerr << "Can't open file" << endl;
        return 1;
    }

    string line;
    while (getline(fin, line)) {
        for (int i = 0; i < line.length(); i++) {
            if (!isalnum(line[i])) {
                line[i] = ' ';
            }
        }

        istringstream iss(line);
        string word;

        while (iss >> word) {
            for (char& c : word)
                c = tolower(c);

            bool found = false;
            for (int i = 0; i < size; i++) {
                if (list[i].word == word) {
                    list[i].count++;
                    found = true;
                    break;
                }
            }

            if (!found) {
                list[size].word = word;
                list[size].count = 1;
                size++;
            }
        }
    }

    WordFreq sorted[MAX_WORDS];
    mergeSort(list, sorted, 0, size - 1);

    for (int i = 0; i < 5 && i < size; i++) {
        for (char& c : list[i].word)
            c = toupper(c);

        cout << list[i].word << ": " << list[i].count << endl;
    }
    return 0;
}