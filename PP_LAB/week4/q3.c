#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int rank, size;
    int matrix[4][4], row[4], result_row[4];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if(size != 4){
        if(rank == 0)fprintf(stderr, "Only four processes can execute this program\n");
        MPI_Finalize();
        exit(0);
    }

    if (rank == 0) {
        printf("Enter 4x4 matrix:\n");
        for(int i=0; i<4; i++) for(int j=0; j<4; j++)scanf("%d", &matrix[i][j]);
    }

    MPI_Scatter(matrix, 4, MPI_INT, row, 4, MPI_INT, 0, MPI_COMM_WORLD);

    MPI_Scan(row, result_row, 4, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    int output_matrix[4][4];
    MPI_Gather(result_row, 4, MPI_INT, output_matrix, 4, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Output Matrix:\n");
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) printf("%d ", output_matrix[i][j]);
            printf("\n");
        }
    }

    MPI_Finalize();
    return 0;
}