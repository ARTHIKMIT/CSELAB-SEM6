/*
Implement a basic chat application where multiple clients can send and receive messages through a server.

Server Requirements:
1.	The server should be able to accept multiple client connections.
2.	The server should broadcast received messages to all connected clients.
3.	Each client should be able to join the chat by connecting to the server and should see all messages sent by other clients.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 10200
#define MAX_CLIENTS 10

#define KEY 8

int client_sockets[MAX_CLIENTS];

void broadcast_message(int sender_sock, char *msg) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] != 0 && client_sockets[i] != sender_sock) {
            send(client_sockets[i], msg, strlen(msg), 0);
        }
    }
}

void xor_encrypt_decrypt(char *msg) {
    for (int i = 0; msg[i] != '\0'; i++) {
        msg[i] = msg[i] ^ KEY;
    }
}


int main() {
    int server_fd, new_sock, max_sd, sd, activity, valread;
    struct sockaddr_in address;

    //Data struct that holds set of fds to monitor
    fd_set readfds;
    
    char buffer[1024];
    socklen_t addrlen = sizeof(address);

    for (int i = 0; i < MAX_CLIENTS; i++) client_sockets[i] = 0;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Server socket failed");
        exit(1);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(server_fd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Chat server started on port %d...\n", PORT);

    while (1) {
        //Clears set before adding fds
        FD_ZERO(&readfds);
        //Adds a fd to set
        FD_SET(server_fd, &readfds);
        
        max_sd = server_fd;

        //Adding client sockets
        for (int i = 0; i < MAX_CLIENTS; i++) {
            sd = client_sockets[i];
            if (sd > 0) FD_SET(sd, &readfds);
            if (sd > max_sd) max_sd = sd;
        }

        //Waiting for activity
        activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);
        if (activity < 0) {
            perror("select error");
        }

        //Incoming connection - FD_ISSET checks if server is ready
        if (FD_ISSET(server_fd, &readfds)) {
            if ((new_sock = accept(server_fd, (struct sockaddr *)&address, &addrlen)) < 0) {
                perror("accept");
                exit(1);
            }
            printf("New client connected: socket fd %d\n", new_sock);

            //Add to array
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockets[i] == 0) {
                    client_sockets[i] = new_sock;
                    break;
                }
            }
        }

        // Client message
        for (int i = 0; i < MAX_CLIENTS; i++) {
            sd = client_sockets[i];
            if (FD_ISSET(sd, &readfds)) {
                if ((valread = read(sd, buffer, sizeof(buffer) - 1)) == 0) {
                    // Disconnected
                    getpeername(sd, (struct sockaddr *)&address, &addrlen);
                    printf("Client disconnected: socket fd %d\n", sd);
                    close(sd);
                    client_sockets[i] = 0;
                } else {
                    buffer[valread] = '\0';
                    printf("Encrypted Message from client %d: %s\n", sd, buffer);
					xor_encrypt_decrypt(buffer);
					printf("Decrypted Message from client %d: %s\n", sd, buffer);
                    //char broadcast_buf[1100];
                    //snprintf(broadcast_buf, sizeof(broadcast_buf), "Client %d %s", sd, buffer);
					xor_encrypt_decrypt(buffer);
                    broadcast_message(sd, buffer);
                }
            }
        }
    }

    return 0;
}
