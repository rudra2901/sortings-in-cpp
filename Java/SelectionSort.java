import java.util.Scanner;

class SelectionSort {

    // Selection Sort Function
    void selectionSort(int arr[], int n) {
	int i, j, min;

	for (i = 0; i < n-1; i++){
            min = i;
            for (j = i+1; j < n; j++)
		if (arr[j] < arr[min])
		    min = j;
 
	    int temp = arr[min];
	    arr[min] = arr [i];
	    arr[i] = temp;
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
	SelectionSort obj = new SelectionSort();

	int n;	
	n = sc.nextInt();	
	int arr[] = new int[n];
	for(int i = 0; i < n; i++)
	    arr[i] = sc.nextInt();

	obj.selectionSort(arr, n);
	System.out.println("Sorted Array:");
	obj.printArray(arr, n);
    }
}
