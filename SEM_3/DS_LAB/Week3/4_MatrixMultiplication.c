/* Implement a C program to read, display and to find the product of two matrices using
functions with suitable parameters. Note that the matrices should be created using
dynamic memory allocation functions and the elements are accessed using array
dereferencing.*/

#include <stdio.h>
#include <stdlib.h>

void Input2DArray(int **Mat, int r, int c)
{
	for (int i=0;i<r;i++)
	{
		for ( int j=0;j< c;j++)
			scanf("%d",*(Mat+i)+j);
	
	}
}

void Display2DArray(int **arr, int r, int c)
{
	printf("\nThe array is : \n");
	for (int i=0;i<r;i++)
	{
		printf("\n");
		for (int j=0;j<c;j++)
			printf("%d\t",*(*(arr+i)+j));
	}
}

void MatrixMutiplication(int **Mat1, int **Mat2, int **Mat3, int r, int c, int n)
{
	for (int i=0; i<r; i++)
		for (int j=0; j<n; j++)
		{
			*(*(Mat3+i)+j) = 0;
			for(int k=0; k<c; k++)
				*(*(Mat3+i)+j) += *(*(Mat1+i)+k) * *(*(Mat2+k)+j);
		}
}

void main()
{
	int **Mat1, r, c;
	printf("Enter the number of rows and coloumns : ");
	scanf("%d %d",&r, &c);
	printf("\n");
	Mat1 = (int**) malloc(r*sizeof(int*));
	for (int i=0;i<r;i++)
		Mat1[i] = calloc(c, sizeof(int));
	Input2DArray(Mat1, r, c);

	int **Mat2, m, n;
	printf("Enter the number of rows and coloumns : ");
	scanf("%d %d",&m, &n);
	printf("\n");
	Mat2 = (int**) malloc(m*sizeof(int*));
	for (int i=0;i<m;i++)
		Mat2[i] = calloc(n, sizeof(int));
	Input2DArray(Mat2, m, n);
	
	if (c == m)
	{
		int **Mat3;
		Mat3 = (int**) malloc(r*sizeof(int*));
		for (int i=0;i<r;i++)
			Mat3[i] = calloc(n, sizeof(int));
		MatrixMutiplication(Mat1, Mat2, Mat3, r, c, n);
		Display2DArray(Mat3, r, n);
	}
	else printf("Cannot multiply.");
}