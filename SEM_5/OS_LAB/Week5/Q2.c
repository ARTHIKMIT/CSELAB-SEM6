/*
Q2 Write a C program to load the binary executable of the previous program in a child process using the exec system call.
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

    if(pid < 0)
        printf("ERROR child not created");

    else if (pid == 0) { /* child process */
        printf("I'm the Child!");
        execlp("./Q1", "Q1", NULL);
        exit(0);
    }

    else { /* parent process */
        wait(&status);
        printf("I'm the parent!\n");
        exit(1);
    }
}
