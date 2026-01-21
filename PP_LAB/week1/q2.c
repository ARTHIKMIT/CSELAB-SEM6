#include<stdio.h>
#include<mpi.h>


    void main(int argc, char *argv[]){
    int ierr, rank, size, flag = 1, res = 0, a = 4, b = 2;
    char op[] = "+-*/";
    ierr = MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    switch(rank){
        case 0:
            res = a+b;
            break;
        case 1:
            res = a-b;
            break;
        case 2:
            res = a*b;
            break;
        case 3:
            res = a/b;
            break;
        default:
            flag = 0;
    }
    if (flag)
        printf("%d of %d is Calculating! %d = %d %c %d \n", rank, size, res, a, op[rank], b);
    else printf("Too many threads!\n");
    MPI_Finalize();
}