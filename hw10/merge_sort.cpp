#include "merge_sort.h"
using namespace std;

void mergeSort(WordFreq list[], WordFreq sorted[], int low, int high){//Recursive merge sort function
    if(low>=high){
        return;
    }
    int mid = (low+high)/2;
    //Recursively sort the left and right halves
    mergeSort(list, sorted, low, mid);
    mergeSort(list, sorted, mid + 1, high);
    //Merge the two sorted halves
    merge(list, sorted, low, mid, high);
}

void merge(WordFreq list[], WordFreq sorted[], int low, int mid, int high){//Merge two sorted subarrays
    int i = low;
    int j = mid + 1;
    int k = low;

    while(i <= mid && j <= high){//Merge elements in order based on compare()
        if(compare(list[i], list[j])){
            sorted[k++] = list[i++];
        } else {
            sorted[k++] = list[j++];
        }
    }
    while(i <= mid){//Copy remaining elements from left half
        sorted[k++] = list[i++];
    }

    while(j <= high){//Copy remaining elements from right half
        sorted[k++] = list[j++];
    }

    for(int t = low; t <= high; ++t){//Copy sorted elements back to the original list
        list[t] = sorted[t];
    }
}

bool compare(const WordFreq& a, const WordFreq& b){//Sort primarily by count (descending), then by word (ascending)
    if (a.count < b.count) return false;
    else if (a.count > b.count) return true;
    else{
        if (a.word < b.word)
            return true;
        else//If counts are equal, compare words alphabetically
            return false;
    }
}