/*
Q3 Write two programs named Interface and Display for the following problem.

Interface program

This program, when run, gives a prompt to the user as “Enter your message:”When the user enters his/her message string and presses Enter, the program writes the message into the shared memory, tells the Display to start processing,and then prompts the user again for another message.
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "shm_com.h"

int main() {
    int running = 1;
    void *sharedMemory = (void *)0;

    struct shared *data;

    char buffer[BUFSIZ];
    int shmid;

    shmid = shmget((key_t)1234, sizeof(struct shared), 0666 | IPC_CREAT);

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

    while(running) {
        /*
        while(data->turn == 1) {
            sleep(1);
            printf("waiting for client...\n");
        }
        */
        printf("Enter some text:");
        fgets(buffer, BUFSIZ, stdin);
        strncpy(data->text, buffer, TEXT_SZ);
        //data->turn = 1;
        if (strncmp(buffer, "end", 3) == 0)
            running = 0;
    }
    if (shmdt(sharedMemory) == -1) {
        fprintf(stderr, "shmdt failed\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
