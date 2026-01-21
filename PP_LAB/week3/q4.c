#include <mpi.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int rank, size, len, part, i;
    char s1[100], s2[100], r1[50], r2[50], result[200];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
    {
        printf("Enter string S1: ");
        scanf("%s", s1);
        printf("Enter string S2: ");
        scanf("%s", s2);
        len = strlen(s1);
    }

    MPI_Bcast(&len, 1, MPI_INT, 0, MPI_COMM_WORLD);

    part = len / size;

    MPI_Scatter(s1, part, MPI_CHAR, r1, part, MPI_CHAR, 0, MPI_COMM_WORLD);
    MPI_Scatter(s2, part, MPI_CHAR, r2, part, MPI_CHAR, 0, MPI_COMM_WORLD);

    char local[100];
    int k = 0;
    for (i = 0; i < part; i++)
    {
        local[k++] = r1[i];
        local[k++] = r2[i];
    }

    MPI_Gather(local, 2 * part, MPI_CHAR, result, 2 * part, MPI_CHAR, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        result[2 * len] = '\0';
        printf("Resultant String: %s\n", result);
    }

    MPI_Finalize();
    return 0;
}
