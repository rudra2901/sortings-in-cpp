#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

// Bubble Sort Function
void bubbleSort(int arr[], int n) {
    int i, j;
    
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
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
    bubbleSort(arr, n);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end-start);
    
    printArray(arr, n);
    cout<<"\n Time Used : "<<duration.count()<<"microsecond \n";
    
    return 0;
}
