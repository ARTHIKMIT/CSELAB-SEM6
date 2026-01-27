/*
2) Write a program to implement Floyd’s algorithm for the All-Pairs- Shortest-Paths problem for any given graph 
and analyse its time efficiency. Obtain the experimental results for order of growth and plot the result.
*/

#include <stdio.h>
#include <stdlib.h>

void floyd(int ** mat, int n) {
    int i, j, k, opCount = 0;
    
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) {
                opCount++;
                if (mat[i][j] > mat[i][k] + mat[k][j])
                    mat[i][j] = mat[i][k] + mat[k][j];
            }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) 
            printf("%d ",mat[i][j]);
        printf("\n");
    }
    printf("It took %d Operations.",opCount);
}

void main() {

    int i, j, n;
    printf("Enter number of vertices ");
    scanf("%d",&n);

    int ** adjMat = calloc(n, sizeof(int *));

    for(i = 0; i < n; i++) 
        adjMat[i] = (int *) calloc(n,sizeof(int));
    
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++) {
            printf("Enter a[%d][%d] ",i,j);
            scanf("%d",&adjMat[i][j]);
        }

    floyd(adjMat,n);

}