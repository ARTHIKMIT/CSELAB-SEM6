/* To reverse the elements of an integer array using pointer and function
Access the elements of the array using dereference operator. Read the values from
the keyboard in main function. Display the result in the main function.*/

#include <stdio.h>

void Reverse(int *a, int n)
{
	int i, temp;
	for (i=0; i<n/2; i++)
	{
		temp = *(a+i);
		*(a+i) = *(a+n-i-1);
		*(a+n-i-1) = temp;
	}
}

void main()
{
	int n, i;
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	int a[n];
	for (i=0; i<n; i++)
		scanf("%d", a+i);
	
	Reverse(a, n);

	for (i=0; i<n; i++)
		printf("%d ", *(a+i));
}