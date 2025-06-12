#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>//For std::sort and other STL algorithms
#include <string>
using namespace std;
#define MAX_WORDS 2048

typedef struct {
    string word;
    int count;
} WordFreq;

bool compare(const WordFreq& a, const WordFreq& b) {//Comparison function: sort by frequency descending, then by word ascending
    if (a.count != b.count)
        return a.count > b.count;
    return a.word < b.word;
}

int main() {
    WordFreq list[MAX_WORDS];//Array to store words and their frequencies
    int size = 0;//Number of unique words

    cout << "Enter file name: ";
    string filename;
    cin >> filename;//Enter the file name
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

    sort(list, list + size, compare);//Sort the list using std::sort based on frequency and then alphabetically

    for (int i = 0; i < 5 && i < size; i++) {//Print top 5 most frequent words (converted to uppercase)
        for (char& c : list[i].word)
            c = toupper(c);

        cout << list[i].word << ": " << list[i].count << endl;
    }
    return 0;
}