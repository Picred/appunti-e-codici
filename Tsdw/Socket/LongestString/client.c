#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>

// $ ./client 0.0.0.0 $'pippo\n'

int main(int argc, char* argv[]){
    int sockfd, n;
    socklen_t len = sizeof(struct sockaddr_in);
    struct sockaddr_in remote_addr;
    char buffer[BUFSIZ];

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket");
        return -1;
    }

    memset(&remote_addr, 0, len);
    remote_addr.sin_addr.s_addr = inet_addr(argv[1]);
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_port = htons(3333);
    
    if((connect(sockfd, (struct sockaddr*)&remote_addr, len)) < 0){
        perror("connect");
        return -1;
    }

    strcpy(buffer, argv[2]);

    if((send(sockfd, buffer, strlen(buffer), 0)) < 0){
        perror("send");
        return -1;
    }

    if((n = recv(sockfd, buffer, BUFSIZ, 0)) < 0){
        perror("recv");
        return -1;
    }

    buffer[n] = 0;

    printf("Received: %s" , buffer);

    return 0;
}