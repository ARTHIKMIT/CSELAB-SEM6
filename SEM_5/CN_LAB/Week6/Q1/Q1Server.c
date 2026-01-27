/*
1. Implement concurrent Remote Math Server To perform arithmetic operations in the
server and display the result to the client. The client accepts two integers and an
operator from the user and sends it to the server. The server then receives integers
and operator. The server will perform the operation on integers and sends the result
back to the client which is displayed on the client screen. Then both the processes
terminate.

TCP Server Program

*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#define PORTNO 10200

int main() {
    int sockfd, newsockfd, portno, clilen, n;
    struct sockaddr_in seraddr, cliaddr;

    char buf[256];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    seraddr.sin_family = AF_INET;
    seraddr.sin_addr.s_addr = inet_addr("172.16.48.159");
    seraddr.sin_port = htons(PORTNO);

    if (bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr)) < 0) {
		perror("bind");
		exit(1);
	}
	if (listen(sockfd, 5) < 0) {
		perror("listen");
		exit(1);
	}

	while(1) {
		clilen = sizeof(cliaddr);
		newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);

		if (fork() == 0){
			close(sockfd);
			n = read(newsockfd, buf, sizeof(buf));
			
			int a, b;
			char op;
			int result = 0;
			buf[n] = '\0';
			
			printf("Message from Client: %s\n", buf);
			
            if (sscanf(buf, "%d %c %d", &a, &op, &b) == 3) {
                switch (op) {
                    case '+': result = a + b; break;
                    case '-': result = a - b; break;
                    case '*': result = a * b; break;
                    case '/': 
                        if (b != 0) result = a / b;
                        else sprintf(buf, "Error: divide by zero");
                        break;
                    default: sprintf(buf, "Error: invalid operator");
                }
                if (op == '+' || op == '-' || op == '*' || (op == '/' && b != 0))
                    sprintf(buf, "Result = %d", result);
            } else sprintf(buf, "Error: invalid input");

			write(newsockfd, buf, strlen(buf) + 1);
			
			close(newsockfd);
			exit(0);
		}
		else close(newsockfd);
	}
}
