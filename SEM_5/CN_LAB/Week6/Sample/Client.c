// TCP Client Program
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

    char buf[25];
	printf("Enter buf\n");
	gets(buf);
    
	int m = send(sd, buf, strlen(buf)+1,0);
	int n = recv(sd, buf, sizeof(buf),0);
	printf("the server echo is\n");
	puts(buf);
	return 0;
}
