/*
1) Write a program to find Minimum Cost Spanning Tree of a given undirected graph 
using Kruskal's algorithm and analyse its time efficiency.
*/
#include <stdio.h>
#include <stdlib.h>

int opCount = 0;

int warshall(int ** mat, int n, int c) {
    if (c == n) {
        for(int i = 0; i < n; i++) {
            int flag = 1;
            for(int j = 0; j < n; j++) {
                (opCount)++;
                if (mat[i][j] == 0)
                    flag = 0;
            }
            if (flag == 1)
                return 1;
        }
        return 0;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            (opCount)++;
            if ((mat[i][j] == 1) || (mat[i][c] == 1 && mat[c][j] == 1))
                mat[i][j] = 1;
        }

    return warshall(mat, n, c+1);
}

void main() {
    int n;
    printf("Enter number of vertices ");
    scanf("%d",&n);

    int ** adjMat = (int **) calloc(n, sizeof(int *));
    for(int i = 0; i < n; i++) 
        adjMat[i] = (int *) calloc(n,sizeof(int));
    
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) {
            printf("Enter a[%d][%d] ",i,j);
            scanf("%d",&adjMat[i][j]);
        }

    if (warshall(adjMat,n,0) == 1) 
        printf("The matrix exhibits transitive closure.");
    else
        printf("The matrix does not exhibit transitive closure.");
    printf("\nIt took %d operations.",  opCount);
}