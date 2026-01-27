/*
Q3 Write two programs named Interface and Display for the following problem.

Display program

The process waits until a new message becomes available on the shared memory. Then it reads the contents of the memory and prints it on the screen. It also clears the contents of the shared memory when it has read the message.
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

    int shmid;
    srand((unsigned int)getpid());
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
    data->turn = 0;
    char prev[2048];

    while(running) {
        //if (data->turn) {
        if (data->text != '\0'){
            printf("You wrote: %s", data->text);
            //sleep( rand() % 4 ); /* make the other process wait for us ! */
            //data->turn = 0;
            //data->text = '\0';
            memset(data->text, ‘\0’, TEXT_SZ);
            if (strncmp(data->text, "end", 3) == 0) {
                running = 0;
            }
        }
    }

    if (shmdt(sharedMemory) == -1) {
        fprintf(stderr, "shmdt failed\n");
        exit(EXIT_FAILURE);
    }

    if (shmctl(shmid, IPC_RMID, 0) == -1) {
        fprintf(stderr, "shmctl(IPC_RMID) failed\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
