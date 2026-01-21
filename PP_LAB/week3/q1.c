#include <mpi.h>
#include <stdio.h>

int fact(int n)
{
    int f = 1;
    for (int i = 1; i <= n; i++)
        f *= i;
    return f;
}

int main(int argc, char *argv[])
{
    int rank, size, A[10], f, F[10], i, sum = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
    {
        printf("Enter %d values:\n", size);
        for (i = 0; i < size; i++)
            scanf("%d", &A[i]);
    }

    MPI_Scatter(A, 1, MPI_INT, &f, 1, MPI_INT, 0, MPI_COMM_WORLD);

    f = fact(f);

    MPI_Gather(&f, 1, MPI_INT, F, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        for (i = 0; i < size; i++)
            sum += F[i];
        printf("Sum of factorials = %d\n", sum);
    }

    MPI_Finalize();
    return 0;
}
