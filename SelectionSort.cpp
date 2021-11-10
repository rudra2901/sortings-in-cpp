#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

// Selection Sort Function
void selectionSort(int arr[], int n) {
    int i, j, min;
 
    for (i = 0; i < n-1; i++){
        min = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
 
        swap(arr[min], arr[i]);
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
    selectionSort(arr, n);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end-start);
    
    printArray(arr, n);
    cout<<"\n Time Used : "<<duration.count()<<"microsecond \n";
    
    return 0;
}
