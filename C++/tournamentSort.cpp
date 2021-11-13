#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

// Tournament sort Implementation
void createTree(int tree[], int n) {
    int i = 0, j = n;
    if(n&1) {
        while(i < 2*n-1) {
            if(i < n-1) {
                if(tree[i] < tree[i+1])
                    tree[j] = i;
                else
                    tree[j] = i+1;
            }
            else if(i == n-1) {
                if(tree[i] < tree[tree[i+1]])
                    tree[j] = i;
                else
                    tree[j] = tree[i+1];
            }
            else {
                if(tree[tree[i]] < tree[tree[i+1]])
                    tree[j] = tree[i];
                else
                    tree[j] = tree[i+1];
            }
            j++;
            i += 2;
        }
    }
    else {
        while(i < 2*n-1) {
            if(i < n-1) {
                if(tree[i] < tree[i+1])
                    tree[j] = i;
                else
                    tree[j] = i+1;
            }
            else {
                if(tree[tree[i]] < tree[tree[i+1]])
                    tree[j] = tree[i];
                else
                    tree[j] = tree[i+1];
            }
            j++;
            i += 2;
        }
    }
}

void tournamentSort(int a[],int out[], int n) {
    int tTree[((2*n)-1)];
    for(int i = 0; i < n; i++)
        tTree[i] = a[i];
    for(int i = 0; i < n; i++) {
        createTree(tTree, n);
        out[i] = a[tTree[(2*n)-2]];
        tTree[tTree[(2*n)-2]] = INT_MAX;
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
    int sortedArr[n];
    
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    
    auto start = high_resolution_clock::now();
    tournamentSort(arr, sortedArr, n);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end-start);
    
    printArray(sortedArr, n);
    cout<<"\n Time Used : "<<duration.count()<<"microsecond \n";
    
    return 0;
}



