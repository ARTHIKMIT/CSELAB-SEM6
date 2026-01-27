/* 1). Write a program to sort set of integers using bubble sort. Analyze its time
efficiency. Obtain the experimental result of order of growth. Plot the result for
the best and worst case. */

#include <stdio.h>

void bubbleSort(int arr[], int n){
	int opCount = 0;
	int flag = 1;
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(arr[j]>arr[j+1]){
				flag = 0;
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				opCount++;
			}
		if (flag) break;
		}
	}
	printf("Op Count is %d\n",opCount);
}

int main(){
	int i, n;
	int arr[100];
	scanf("%d",&n);
	for(i=0; i<n; i++)
		scanf("%d",&arr[i]);
	bubbleSort(arr, n);
	for(i=0; i<n; i++)
		printf("%d ",arr[i]);
	return 0;
}