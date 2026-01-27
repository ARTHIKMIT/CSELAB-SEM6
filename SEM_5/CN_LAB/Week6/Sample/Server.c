// TCP Server Program
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
    int sockfd, newsockfd, portno, clilen, n = 1, i, val;
    struct sockaddr_in seraddr, cliaddr;

    char buf[256], result[512];

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
			n = read(newsockfd, buf, sizeof(buf));
			//buf[n] = '\0';
			printf("Message from Client: %s\n", buf);
			n = write(newsockfd, buf, sizeof(buf));
			close(newsockfd);
			exit(0);
		}
		else close(newsockfd);
	}
}
