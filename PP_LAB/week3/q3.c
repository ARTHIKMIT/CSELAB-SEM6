#include <mpi.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_vowel(char c)
{
    c = tolower(c);
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

int main(int argc, char *argv[])
{
    int rank, size, len, part, count = 0, total;
    char str[100], sub[20];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
    {
        printf("Enter string: ");
        scanf("%s", str);
        len = strlen(str);
    }

    MPI_Bcast(&len, 1, MPI_INT, 0, MPI_COMM_WORLD);

    part = len / size;

    MPI_Scatter(str, part, MPI_CHAR, sub, part, MPI_CHAR, 0, MPI_COMM_WORLD);

    for (int i = 0; i < part; i++)
        if (!is_vowel(sub[i]))
            count++;

    printf("Process %d non-vowels = %d\n", rank, count);

    MPI_Reduce(&count, &total, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
        printf("Total non-vowels = %d\n", total);

    MPI_Finalize();
    return 0;
}
