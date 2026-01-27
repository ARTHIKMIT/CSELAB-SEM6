/*
Q1 Write a C program to block a parent process until the child completes using a wait system call.
*/

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    pid_t pid;
    int status;

    pid = fork();

    if(pid == -1){
        printf("ERROR child not created");
        exit(1);
    }
    else if (pid == 0) { /* child process */
        printf("I'm the child! ");
        exit(0);
    }

    else { /* parent process */
        wait(&status);
        printf("\nI'm the parent!");
        printf("\nChild returned: %d\n", status);
        exit(0);
    }
}
