/* 
1. Find 1! + 2! + .... + N!. Using scan. Handle different errors using error handling routines
*/
#include<stdio.h>
#include <mpi.h>

void ErrorHandler(int err_code) {
    if(err_code != MPI_SUCCESS) {
        
        char error_string[BUFSIZ];
        int length_err_string, err_class;
        
        MPI_Error_class(err_code, &err_class);
        MPI_Error_string(err_code, error_string, &length_err_string);
        
        printf("Error: %d %s\n", err_class, error_string);
    }
}

void main(int argc, char *argv[]){
    int rank, size, fact = 1, factsum, error_code, value;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    MPI_Errhandler_set(MPI_COMM_WORLD, MPI_ERRORS_RETURN);

    value = rank + 1;
    error_code = MPI_Scan(&value, &fact ,1, MPI_INT, MPI_PROD,MPI_COMM_WORLD);
    ErrorHandler(error_code);
    
    error_code = MPI_Scan(&fact, &factsum, 1,MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    ErrorHandler(error_code);

    printf("%d factorials is %d\n", value, fact);

    if(rank == size-1) 
        printf("Sum of all factorials is %d\n", factsum);
    MPI_Finalize();
}