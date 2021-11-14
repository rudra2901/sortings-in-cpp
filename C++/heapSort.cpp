#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

// Heap Sort Implementation
class Heap {
    int *heapArr;
    int size = 0;
    
public:
    Heap(int size) {
        this->size = size;
        heapArr = new int[this->size];
        for (int i = 0; i < this->size; i++)
            heapArr[i] = INT_MAX;
    }
    
    void insElement(int val[]) {
        for (int i = 0; i < size; i++)
            heapArr[i] = val[i];
    }
    
    void heapify(int n, int index) {
        int curr = index;
        int left = 2 * index + 1, right = 2 * index + 2;
        if (left < n and heapArr[left] > heapArr[curr])
            curr = left;
        if (right < n and heapArr[right] > heapArr[curr])
            curr = right;
        if (curr != index) {
            swap(heapArr[index],heapArr[curr]);
            heapify(n, curr);
        }
    }
    
    void createHeap() {
        for (int i = size / 2 - 1; i >= 0; i--)
            heapify(size, i);
    }
    
    void heapSort() {
        for (int i = size - 1; i >= 0; i--) {
            swap(heapArr[0], heapArr[i]);
            heapify(i, 0);
        }
    }
    
    void printHeap() {
        cout<<"\n\t Current Heap Array : ";
        for (int i = 0; i < size; i++)
                cout << heapArr[i] << " ";
        cout << endl;
    }
};

int main() {
    //Input size
    int n;
    cin>>n;
    
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    
    Heap h(n);
    h.insElement(arr);
    h.createHeap();
    
    auto start = high_resolution_clock::now();
    h.heapSort();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end-start);
    
    h.printHeap();
    cout<<"\n Time Used : "<<duration.count()<<"microsecond \n";
    
    return 0;
}




