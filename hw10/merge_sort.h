#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <string>

#define MAX_WORDS 2048

typedef struct {
    std::string word;
    int count;
} WordFreq;

void mergeSort(WordFreq list[], WordFreq sorted[], int low, int high);

void merge(WordFreq list[], WordFreq sorted[], int low, int mid, int high);

bool compare(const WordFreq& a, const WordFreq& b);

#endif