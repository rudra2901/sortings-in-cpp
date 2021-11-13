import java.util.Scanner;

class QuickSort {

    static void swap(int[] arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
    }

    //Partition by choosing last element as Pivot.
    static int partition(int[] arr, int low, int high) {
      	int pivot = arr[high]; 
	int i = (low - 1); 
  
	for(int j = low; j <= high - 1; j++) {
	    if (arr[j] < pivot) {
		i++;
		swap(arr, i, j);
	    }
	}
	
	swap(arr, i + 1, high);
	return (i + 1);
    }
    
    //Quick Sort Function
    static void quickSort(int[] arr, int low, int high) {
	if (low < high) {
	    int pi = partition(arr, low, high);
	    
	    quickSort(arr, low, pi - 1);
	    quickSort(arr, pi + 1, high);
	}
    }
    
    // Array printing function
    void printArray(int arr[], int n) {

	for(int i = 0; i < n; i++)
	    System.out.print(arr[i] + " ");
	System.out.println();
    }

    //Driver function
    public static void main(String args[]) {
	Scanner sc = new Scanner(System.in);
	QuickSort obj = new QuickSort();

	int n;	
	n = sc.nextInt();	
	int arr[] = new int[n];
	for(int i = 0; i < n; i++)
	    arr[i] = sc.nextInt();

	obj.quickSort(arr, 0, n-1);
	System.out.println("Sorted Array:");
	obj.printArray(arr, n);
    }
}
