/*
Q2 Implement a parent process, which sends an English alphabet to a child process
using shared memory. The child process responds with the next English alphabet
to the parent. The parent displays the reply from the Child.

Sender

*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

struct shared {
    int turn;
    char ch;
};


int main() {
    void *sharedMemory = (void *) 0;
    pid_t cpid;
    struct shared *data;

    int shmid = shmget((key_t)1234, sizeof(struct shared), 0666 | IPC_CREAT);

    if (shmid == -1) {
        fprintf(stderr, "shmget failed\n");
        exit(EXIT_FAILURE);
    }

    sharedMemory = shmat(shmid, (void *)0, 0);

    if (sharedMemory == (void *)-1) {
        fprintf(stderr, "shmat failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Memory attached at %X\n", sharedMemory);
    data = (struct shared *)sharedMemory;
    data->turn = 1;

    cpid = fork();

    if (cpid == 0){
        while(data -> turn == 1)
            sleep(1);
        data->ch = data->ch + 1;
        data->turn = 1;
    }
    else { // Parent Process (Turn == 1)

        char ch;
        printf("Enter a character ");
        scanf("%c", &ch);
        data->ch = ch;
        data->turn = 0;

        while (data->turn == 0)
            sleep(1);

        printf("Received character: %c\n", data->ch);

    }

    if (shmdt(sharedMemory) == -1) {
        printf("Shared Memory deletion failed\n");
        exit(1);
    }
}
