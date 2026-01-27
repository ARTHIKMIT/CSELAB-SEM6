/*
2. Write a concurrent TCP client server ‘C’ program where the client accepts a sentence
from the user and sends it to the server. The server will check for duplicate words in
the string. Server will find the number of occurrences of duplicate words present and
remove the duplicate words by retaining single occurrence of the word and send the
resultant sentence to the client.

TCP Client Program

*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<fcntl.h>

int main() {
    int sd, len;
    struct sockaddr_in address;
	char buf[256];
    // Create socket
    sd = socket(AF_INET, SOCK_STREAM, 0);

    // Setup server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("172.16.48.159");
    address.sin_port = htons(10200);
    
    len = sizeof(address);
	if (connect(sd, (struct sockaddr *)&address, len) < 0) {
		perror("connect");
		exit(1);
	}

    printf("Enter Sentence : ");
    fgets(buf, sizeof(buf), stdin);
    buf[strcspn(buf, "\n")] = '\0';  // remove newline

    send(sd, buf, strlen(buf), 0);

    int n = recv(sd, buf, sizeof(buf) - 1, 0);
    if (n > 0) {
        buf[n] = '\0';
        printf("Server reply: %s\n", buf);
    }

    close(sd);
    return 0;
}
