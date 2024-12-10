#include<stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Selection Sort
void selection(int arr[], int n) {
    for (int i = 0; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {  // Changed i to j
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

// Insertion Sort
void insertion(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// Partition function for QuickSort
int Partition(int arr[], int low, int high) {
    int pi = arr[low];
    int i = low, j = high;
    while (i < j) {
        while (arr[i] <= pi && i <= high - 1) {
            i++;
        }
        while (arr[j] > pi && j >= low) {  // Fixed condition here
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = Partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Heapify function for HeapSort
void heapify(int arr[], int n, int i) {
    int root = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[root]) {
        root = left;
    }
    if (right < n && arr[right] > arr[root]) {
        root = right;
    }
    if (root != i) {
        swap(&arr[root], &arr[i]);
        heapify(arr, n, root);
    }
}

// HeapSort function
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

//MergeSort
void Merge(int arr[],int temp[],int start1,int end1, int start2, int end2)
{
    int i=start1;
    int j=start2 ; 
    int k=start1;
    while (i<=end1 && j<=end2)
    {
            if(arr[i]<=arr[j])
            {
                temp[k]=arr[i];
                i++;k++;
            }
            else
            {
                temp[k]=arr[j];
                j++;k++;
            }
    }
    while (i<=end1)
    {
        temp[k]=arr[i];
        i++;k++;
    }
    while(j<=end2)
    {
        temp[k]=arr[j];
        j++;k++;
    }
    for(i=start1;i<=end2;i++)
    {
        arr[i]=temp[i];
    }
}
void MergeSort(int arr[],int temp[],int start, int end)
{
    if (start<end)
    {
        int middle=(start+end)/2;
        MergeSort(arr,temp,start,middle);
        MergeSort(arr,temp,middle+1,end);
        Merge(arr,temp,start,middle,middle+1,end);
    }
}
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    // You can call any sorting function here, e.g., quickSort(arr, 0, n-1);
    quickSort(arr, 0, n - 1);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
