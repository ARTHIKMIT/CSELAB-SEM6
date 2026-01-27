/*
Implement a basic chat application where multiple clients can send and receive messages through a server.

Client Requirements:
1.	Each client should be able to connect to the server.
2.	Clients should be able to send messages to the server.
3.	Clients should be able to receive and display messages from other clients.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 10200

#define KEY 8

int sockfd;

void xor_encrypt_decrypt(char *msg) {
    for (int i = 0; msg[i] != '\0'; i++) {
        msg[i] = msg[i] ^ KEY;
    }
}

void *receive_messages(void *arg) {
    char buffer[1024];
    int n;
    while ((n = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[n] = '\0';
        xor_encrypt_decrypt(buffer);
        printf("\n[Chat] %s\n> ", buffer);
        fflush(stdout);
    }
    if (n == 0) printf("\n[Client] Server has closed the connection. Exiting.\n");
    else perror("\n[Client] recv failed");
	close(sockfd);
	exit(0);  // Exit client process
    return NULL;
}

int main() {
    struct sockaddr_in servaddr;
    char msg[1024], username[1024];
    pthread_t recv_thread;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(1);
    }

	printf("Username : ");
	fgets(username, sizeof(username), stdin);
	username[strcspn(username, "\n")] = '\0';
	
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("172.16.48.159"); // or server IP

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("Connected to chat server. Type messages...\n");

    // Start receiving thread
    pthread_create(&recv_thread, NULL, receive_messages, NULL);

    while (1) {
        printf("> ");
        fgets(msg, sizeof(msg), stdin);
        msg[strcspn(msg, "\n")] = '\0';
        if (strlen(msg) > 0) {
			char msgFinal[1100];
			snprintf(msgFinal, sizeof(msgFinal), "%s : %s", username, msg);
			xor_encrypt_decrypt(msgFinal);
            send(sockfd, msgFinal, strlen(msgFinal), 0);
        }
    }

    close(sockfd);
    return 0;
}
