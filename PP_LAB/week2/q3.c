/*
Q3 Read N elements of an aray in the root p (rank 0) where N = Total number of Ps. Using Buffered Send, send one val to each slave and let the even ranked ones find the square of the received element and the odd ones the cube.

*/

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

void main(int argc, char *argv[]){
    int ierr, rank, size, num, res;

    ierr = MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;

    int *arr = calloc(size, sizeof(int));
    
    if (rank == 0){
        for (int i=0; i<size; i++){
            printf("Element %d: ", i+1);
            scanf("%d", &arr[i]);
    
            int bufSize = 96+size;
            int *buf = calloc(bufSize, sizeof(int));

            MPI_Buffer_attach(buf, bufSize);
            
            if (i != 0)
                MPI_Bsend(&arr[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
            
            MPI_Buffer_detach(&buf, &bufSize);
        }
        num = arr[0];
    }
    else MPI_Recv(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
    
    if (rank % 2 == 0)
        res = num*num;   
    else res = num*num*num;
    printf("%d of %d received %d and found %d!\n", rank, size, num, res);
    
    MPI_Finalize();
}