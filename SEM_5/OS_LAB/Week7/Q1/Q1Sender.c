/*
Q1 Process A wants to send a number to Process B. Once received, Process B has to check whether the number is palindrome or not. Write a C program to implement this
interprocess communication using a message queue.

Sender

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg {
    long int type;
    int num;
};

int main() {
    int running = 1;
    struct msg data;
    int msgid, num;

    msgid = msgget((key_t)1234, 0666 | IPC_CREAT);

    if (msgid == -1) {
        fprintf(stderr, "msgget failed with error: %d\n", errno);
        exit(EXIT_FAILURE);
    }

    while(running) {
        printf("Enter a number :");
        //fgets(&num, sizeof(int), stdin);
        scanf("%d", &num);
        data.type = 1;
        data.num = num;
        if (msgsnd(msgid, (void *)&data, sizeof(data), 0) == -1) {
            fprintf(stderr, "msgsnd failed\n");
            exit(EXIT_FAILURE);
        }
        if (num == 0)
            running = 0;
    }
    exit(EXIT_SUCCESS);
}
