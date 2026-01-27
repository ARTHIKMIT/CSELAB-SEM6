// Find triplets in an array whose sum is zero taking the array as input. 
// (Triplets Game)

#include<stdio.h>

int main()
{
	int i, j, k, n, a[10], sum;

	//Input
	printf("Enter the number of array elements : \n");
	scanf("%d",&n);
	printf("\nEnter the array elements : \n");
	for (i=0;i<n;i++)
		scanf("%d",&a[i]);

	//Checking For Triplets
	for (i=0;i<n-2;i++)
	{
		for (j=i+1;j<n-1;j++)
		{
			for (k=j+1;k<n;k++)
			{
				sum = a[i] + a[j] + a[k];
				if (sum == 0)
					printf("\nFound Triplets - %d %d %d\n",a[i],a[j],a[k]);
			}
		}
	}
	return 0;
}