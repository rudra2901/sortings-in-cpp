import java.util.Scanner;

class InsertionSort {
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

    // Array printing function
    void printArray(int arr[], int n) {

	for(int i = 0; i < n; i++)
	    System.out.print(arr[i] + " ");
	System.out.println();
    }

    //Driver function
    public static void main(String args[]) {
	Scanner sc = new Scanner(System.in);
	InsertionSort obj = new InsertionSort();

	int n;	
	n = sc.nextInt();	
	int arr[] = new int[n];
	for(int i = 0; i < n; i++)
	    arr[i] = sc.nextInt();

	obj.BubbleSort(arr, n);
	System.out.println("Sorted Array:");
	obj.printArray(arr, n);
    }
}
