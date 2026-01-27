/*
Q1 Process A wants to send a number to Process B. Once received, Process B has to check whether the number is palindrome or not. Write a C program to implement this
interprocess communication using a message queue.

Receiver

*/

#include <stdio.h>
#include <stdlib.h>
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

int isPalindrome(int num){
    int n = num;
    int rev = 0;
    while (n){
        int d = n%10;
        rev = rev*10 + d;
        n = n / 10;
    }
    //printf("%d %d", rev, num);
    return (rev == num);
}

int main() {
    int running = 1;
    int msgid;
    struct msg data;
    long int msgReceived = 0;

    msgid = msgget((key_t)1234, 0666 | IPC_CREAT);

    if (msgid == -1) {
        fprintf(stderr, "msgget failed with error: %d\n", errno);
        exit(EXIT_FAILURE);
    }

    while(running) {
        if (msgrcv(msgid, (void *)&data, sizeof(data), msgReceived, 0) == -1) {
            fprintf(stderr, "msgrcv failed with error: %d\n", errno);
            exit(EXIT_FAILURE);
        }
        printf("You wrote: %d\n", data.num);
        if (isPalindrome(data.num))
            printf("It is a Palindrome\n");
        else printf("It is not a Palindrome\n");
        if (data.num == 0)
            running = 0;
    }
    if (msgctl(msgid, IPC_RMID, 0) == -1) {
        fprintf(stderr, "msgctl(IPC_RMID) failed\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
