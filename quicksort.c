// C program to implement Quick Sort Algorithm
#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {

    // Initialize pivot to be the first element
    int p = arr[low];
    int i = low;
    int j = high;

    while (i < j) {

        // Find the first element greater than
        // the pivot (from starting)
        while (arr[i] <= p && i < high) {
            i++;
        }

        // Find the first element smaller than
        // the pivot (from last)
        while (arr[j] > p && j > low) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {

        // call partition function to find Partition Index
        int pi = partition(arr, low, high);

        // Recursively call quickSort() for left and right
        // half based on Partition Index
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
  
    int arr[] = { 4, 2, 5, 3, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // calling quickSort() to sort the given array
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
// C program for the implementation of merge sort
#include <stdio.h>
#include <stdlib.h>

// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int leftArr[n1], rightArr[n2];

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// The subarray to be sorted is in the index range [left-right]
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
      
        // Calculate the midpoint
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    
      // Sorting arr using mergesort
    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
// C Program for HeapSort 
#include <stdio.h> 

// Heapify function 
void heapify(int arr[], int n, int i) 
{ 
	int temp, maximum, left_index, right_index; 

	// currently assuming i postion to 
	// be holding the largest value 
	maximum = i; 

	// right child index 
	right_index = 2 * i + 2; 

	// left child index 
	left_index = 2 * i + 1; 

	// if left index value is grater than the current index 
	// value 
	if (left_index < n && arr[left_index] > arr[maximum]) 
		maximum = left_index; 

	// if right index value is grater than the current index 
	// value 
	if (right_index < n && arr[right_index] > arr[maximum]) 
		maximum = right_index; 

	// checking if we needed swaping the elements or not 
	if (maximum != i) { 
		temp = arr[i]; 
		arr[i] = arr[maximum]; 
		arr[maximum] = temp; 
		heapify(arr, n, maximum); 
	} 
} 

// HeapSorting function 
void heapsort(int arr[], int n) 
{ 
	int i, temp; 

	// performing heapify on the non leaf nodes so n/2 - 1 
	// to 0 are the non leaf nodes 
	for (i = n / 2 - 1; i >= 0; i--) { 
		heapify(arr, n, i); 
	} 
	// the current array is changed to max heap 

	for (i = n - 1; i > 0; i--) { 
		temp = arr[0]; 
		arr[0] = arr[i]; 
		arr[i] = temp; 
		heapify(arr, i, 0); 
	} 
} 

// Driver code 
int main() 
{ 
	// initializing the array 
	int arr[] = { 20, 18, 5, 15, 3, 2 }; 
	int n = 6; 

	// Displaying original array 
	printf("Original Array : "); 
	for (int i = 0; i < n; i++) { 
		printf("%d ", arr[i]); 
	} 

	printf("\n"); 
	heapsort(arr, n); 

	// Displaying sorted array 
	printf("Array after performing heap sort: "); 
	for (int i = 0; i < n; i++) { 
		printf("%d ", arr[i]); 
	} 
	return 0; 
}
