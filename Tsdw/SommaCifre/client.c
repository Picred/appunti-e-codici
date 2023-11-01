#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

void handle_error(char* str){
    perror(str);
    exit(EXIT_FAILURE);
}

int main(void){
    int sockfd, n;
    struct sockaddr_in remote_addr;
    socklen_t len = sizeof(struct sockaddr_in);
    char buffer[BUFSIZ];

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket");
        return EXIT_FAILURE;
    }
    
    memset(&remote_addr, 0, len);

    remote_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_port = htons(3333);

    if((connect(sockfd, (struct sockaddr*)&remote_addr, len)) < 0){
        perror("connect");
        return EXIT_FAILURE;
    }

    sprintf(buffer, "c0a89s2a3hk\n");

    if((send(sockfd, buffer, strlen(buffer), 0)) < 0){
        perror("send");
        return EXIT_FAILURE;
    }

    if((n = recv(sockfd, &buffer, BUFSIZ, 0)) < 0){
        perror("recv");
        return EXIT_FAILURE;
    }
    buffer[n] = '\0';

    printf("%s", buffer);

    return EXIT_SUCCESS;
}