#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int rank, size, M, i;
    float A[100], sub[10], avg, avgs[10], total_avg;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
    {
        printf("Enter M: ");
        scanf("%d", &M);

        printf("Enter %d values:\n", M * size);
        for (i = 0; i < M * size; i++)
            scanf("%f", &A[i]);
    }

    MPI_Bcast(&M, 1, MPI_INT, 0, MPI_COMM_WORLD);

    MPI_Scatter(A, M, MPI_FLOAT, sub, M, MPI_FLOAT, 0, MPI_COMM_WORLD);

    avg = 0;
    for (i = 0; i < M; i++)
        avg += sub[i];
    avg /= M;

    MPI_Gather(&avg, 1, MPI_FLOAT, avgs, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        total_avg = 0;
        for (i = 0; i < size; i++)
            total_avg += avgs[i];
        total_avg /= size;
        printf("Total Average = %f\n", total_avg);
    }

    MPI_Finalize();
    return 0;
}
