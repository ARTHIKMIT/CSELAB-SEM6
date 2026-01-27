// UDP Client Program
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main() {
    int sd, rows, cols, i, j, len;
    struct sockaddr_in address;
    char buf[256], result[512];

    // Create UDP socket
    sd = socket(AF_INET, SOCK_DGRAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("172.16.48.159");
    address.sin_port = htons(9704);

    len = sizeof(address);

    // Input rows and cols
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Send rows and cols to server
    sprintf(buf, "%d", rows);
    sendto(sd, buf, sizeof(buf), 0, (struct sockaddr *)&address, len);

    sprintf(buf, "%d", cols);
    sendto(sd, buf, sizeof(buf), 0, (struct sockaddr *)&address, len);

    // Input and send matrix row by row
    int val;
    printf("Enter matrix values row by row:\n");
    for(i = 0; i < rows; i++) {
        char rowbuf[256] = "";
        for(j = 0; j < cols; j++) {
            scanf("%d", &val);
            char temp[10];
            sprintf(temp, "%d ", val);
            strcat(rowbuf, temp);
        }
        sendto(sd, rowbuf, sizeof(rowbuf), 0, (struct sockaddr *)&address, len);
    }

    // Receive combined matrix back from server
    recvfrom(sd, result, sizeof(result), 0, (struct sockaddr *)&address, &len);

    printf("\nMatrix received back from server:\n%s\n", result);

    close(sd);
    return 0;
}
