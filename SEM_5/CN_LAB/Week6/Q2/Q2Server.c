/*
2. Write a concurrent TCP client server ‘C’ program where the client accepts a sentence
from the user and sends it to the server. The server will check for duplicate words in
the string. Server will find the number of occurrences of duplicate words present and
remove the duplicate words by retaining single occurrence of the word and send the
resultant sentence to the client.

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

void processSentence(char *input, char *output) {
    char words[100][50];   // store words
    int count[100] = {0};  // word frequency
    int i, j, k = 0, n = 0;
    char *token;

    // Break sentence into words
    token = strtok(input, " ");
    while(token != NULL) {
        strcpy(words[n], token);
        n++;
        token = strtok(NULL, " ");
    }

    // Count occurrences
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            if(strcmp(words[i], words[j]) == 0) {
                count[i]++;
                // shift left (remove duplicate)
                for(k = j; k < n-1; k++) {
                    strcpy(words[k], words[k+1]);
                }
                n--;
                j--; // adjust index
            }
        }
    }

    // Build output sentence
    strcpy(output, "");
    for(i = 0; i < n; i++) {
        strcat(output, words[i]);
        if(i != n-1) strcat(output, " ");
    }

    // Append frequency infocd
    strcat(output, "\nDuplicate Word Counts:\n");
    for(i = 0; i < n; i++) {
        if(count[i] > 0) {
            char temp[50];
            sprintf(temp, "%s -> %d times\n", words[i], count[i]+1);
            strcat(output, temp);
        }
    }
}

int main() {
    int sockfd, newsockfd, clilen, n;
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
			close(sockfd);
			n = read(newsockfd, buf, sizeof(buf));
			buf[n] = '\0';
			
			printf("Message from Client: %s\n", buf);
			
			processSentence(buf, result);

			write(newsockfd, result, strlen(result)+1);

			close(newsockfd);
			exit(0);
		}
		else close(newsockfd);
	}
}
