/*
1) Write a program to create a heap for the list of integers using top-down heap construction algorithm and 
analyze its time efficiency. Obtain the experimental results for order of growth and plot the result.
*/

#include <stdio.h>

int opCount = 0;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int heap[], int i) {
    int parent = (i - 1) / 2; // Parent index
    //Max Heap
    while (i > 0 && heap[i] > heap[parent]) {
        opCount += 1; //Swapping
        swap(&heap[i], &heap[parent]);  // Swapping with parent if larger
        i = parent;  // Updating i to the parent index
        parent = (i - 1) / 2;  // Updating parent index
    }
}

void printArr(int arr[], int n){
  for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void buildHeap(int arr[], int n) {
    int heap[n];

    for (int i = 0; i < n; i++) {
        opCount += 1; //Inserting Element
        heap[i] = arr[i];
        insert(heap, i);
        printf("Inserting %d : ", arr[i]);
        printArr(heap, i+1);
    }

    printf("Heap after building (top-down):\n");
    printArr(heap, n);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};//{1, 9, 6, 4, 3, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArr(arr, n);
    
    buildHeap(arr, n);
    printf("It took %d Operations.", opCount);
    return 0;
}
