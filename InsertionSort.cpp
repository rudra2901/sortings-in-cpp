#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

// Insertion Sort Function
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    cout<<"\n Array : ";
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}

int main() {
    //Input size
    int n;
    cin>>n;
    
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    
    auto start = high_resolution_clock::now();
    insertionSort(arr, n);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end-start);
    
    printArray(arr, n);
    cout<<"\n Time Used : "<<duration.count()<<"microsecond \n";
    
    return 0;
}
