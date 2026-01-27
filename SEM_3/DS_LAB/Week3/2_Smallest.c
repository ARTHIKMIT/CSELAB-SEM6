/* Write a function Smallest to find the smallest element in an array using pointer.
Create a dynamically allocated array and read the values from keyboard in main.
Display the result in the main function.*/

#include <stdio.h>
#include <stdlib.h>

int Smallest(int *a, int n)
{
	int smallest = *a;
	for (int i=0; i<n; i++)
		if (smallest > *(a+i))
			smallest = *(a+i);
	return smallest;
}

void main()
{
	int n, i, *arr;
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	arr = calloc(n, sizeof(int));
	for (i=0; i<n; i++)
		scanf("%d", &arr[i]);
	
	int s = Smallest(arr, n);

	printf("The smallest element is : %d ", s);
}