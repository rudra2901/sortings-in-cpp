#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

// Merge Sort Function
void merge(int a[], int left, int mid, int right) {
    int i = 0, j = 0;
    int lSize = mid - left + 1;
    int rSize = right - mid;
    
    int lArr[lSize], rArr[rSize];
    
    for(i = 0; i < lSize; i++)
       lArr[i] = a[left+i];
    for(j = 0; j < rSize; j++)
       rArr[j] = a[mid+1+j];
    
    i = 0; j = 0;
    int k = left;
    while(i < lSize && j < rSize) {
       if(lArr[i] <= rArr[j]) {
          a[k] = lArr[i];
          i++;
       }
       else {
          a[k] = rArr[j];
          j++;
       }
       k++;
    }
    while(i < lSize) {
       a[k] = lArr[i];
       i++; k++;
    }
    while(j < rSize) {
       a[k] = rArr[j];
       j++; k++;
    }
}
void mergeSort(int arr[], int left, int right) {
    int mid;
    if(left < right) {
        mid = left + (right - left)/2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
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
    mergeSort(arr, 0, n-1);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end-start);
    
    printArray(arr, n);
    cout<<"\n Time Used : "<<duration.count()<<"microsecond \n";
    
    return 0;
}

