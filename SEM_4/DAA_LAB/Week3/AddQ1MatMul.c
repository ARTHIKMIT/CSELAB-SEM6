/* 1). Write a program to implement matrix multiplication using brute-force technique
and analyze its time efficiency. Obtain the experimental result of order of
growth. Plot the result for the best and worst case.*/

#include <stdio.h>

void mul(int A[][10], int B[][10], int C[][10], int m, int n, int p, int q){
	int opCount = 0;
	for(int i=0; i<m; i++)
		for(int j=0; j<q; j++){
			C[i][j] = 0;
			for(int k=0; k<n; k++){
				C[i][j] += A[i][k] * B[k][j];
				++opCount;
			}
		}
	printf("Op Count is %d \n", opCount);
}

void disp(int mat[][10], int m ,int n){
	printf("Matrix : \n");
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}

int main(){
	int m, n, p, q;
	int A[10][10], B[10][10], C[10][10];
	printf("Matrix 1 :\n");
	printf("Rows : ");
	scanf("%d",&m);
	printf("Columns : ");
	scanf("%d",&n);
	printf("Values : \n");
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &A[i][j]);

	printf("Matrix 2 :\n");
	printf("Rows : ");
	scanf("%d",&p);
	printf("Columns : ");
	scanf("%d",&q);
	printf("Values : \n");
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &B[i][j]);

	if (n != p)
		printf("Incompatible.");
	else {
		mul(A, B, C, m, n, p, q);
		disp(C, m, q);
	}
}