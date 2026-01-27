/* 
2) Write a program to sort the list of integers using heap sort with bottom up max heap construction and 
analyze its time efficiency. Prove experimentally that the worst case time complexity is O(n log n)
*/

#include <stdio.h>

int opCount = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void heapify(int heap[], int n) {
    // Iterate from the last non-leaf (parent) node to the root
    // i -> current Index, j -> index to heapify, v -> value to heapify
    for (int i = n / 2; i >= 0; i--) {
        int j = i;
        int v = heap[j];
        int heapifyComplete = 0;

        while (!heapifyComplete && 2 * j < n) {
            opCount += 2; //Comparision -> can be 2
            int largestChildIndex = 2 * j;

            // if the right child exists and is > left child
            if (largestChildIndex + 1 < n && heap[largestChildIndex] < heap[largestChildIndex + 1]) {
                largestChildIndex += 1;  // Right child is larger
            }

            // If value >= largest child
            if (v >= heap[largestChildIndex]) {
                heapifyComplete = 1;
            } else {
                // Swap with the largest child and continue heapifying
                heap[j] = heap[largestChildIndex];
                j = largestChildIndex;
            }
        }

        // Placing value in the correct position
        heap[j] = v;
    }
}


void heapSort(int arr[], int n) {

    heapify(arr, n);
    printArray(arr, n);
    for (int i = n - 1; i >= 1; i--) {
        //opCount+=1; //Swapping
        // Swapping root (max) element with the last element
        swap(&arr[0], &arr[i]);

        // heapify the reduced heap (by 1 each iter)
        heapify(arr, i);
    }
}

int main() {
    int arr[] = {1 ,2, 3, 4, 5, 6, 7, 8, 9, 10};  //{4, 10, 3, 5, 1};  // Example array
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Array after Heap Sort: \n");
    printArray(arr, n);
    printf("It took %d Operations.", opCount);
    return 0;
}
