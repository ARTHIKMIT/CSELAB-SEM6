/*
Q4 Even ranked p prints factorial of rank and odd prints the rank's fibonacci number.
*/

#include <stdio.h>
#include <mpi.h>

int fact(int n){
    if (n == 0)
        return 1;
    else return n*fact(n-1);
}

int fib(int ind){
    if (ind == 0)
        return 0;
    if (ind == 1)
        return 1;
    else return fib(ind-1) + fib(ind-2);
}

void main(int argc, char *argv[]){
    int ierr, rank, size, res;
    char s[] = "hello";
    ierr = MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank % 2 == 0)
        printf("%d of %d is even and its factorial is %d\n", rank, size, fact(rank));
    else printf("%d of %d is odd and its fibonacci number is %d\n", rank, size, fib(rank)); 
    
    MPI_Finalize();
}