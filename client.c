#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <signal.h>


//standard port number for http 
#define SERVER_PORT 80
#define TCP 0
#define MAXLINE 4096
#define SA struct sockaddr


int main(int argc, char** argv) {
    if (argc < 2) {
        return -1;
    }

    int sockfd;
    // creates a socket with the internet protocol, streaming, and TCP connection
    if ((sockfd = socket(AF_INET, SOCK_STREAM, TCP)) == 0) {
        return -1;
    }

    //zeroes out the socket's server address
    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    // host to network short (ensures that two computers can communicate regardless of architecture big endianness/little endianness)
    servaddr.sin_port = htons(SERVER_PORT);

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) < 0) {
        return -1;
    }

    char* sendline;
    sprintf(sendline, "GET / HTTP/1.1\r\n\r\n");

}