/*
3) Sort the given set of integers using Merge sort and display the number of inversions performed during the merging step. 
Obtain the experimental result of order of growth by analysing its efficiency and plot the result.
*/

#include <stdio.h>
#include <stdlib.h>

int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left, inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (i = left; i <= right; i++) arr[i] = temp[i];

    return inv_count;
}

int mergeAndCount(int arr[], int temp[], int left, int right) {
    int mid, i, j, k;
    int inv_count = 0;

    if (left < right) {
        mid = (left + right) / 2;
        inv_count += mergeAndCount(arr, temp, left, mid);
        inv_count += mergeAndCount(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid, right);
    }

    return inv_count;
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: \n");
    printArray(arr, n);

    int* temp = (int*)malloc(sizeof(int) * n);
    int inversions = mergeAndCount(arr, temp, 0, n - 1);
    free(temp);

    printf("Sorted Array: \n");
    printArray(arr, n);

    printf("Number of inversions: %d\n", inversions);

    return 0;
}
