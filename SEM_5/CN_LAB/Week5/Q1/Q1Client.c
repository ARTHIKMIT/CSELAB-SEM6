// TCP Client Program
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main() {
    int len, result, sockfd, n;
    struct sockaddr_in address;
    char ch[256], buf[512];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Setup server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("172.16.48.159");
    address.sin_port = htons(10200);
    len = sizeof(address);

    // Connect to server
    result = connect(sockfd, (struct sockaddr *)&address, len);
    if(result == -1) {
        perror("CLIENT ERROR");
        exit(1);
    }

    while(1) {
        printf("\nType 'Stop' to exit \nEnter Sentence : ");
        fgets(ch, sizeof(ch), stdin);
        ch[strcspn(ch, "\n")] = '\0';  // remove newline

        // Send message to server
        write(sockfd, ch, strlen(ch));

        if(strcmp(ch, "Stop") == 0) {
            printf("Terminating client...\n");
            break;
        }

        // Receive processed message
        bzero(buf, sizeof(buf));
        n = read(sockfd, buf, sizeof(buf));
        buf[n] = '\0';

        printf("String sent back from the server: %s\n", buf);
    }

    close(sockfd);
    return 0;
}
