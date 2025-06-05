#include "merge_sort.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

using namespace std;

int main() {
    WordFreq list[MAX_WORDS];//Array to store words and their frequencies
    int size = 0;//Number of unique words

    string filename;
    cin >> filename;
    ifstream fin(filename);

    if (!fin) {
        cerr << "Can't open file" << endl;
        return 1;
    }

    string line;
    while (getline(fin, line)) {
        for (int i = 0; i < line.length(); i++) {//Replace non-alphanumeric characters with spaces
            if (!isalnum(line[i])) {
                line[i] = ' ';
            }
        }

        istringstream iss(line);//Stream line into words
        string word;

        while (iss >> word) {
            for (char& c : word)//Convert word to lowercase
                c = tolower(c);

            bool found = false;
            for (int i = 0; i < size; i++) {//Check if the word already exists in the list
                if (list[i].word == word) {
                    list[i].count++;
                    found = true;
                    break;
                }
            }

            if (!found) {//If word is new, add it to the list
                list[size].word = word;
                list[size].count = 1;
                size++;
            }
        }
    }

    WordFreq sorted[MAX_WORDS];//Sort the word list using merge sort
    mergeSort(list, sorted, 0, size - 1);

    for (int i = 0; i < 5 && i < size; i++) {//Print top 5 most frequent words (converted to uppercase)
        for (char& c : list[i].word)
            c = toupper(c);

        cout << list[i].word << ": " << list[i].count << endl;
    }
    return 0;
}