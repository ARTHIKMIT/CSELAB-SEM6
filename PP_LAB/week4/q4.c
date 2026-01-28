#include <mpi.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int rank, size, flag = 0;
    char word[100], char_to_process;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        printf("Enter a word (length should match process count %d): \n", size);
        scanf("%s", word);
        if(strlen(word) != size)flag = 1;
    }
    MPI_Bcast(&flag, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if(flag == 0){
        if(rank == 0)fprintf(stderr, "Size of string i not equal to no of processes\n");
        MPI_Finalize();
        exit(0);
    }

    MPI_Scatter(word, 1, MPI_CHAR, &char_to_process, 1, MPI_CHAR, 0, MPI_COMM_WORLD);

    int repeat = rank + 1;
    char *send_buffer = (char*)malloc((repeat+1) * sizeof(char));

    for (int i = 0; i < repeat; i++) {
        send_buffer[i] = char_to_process;
    }
    send_buffer[repeat] = '\0';

    if (rank == 0) {
        char final_word[100];
        final_word[0] = send_buffer[0];

        int cursor = 1;

        for (int i = 1; i < size; i++) {
            MPI_Status mpis;
            char recv_str[100];
            MPI_Recv(recv_str, i+2, MPI_CHAR, i, i, MPI_COMM_WORLD, &mpis);
            for (int j = 0; j < (i + 1); j++) {
                if(recv_str[j]!='\0')final_word[cursor++] = recv_str[j];
            }
        }
        final_word[cursor] = '\0';

        printf("Output: %s\n", final_word);
    }else{
        MPI_Send(send_buffer, repeat, MPI_CHAR, 0, rank, MPI_COMM_WORLD);
    }

    free(send_buffer);
    MPI_Finalize();
    return 0;
}