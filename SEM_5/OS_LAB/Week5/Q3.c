/*
Q3 Write a program to create a child process. Display the process IDs of the process, parent and child (if any) in both the parent and child processes.
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

    if(pid == -1)
        printf("ERROR child not created");

    else if (pid == 0) { /* child process */
        printf("I'm the Child! PID : %d Parent PID : %d", getpid(), getppid());
        exit(0);
    }

    else { /* parent process */
        wait(&status);
        printf("\nI'm the parent! PID : %d Parent PID : %d\n", getpid(), getppid());
        exit(0);
    }
}
