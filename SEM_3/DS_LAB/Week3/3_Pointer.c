/* Write a C program to
a) Demonstrate passing pointers to a function.
b) Demonstrate Returning pointer from a function.
c) c) Using pointer to pointer.*/

#include <stdio.h>
#include <stdlib.h>

int* Input2DArray(int **Mat, int r, int c, int *n)
{
	for (int i=0;i<r;i++)
	{
		for ( int j=0;j< c;j++)
			scanf("%d",*(Mat+i)+j);
		printf("\n");
	}
	*n=r*c;
	return n;
}

void main()
{
	int **Mat1, r, c, *pn, n;
	printf("Enter the number of rows and coloumns : ");
	scanf("%d %d",&r, &c);
	printf("\n");
	Mat1 = (int**) malloc(r*sizeof(int*));
	for (int i=0;i<r;i++)
		Mat1[i] = calloc(c, sizeof(int));
	pn = &n;
	pn = Input2DArray(Mat1, r, c, pn);
	printf("Number of elements is %d",n);
}