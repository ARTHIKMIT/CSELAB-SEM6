/*
Q4 Create a zombie (defunct) child process (a child with exit() call, but no corresponding wait() in the sleeping parent) and allow the init process to adopt it (after parent terminates). Run the process as a background process and run the “ps” command.
*/

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    pid_t pid;

    pid = fork();

    if(pid == -1)
        printf("ERROR child not created");

    else if (pid == 0) { /* child process */
        printf("I'm the Child! PID : %d Parent PID : %d\n", getpid(), getppid());
        execlp("/bin/ps", "ps", NULL);
        //execlp("/bin/top", "top", NULL);
        exit(0);
    }

    else { /* parent process */
        printf("\nI'm the parent! PID : %d Parent PID : %d\n", getpid(), getppid());
        sleep(5);
        exit(0);
    }
}
