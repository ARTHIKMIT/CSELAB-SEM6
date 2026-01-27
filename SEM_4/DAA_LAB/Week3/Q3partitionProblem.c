/* 3). Write a program to implement solution to partition problem using brute-force
technique and analyze its time efficiency theoretically. A partition problem takes
a set of numbers and finds two disjoint sets such that the sum of the elements in
the first set is equal to the second set. [Hint: You may generate power set] */

#include <stdio.h>
#include <stdlib.h>

int calculateSum(int arr[], int n){
	int sum=0;
	for(int i=0; i<n; i++)
		sum+=arr[i];
	return sum;	
}

int canPartition(int arr[], int n, int sum){
	if (sum==0)
		return 1;
	if (n==0)
		return 0;
	if(arr[n-1] > sum)
		return canPartition(arr, n-1, sum);
	return canPartition(arr, n-1, sum) || canPartition(arr, n-1, sum-arr[n-1]);
}
int isPartitionPossible(int arr[], int n){
	int sum = calculateSum(arr, n);
	if (sum%2!=0) return 0;
	return canPartition(arr, n, sum/2);
}
int main(){
	int arr[] = {1,5,11,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	if (isPartitionPossible(arr, n))
		printf("Partition possible!");
	else printf("Partition not possible!");
	return 0;
}