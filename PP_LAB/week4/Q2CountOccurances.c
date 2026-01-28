/* 
2. Read a 3 X 3 Matrix. Enter an element to be searched in the root process, find the number of times it occurs using 3 processes.
*/
#include<stdio.h>
#include <mpi.h>


void main(int argc, char *argv[]){
    int rank, size, arr[3][3], x, array[3], count = 0, ans;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0){
        printf("Enter the 9 elements ROW wise : \n");
        for (int i=0; i<3; i++)
            for (int j=0; j<3; j++)
                scanf("%d", &arr[i][j]);
        printf("Enter the element to search : \n");
        scanf("%d", &x);
    }
    
    MPI_Bcast(&x, 1, MPI_INT, 0, MPI_COMM_WORLD);
    
    MPI_Scatter(arr, 3, MPI_INT, array, 3, MPI_INT, 0, MPI_COMM_WORLD);
    
    for(int i = 0; i < 3; i++)
        if(array[i] == x) 
            count++;
    
    MPI_Reduce(&count, &ans, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if(rank == 0) 
        printf("Number of occurances = %d\n", ans);
    MPI_Finalize();
}