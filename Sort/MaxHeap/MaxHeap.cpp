#include <vector>
#include <iostream>
using namespace std;

class MaxHeap {
    vector<int> heap;

public:
    void insert(int value);
    void deleteMax();
    void print();
};

void MaxHeap::insert(int value){
    heap.push_back(value);
    int i = heap.size() - 1;
    int parent = (i - 1) / 2;
    while(i>0){
        if(heap[parent]<heap[i]){
            swap(heap[parent],heap[i]);
            i = parent;
            parent = (i - 1) / 2;
        }else{
            break;
        }
    }
}

void MaxHeap::deleteMax(){
    if (heap.empty()) return;
    heap[0] = heap.back();
    heap.pop_back();
    int i=0;
    while(i<heap.size()){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            i = largest;
        } else break;
    }
}

int main(){

}