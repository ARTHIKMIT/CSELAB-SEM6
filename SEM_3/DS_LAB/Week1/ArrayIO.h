// Function to input and output a 1D Array
#include<stdio.h>

void Input1DArray(int arr[], int *n)
{
	int i;
	printf("Enter the number of array elements : \n");
	scanf("%d",n);
	printf("\nEnter the array elements : \n");
	for (i=0;i<*n;i++)
		scanf("%d",&arr[i]);
}

void Display1DArray(int arr[], int n)
{
	int i;
	printf("\nThe array elements are : \n");
	for (i=0;i<n;i++)
		printf("%d\t",arr[i]);
	printf("\n");
}

// Function to input and output a 2D Array
#include<stdio.h>

void Input2DArray(int arr[][15], int *r, int *c)
{
	int i, j;
	printf("Enter the matrix size : \n");
	scanf("%d %d",r, c);
	printf("\nEnter the array elements : \n");
	for (i=0;i<*r;i++)
	{
		for (j=0;j<*c;j++)
			scanf("%d",&arr[i][j]);
		printf("\n");
	}
}

void Display2DArray(int arr[][15], int r, int c)
{
	int i, j;
	printf("\nThe array is : \n");
	for (i=0;i<*r;i++)
	{
		printf("\n");
		for (j=0;j<*c;j++)
			printf("%d\t",arr[i][j]);
	}
}