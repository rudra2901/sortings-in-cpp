#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to generate arrays randomnly
void arrayGenerator(int a[], int n) {
    srand((unsigned)time(0));
    
    for(int i = 0; i < n; i++)
        a[i] = (rand()%n + 1);
}

// Function to swap two numbers in an array
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

// Quick Sort Implementation
int partition(int* arr,int l,int r){
    int pivot = arr[r];
    int i = l-1;

    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}

void quickSort(int *arr,int l,int r){
    if(l<r){
        int p = partition(arr,l,r);

        quickSort(arr,l,p-1);
        quickSort(arr,p+1,r);
    }
}

//Bucket Sort Implementation
void bucketSort(double arr[], int n) {
    vector<double> b[n];
 
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }
 
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());
 
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}

//Driver Function
int main() {
    int a[10], b[20], c[50], d[100], e[1000];
    arrayGenerator(a, 10);
    arrayGenerator(b, 20);
    arrayGenerator(c, 50);
    arrayGenerator(d, 100);
    arrayGenerator(e, 1000);
    
    int sizes[] = {10, 20, 50, 100, 1000};
    
    vector<vector<int>> test(5);
    for(int j = 0; j < 10; j++)
        test[0].push_back(a[j]);
    for(int j = 0; j <20; j++)
        test[1].push_back(b[j]);
    for(int j = 0; j < 50; j++)
        test[2].push_back(c[j]);
    for(int j = 0; j < 100; j++)
        test[3].push_back(d[j]);
    for(int j = 0; j < 1000; j++)
        test[4].push_back(e[j]);
    
    cout<<"\n\n\t\t\t\t\t\t BUBBLE SORT\n";
    cout<<"\n Size  |  Run 1  |  Run 2  |  Run 3  |  Run 4  |  Run 5  |  Avg  ";
    for(int i = 0; i < 5; i++) {
        
        cout<<"\n "<<sizes[i];
        if(i <= 2)
            cout<<"    |";
        else if(i == 3)
            cout<<"   |";
        else
            cout<<"  |";
        
        int *temp = new int[sizes[i]];
        
        double avg = 0.00;
        for(int j = 0; j < 5; j++) {
            for(int j = 0; j < sizes[i]; j++)
                temp[j] = test[i][j];
            
            auto start = high_resolution_clock::now();
            bubbleSort(temp, sizes[i]);
            auto end = high_resolution_clock::now();
            
            auto duration = duration_cast<microseconds>(end-start);
            long long count = duration.count();
            avg += count;
            if(count < 10)
                cout<<"    "<<count<<"    |";
            else if(count < 100)
                cout<<"    "<<count<<"   |";
            else if(count < 1000)
                cout<<"    "<<count<<"  |";
            else if(count < 10000)
                cout<<"   "<<count<<"  |";
        }
        avg = (avg/5);
        cout<<"   "<<avg;
        
        delete [] temp;
    }
    cout<<"\n";
    
    cout<<"\n\n\t\t\t\t\t\t INSERTION SORT\n";
    cout<<"\n Size  |  Run 1  |  Run 2  |  Run 3  |  Run 4  |  Run 5  |  Avg  ";
    for(int i = 0; i < 5; i++) {
        
        cout<<"\n "<<sizes[i];
        if(i <= 2)
            cout<<"    |";
        else if(i == 3)
            cout<<"   |";
        else
            cout<<"  |";
        
        int *temp = new int[sizes[i]];
        
        double avg = 0.00;
        for(int j = 0; j < 5; j++) {
            for(int j = 0; j < sizes[i]; j++)
                temp[j] = test[i][j];
            
            auto start = high_resolution_clock::now();
            insertionSort(temp, sizes[i]);
            auto end = high_resolution_clock::now();
            
            auto duration = duration_cast<microseconds>(end-start);
            long long count = duration.count();
            avg += count;
            if(count < 10)
                cout<<"    "<<count<<"    |";
            else if(count < 100)
                cout<<"    "<<count<<"   |";
            else if(count < 1000)
                cout<<"    "<<count<<"  |";
            else if(count < 10000)
                cout<<"   "<<count<<"  |";
        }
        avg = (avg/5);
        cout<<"   "<<avg;
        
        delete [] temp;
    }
    cout<<"\n";
    
    cout<<"\n\n\t\t\t\t\t\t SELECTION SORT\n";
    cout<<"\n Size  |  Run 1  |  Run 2  |  Run 3  |  Run 4  |  Run 5  |  Avg  ";
    for(int i = 0; i < 5; i++) {
        
        cout<<"\n "<<sizes[i];
        if(i <= 2)
            cout<<"    |";
        else if(i == 3)
            cout<<"   |";
        else
            cout<<"  |";
        
        int *temp = new int[sizes[i]];
        
        double avg = 0.00;
        for(int j = 0; j < 5; j++) {
            for(int j = 0; j < sizes[i]; j++)
                temp[j] = test[i][j];
            
            auto start = high_resolution_clock::now();
            selectionSort(temp, sizes[i]);
            auto end = high_resolution_clock::now();
            
            auto duration = duration_cast<microseconds>(end-start);
            long long count = duration.count();
            avg += count;
            if(count < 10)
                cout<<"    "<<count<<"    |";
            else if(count < 100)
                cout<<"    "<<count<<"   |";
            else if(count < 1000)
                cout<<"    "<<count<<"  |";
            else if(count < 10000)
                cout<<"   "<<count<<"  |";
        }
        avg = (avg/5);
        cout<<"   "<<avg;
        
        delete [] temp;
    }
    cout<<"\n";
    
    cout<<"\n\n\t\t\t\t\t\t TOURNAMENT SORT\n";
    cout<<"\n Size  |  Run 1  |  Run 2  |  Run 3  |  Run 4  |  Run 5  |  Avg  ";
    for(int i = 0; i < 5; i++) {
        
        cout<<"\n "<<sizes[i];
        if(i <= 2)
            cout<<"    |";
        else if(i == 3)
            cout<<"   |";
        else
            cout<<"  |";
        
        int *temp = new int[sizes[i]];
        int *output = new int[sizes[i]];
        double avg = 0.00;
        for(int j = 0; j < 5; j++) {
            for(int j = 0; j < sizes[i]; j++)
                temp[j] = test[i][j];
            
            auto start = high_resolution_clock::now();
            tournamentSort(temp, output,sizes[i]);
            auto end = high_resolution_clock::now();
            
            auto duration = duration_cast<microseconds>(end-start);
            long long count = duration.count();
            avg += count;
            if(count < 10)
                cout<<"    "<<count<<"    |";
            else if(count < 100)
                cout<<"    "<<count<<"   |";
            else if(count < 1000)
                cout<<"    "<<count<<"  |";
            else if(count < 10000)
                cout<<"   "<<count<<"  |";
        }
        avg = (avg/5);
        cout<<"   "<<avg;
        
        delete [] temp;
        delete [] output;
    }
    cout<<"\n";
    
    cout<<"\n\n\t\t\t\t\t\t QUICK SORT\n";
    cout<<"\n Size  |  Run 1  |  Run 2  |  Run 3  |  Run 4  |  Run 5  |  Avg  ";
    for(int i = 0; i < 5; i++) {
        
        cout<<"\n "<<sizes[i];
        if(i <= 2)
            cout<<"    |";
        else if(i == 3)
            cout<<"   |";
        else
            cout<<"  |";
        
        int *temp = new int[sizes[i]];

        double avg = 0.00;
        for(int j = 0; j < 5; j++) {
            for(int j = 0; j < sizes[i]; j++)
                temp[j] = test[i][j];
            
            auto start = high_resolution_clock::now();
            quickSort(temp, 0, sizes[i] - 1);
            auto end = high_resolution_clock::now();
            
            auto duration = duration_cast<microseconds>(end-start);
            long long count = duration.count();
            avg += count;
            if(count < 10)
                cout<<"    "<<count<<"    |";
            else if(count < 100)
                cout<<"    "<<count<<"   |";
            else if(count < 1000)
                cout<<"    "<<count<<"  |";
            else if(count < 10000)
                cout<<"   "<<count<<"  |";
        }
        avg = (avg/5);
        cout<<"   "<<avg;
        
        delete [] temp;
    }
    cout<<"\n";
    
    cout<<"\n\n\t\t\t\t\t\t MERGE SORT\n";
    cout<<"\n Size  |  Run 1  |  Run 2  |  Run 3  |  Run 4  |  Run 5  |  Avg  ";
    for(int i = 0; i < 5; i++) {
        
        cout<<"\n "<<sizes[i];
        if(i <= 2)
            cout<<"    |";
        else if(i == 3)
            cout<<"   |";
        else
            cout<<"  |";
        
        int *temp = new int[sizes[i]];
        
        double avg = 0.00;
        for(int j = 0; j < 5; j++) {
            for(int j = 0; j < sizes[i]; j++)
                temp[j] = test[i][j];
            
            auto start = high_resolution_clock::now();
            mergeSort(temp, 0, sizes[i] - 1);
            auto end = high_resolution_clock::now();
            
            auto duration = duration_cast<microseconds>(end-start);
            long long count = duration.count();
            avg += count;
            if(count < 10)
                cout<<"    "<<count<<"    |";
            else if(count < 100)
                cout<<"    "<<count<<"   |";
            else if(count < 1000)
                cout<<"    "<<count<<"  |";
            else if(count < 10000)
                cout<<"   "<<count<<"  |";
        }
        avg = (avg/5);
        cout<<"   "<<avg;
        
        delete [] temp;
    }
    cout<<"\n";
    
    cout<<"\n\n\t\t\t\t\t\t RADIX SORT\n";
    cout<<"\n Size  |  Run 1  |  Run 2  |  Run 3  |  Run 4  |  Run 5  |  Avg  ";
    for(int i = 0; i < 5; i++) {
        
        cout<<"\n "<<sizes[i];
        if(i <= 2)
            cout<<"    |";
        else if(i == 3)
            cout<<"   |";
        else
            cout<<"  |";
        
        int *temp = new int[sizes[i]];
        
        double avg = 0.00;
        for(int j = 0; j < 5; j++) {
            for(int j = 0; j < sizes[i]; j++)
                temp[j] = test[i][j];
            
            auto start = high_resolution_clock::now();
            radixsort(temp, sizes[i]);
            auto end = high_resolution_clock::now();
            
            auto duration = duration_cast<microseconds>(end-start);
            long long count = duration.count();
            avg += count;
            if(count < 10)
                cout<<"    "<<count<<"    |";
            else if(count < 100)
                cout<<"    "<<count<<"   |";
            else if(count < 1000)
                cout<<"    "<<count<<"  |";
            else if(count < 10000)
                cout<<"   "<<count<<"  |";
        }
        avg = (avg/5);
        cout<<"   "<<avg;
        
        delete [] temp;
    }
    cout<<"\n";
    
    cout<<"\n\n\t\t\t\t\t\t BUCKET SORT\n";
    cout<<"\n Size  |  Run 1  |  Run 2  |  Run 3  |  Run 4  |  Run 5  |  Avg  ";
    for(int i = 0; i < 4; i++) {
        
        cout<<"\n "<<sizes[i];
        if(i <= 2)
            cout<<"    |";
        else if(i == 3)
            cout<<"   |";
        else
            cout<<"  |";
        
        double *temp = new double[sizes[i]];
        
        double avg = 0.00;
        for(int j = 0; j < 5; j++) {
            for(int j = 0; j < sizes[i]; j++)
                temp[j] = test[i][j]*0.001;
            
            auto start = high_resolution_clock::now();
            bucketSort(temp, sizes[i]);
            auto end = high_resolution_clock::now();
            
            auto duration = duration_cast<microseconds>(end-start);
            long long count = duration.count();
            avg += count;
            if(count < 10)
                cout<<"    "<<count<<"    |";
            else if(count < 100)
                cout<<"    "<<count<<"   |";
            else if(count < 1000)
                cout<<"    "<<count<<"  |";
            else if(count < 10000)
                cout<<"   "<<count<<"  |";
        }
        avg = (avg/4);
        cout<<"   "<<avg;
        
        delete [] temp;
    }
    cout<<"\n";
    
    return 0;
}
