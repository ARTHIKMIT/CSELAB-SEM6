/*
Q4 Your product will sit on a shelf: that is an integer - a count of the items "on the shelf".
This integer may never drop below 0 or rise above 5.

Your producer sets the value of the count to 5. It is the producer program's
responsibility to stock product on the shelf, but not overstocked. The producer may
add one item to the shelf at a time, and must report to STDOUT every time another
item is added as well as the current shelf count.

Producer

*/
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>

#define FIFO_NAME "/tmp/fifo"

void main() {
    int res, pid;
    if (access(FIFO_NAME, F_OK) == -1) {
        res = mkfifo(FIFO_NAME, 0777); // permission: read, write, and execute for all users
        if (res != 0) {
            printf("Could not create FIFO %s\n", FIFO_NAME);
            exit(1);
        }
    }
    int pipeID = open(FIFO_NAME, O_RDWR);
    if (pipeID == -1) {
        printf("Failed to open pipe\n");
        exit(1);
    }

    int n = 5;
    write(pipeID, &n, sizeof(int)); // Setting it to 5 initially

    while(1) {

        read(pipeID, &n, sizeof(int));
        if (n >= 5) {
            printf("Producer could not produce because max goods are available\n");
            write(pipeID, &n, sizeof(int));
        }
        else {
            n += 1;
            write(pipeID, &n, sizeof(int));
            printf("Producer produced goods. Total number of goods now: %d\n", n);
        }
        sleep(2);
    }
    close(pipeID);
}
