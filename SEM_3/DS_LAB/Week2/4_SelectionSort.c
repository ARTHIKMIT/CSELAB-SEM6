//To implement selection sort using recursion
#include <stdio.h>

void SelectionSort(int a[], int n)
{
	if (n == 1)
		return;
	int i, temp, minIndex = 0;
	//Select
	for (i=0; i<n; i++)
		if (a[i] < a[minIndex])
			minIndex = i;
	//Sort
	temp = a[0];	
	a[0] = a[minIndex];
	a[minIndex] = temp;
	SelectionSort(a+1,--n);
}

void main()
{
	int n, i;
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	int a[n];
	for (i=0; i<n; i++)
		scanf("%d", &a[i]);
	
	SelectionSort(a, n);
	for (i=0; i<n; i++)
		printf("%d ", a[i]);
}