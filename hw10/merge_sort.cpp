#include "merge_sort.h"
using namespace std;

void mergeSort(WordFreq list[], WordFreq sorted[], int low, int high){
    if(low>=high){
        return;
    }
    int mid = (low+high)/2;
    mergeSort(list, sorted, low, mid);
    mergeSort(list, sorted, mid + 1, high);
    merge(list, sorted, low, mid, high);
}

void merge(WordFreq list[], WordFreq sorted[], int low, int mid, int high){
    int i = low;
    int j = mid + 1;
    int k = low;

    while(i <= mid && j <= high){
        if(compare(list[i], list[j])){
            sorted[k++] = list[i++];
        } else {
            sorted[k++] = list[j++];
        }
    }
    while(i <= mid){
        sorted[k++] = list[i++];
    }

    while(j <= high){
        sorted[k++] = list[j++];
    }

    for(int t = low; t <= high; ++t){
        list[t] = sorted[t];
    }
}

bool compare(const WordFreq& a, const WordFreq& b){
    if (a.count < b.count) return false;
    else if (a.count > b.count) return true;
    else{
        if (a.word < b.word)
            return true;
        else
            return false;
    }
}