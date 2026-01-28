/* 
Find 1! + 2! + .... + N!. Using collective communication
*/
#include<stdio.h>
#include "mpi.h"


void main(int argc, char *argv[]){
    int rank, size, fact = 1, factsum;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    for (int i=1; i<=rank; i++)
        fact = fact * i;

    printf("%d factorials is %d\n", rank, fact);

    MPI_Reduce(&fact, &factsum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if(rank == 0) 
        printf("Sum of all factorials is %d\n", factsum);
    MPI_Finalize();
}