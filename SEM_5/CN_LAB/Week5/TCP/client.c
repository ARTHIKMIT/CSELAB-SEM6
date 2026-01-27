//TCP

#include<stdio.h>       // For standard I/O functions (printf, gets, perror)
#include<stdlib.h>      // For exit(), memory, and utility functions
#include<string.h>      // For string handling functions (strlen, strcpy, etc.)
#include<sys/types.h>   // Defines data types used in system calls
#include<sys/socket.h>  // For socket-related functions (socket, connect, read, write)
#include<netinet/in.h>  // For sockaddr_in structure (Internet domain addresses)
#include<arpa/inet.h>   // For inet_addr() (converts IP address string to binary form)


int main() {
	/*
	sockfd → socket file descriptor (like an ID for your socket).
	address → structure holding server details (IP + port).
	ch → input string (client sends to server).
	buf → buffer to store message received back from serve 
	 */
	int len, result, sockfd, n=1; 
	struct sockaddr_in address;
	char ch[256],buf[256];

	/*
	Create a socket for the client : 
	
	AF_INET → IPv4 family.
	SOCK_STREAM → TCP socket (connection-oriented, reliable).
	0 → use default protocol (TCP for SOCK_STREAM).
	Returns a socket descriptor (sockfd), or -1 if error.
	 */
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	/*
	Name the socket as agreed with the server
	
	sin_family = AF_INET (IPv4).
	sin_addr.s_addr = server’s IP in binary (using inet_addr).
	sin_port = port number converted to network byte order using htons.
	len = size of address structure.
	*/
	address.sin_family=AF_INET;
	address.sin_addr.s_addr = inet_addr("172.16.48.159");
	address.sin_port=htons(10200);
	len = sizeof(address);

	//Connect your socket to the server’s socket
	result=connect(sockfd,(struct sockaddr *)&address,len);
	if(result==-1) {
		perror("\nCLIENT ERROR");
		exit(1);
	}
	//You can now read and write via sockfd (Logic for problem mentioned here)
	printf("\nENTER STRING\t");
	gets(ch);
	ch[strlen(ch)]='\0';
	write(sockfd,ch,strlen(ch)); //ends data to server via socket
	printf("STRING SENT BACK FROM SERVER IS ..... ");
	
	while(n){	//n = 0, it means server closed
		n=read(sockfd,buf,sizeof(buf)); //receives data into buf
		puts(buf);
	}
}
