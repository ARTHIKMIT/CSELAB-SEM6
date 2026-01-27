/*
1. Implement concurrent Remote Math Server To perform arithmetic operations in the
server and display the result to the client. The client accepts two integers and an
operator from the user and sends it to the server. The server then receives integers
and operator. The server will perform the operation on integers and sends the result
back to the client which is displayed on the client screen. Then both the processes
terminate.

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

    printf("Enter expression (e.g., 10 + 20): ");
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
