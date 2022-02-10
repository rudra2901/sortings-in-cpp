#include <iostream>
#include <chrono>

#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

using namespace std;
using namespace std::chrono;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

// Insertion Sort Function
void insertionSort(int arr[], int l, int r) {
    int i, key, j;
    for (i = l; i <= r; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Quick Sort Implementation

//Partition with middle of three elements
int medianOf3(int* arr, int l, int r) {
    int mid = (l + r) / 2;

    if (arr[mid] < arr[l])
        swap(arr[mid], arr[l]);

    if (arr[r] < arr[l])
        swap(arr[r], arr[l]);

    if (arr[mid] > arr[r])
        swap(arr[mid], arr[r]);

    swap(arr[mid], arr[r - 1]);

    return arr[r - 1];
}

int partition(int* arr, int l, int r, int pivot) {
    int i = l + 1;
    int j = r - 2;
    while (i < j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[r - 1]);

    return i;
}

void quickSort(int *arr,int l,int r){
    if(r-l < 5)
        insertionSort(arr, l, r);

    else if(l < r) {
        int pivot = medianOf3(arr, l, r);
        int p = partition(arr,l,r, pivot);
        quickSort(arr,l,p-1);
        quickSort(arr,p+1,r);
    }
}

void printArray(int arr[], int n) {
    cout<<"\n Array : ";
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
}

int main() {
    //FILEIO 

    //Input size
    int n = 10;
    cin>>n;
    
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    
    auto start = high_resolution_clock::now();
    quickSort(arr, 0, n-1);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end-start);
    
    printArray(arr, n);
    cout<<"\n Time Used : "<<duration.count()<<"microsecond \n";
    
    return 0;
}


