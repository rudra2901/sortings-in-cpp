import java.util.Scanner;

class BubbleSort {
    //Function for Sorting
    void BubbleSort (int arr[], int n) {

	for(int i = 0; i < n-1; i++)
	    for(int j = 0; j < n-i-1; j++)
		if(arr[j] > arr[j+1]) {
		    int temp = arr[j];
		    arr[j] = arr[j+1];
		    arr[j+1] = temp;
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
	BubbleSort obj = new BubbleSort();

	int n;	
	n = sc.nextInt();	
	int arr[] = new int[10];
	for(int i = 0; i < n; i++)
	    arr[i] = sc.nextInt();

	obj.BubbleSort(arr, n);
	System.out.println("Sorted Array:");
	obj.printArray(arr, n);
    }
}
