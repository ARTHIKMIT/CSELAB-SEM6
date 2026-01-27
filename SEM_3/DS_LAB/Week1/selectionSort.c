// Selection Sort

#include <stdio.h>
#include "selectionSort.h"

void main()
{
	int n, arr[10];

	InputArray(arr, &n);
	
	SelectionSort(arr, n);

	DisplayArray(arr, n);

}