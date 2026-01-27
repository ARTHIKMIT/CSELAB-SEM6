// TCP Server Program
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define PORTNO 10200

// Function to process string: remove duplicates + count
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

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Setup server address
    seraddr.sin_family = AF_INET;
    seraddr.sin_addr.s_addr = inet_addr("172.16.48.159");
    seraddr.sin_port = htons(PORTNO);

    // Bind socket
    bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr));

    // Listen for connections
    listen(sockfd, 5);

    printf("Server waiting...\n");

    clilen = sizeof(cliaddr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);

    while(1) {
        bzero(buf, sizeof(buf));
        n = read(newsockfd, buf, sizeof(buf));
        buf[n] = '\0';

        if(strcmp(buf, "Stop") == 0) {
            printf("Client requested termination. Closing...\n");
            break;
        }

        printf("Message from Client: %s\n", buf);

        // Process string
        processSentence(buf, result);

        // Send back to client
        write(newsockfd, result, strlen(result)+1);
    }

    close(newsockfd);
    close(sockfd);
    return 0;
}
