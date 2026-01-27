/*
Q2 Demonstrate creation, writing to, and reading from a pipe.
*/

#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int n, fd[2];
    char buf[1025];
    char *data = "hello, this is sample data!";

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    write(fd[1], data, strlen(data));

    close(fd[1]);

    if ((n = read(fd[0], buf, 1024)) >= 0){
        buf[n] = '\0';
        printf("Read %d bytes from the pip : %s\n", n, buf);
    }
    else perror("read");
    exit(0);
}
