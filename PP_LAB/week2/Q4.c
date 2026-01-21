/*
Q4 Read an Integer value in root the p and send it to p1, using Point to point communication routines, which increments it by 1 sends it to p2 and so on. the last p sends it back to the root. */

#include <stdio.h>
#include <mpi.h>

void main(int argc, char *argv[]){
    int ierr, rank, size, num;

    ierr = MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;

    if (rank == 0){
        printf("Enter a number : ");
        scanf("%d", &num);
        MPI_Send(&num, 1, MPI_INT, rank+1, 0, MPI_COMM_WORLD);
        MPI_Recv(&num, 1, MPI_INT, size-1, 0, MPI_COMM_WORLD, &status);
        printf("The Number is : %d\n", num);
    }
    else {
        MPI_Recv(&num, 1, MPI_INT, rank-1, 0, MPI_COMM_WORLD, &status);
        num++;
        MPI_Send(&num, 1, MPI_INT, (rank+1)%size, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
}