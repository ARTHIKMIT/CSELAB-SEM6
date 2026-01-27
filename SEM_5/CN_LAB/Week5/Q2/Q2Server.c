// UDP Server Program
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main() {
    int sd, rows, cols, len, i, j;
    struct sockaddr_in sadd, cadd;
    char buf[256];
    int matrix[20][20];

    // Create UDP socket
    sd = socket(AF_INET, SOCK_DGRAM, 0);

    // Server address
    sadd.sin_family = AF_INET;
    sadd.sin_addr.s_addr = inet_addr("172.16.48.159");
    sadd.sin_port = htons(9704);

    bind(sd, (struct sockaddr *)&sadd, sizeof(sadd));

    len = sizeof(cadd);

    // Receive rows
    recvfrom(sd, buf, sizeof(buf), 0, (struct sockaddr *)&cadd, &len);
    rows = atoi(buf);

    // Receive cols
    recvfrom(sd, buf, sizeof(buf), 0, (struct sockaddr *)&cadd, &len);
    cols = atoi(buf);

    printf("Server: expecting %d x %d matrix\n", rows, cols);

    // Receive matrix row by row
    for(i = 0; i < rows; i++) {
        recvfrom(sd, buf, sizeof(buf), 0, (struct sockaddr *)&cadd, &len);
        char *token = strtok(buf, " ");
        j = 0;
        while(token != NULL && j < cols) {
            matrix[i][j] = atoi(token);
            j++;
            token = strtok(NULL, " ");
        }
    }

    printf("Matrix received at server:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Convert matrix into string
    char result[512] = "";
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            char temp[10];
            sprintf(temp, "%d ", matrix[i][j]);
            strcat(result, temp);
        }
        strcat(result, "\n");
    }

    // Send matrix back to client
    sendto(sd, result, sizeof(result), 0, (struct sockaddr *)&cadd, len);

    close(sd);
    return 0;
}
