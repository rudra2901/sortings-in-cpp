#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

// Function to find highest value in an array
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// Radix Sort Function
void countSort(int arr[], int n, int exp) {
    int output[n];
    int i, count[10] = { 0 };
 
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n) {
    int m = getMax(arr, n);
 
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
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
    radixsort(arr, n);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end-start);
    
    printArray(arr, n);
    cout<<"\n Time Used : "<<duration.count()<<"microsecond \n";
    
    return 0;
}



