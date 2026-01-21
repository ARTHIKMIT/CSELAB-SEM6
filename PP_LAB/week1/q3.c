/*
Q3 Toggle char of given string indexed by rank

*/

#include <stdio.h>
#include <mpi.h>
#include <string.h>

void main(int argc, char *argv[]){
    int ierr, rank, size, res;
    char s[] = "hello";
    ierr = MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank < strlen(s)){
        s[rank] -= 32;
        printf("%d of %d is running! The String is %s \n", rank, size, s);
    }
    else printf("Too many threads!\n");
    MPI_Finalize();
}