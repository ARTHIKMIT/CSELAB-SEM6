// Function to input an array

#include<stdio.h>

void InputArray(int arr[], int *n)
{
	int i;
	printf("Enter the number of array elements : \n");
	scanf("%d",n);
	printf("\nEnter the array elements : \n");
	for (i=0;i<*n;i++)
		scanf("%d",&arr[i]);
}

void DisplayArray(int arr[], int n)
{
	int i;
	printf("\nThe array elements are : \n");
	for (i=0;i<n;i++)
		printf("%d\t",arr[i]);
	printf("\n");
}

// Function to swap array elements at positions x and y
void Swap(int arr[], int x, int y)
{
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

// Function for Selection Sort
void SelectionSort(int arr[], int n)
{
	int pass, i, minIndex;

	for (pass=0; pass<n-1; pass++)
	{
		// Finding Min element
		minIndex = pass;
		for (i=pass+1; i<n; i++)

			if (arr[i]<arr[minIndex])
				minIndex = i;
		
		// Swapping
		if (minIndex != pass)
			Swap(arr, minIndex, pass);

	}
}