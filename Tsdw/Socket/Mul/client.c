#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    struct sockaddr_in remote_addr;
    socklen_t len = sizeof(struct sockaddr_in);
    char buffer[BUFSIZ];
    int sockfd, n;

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket");
        return EXIT_FAILURE;
    }

    memset(&remote_addr, 0, len);

    remote_addr.sin_family = AF_INET;
    remote_addr.sin_port = htons(7777);
    remote_addr.sin_addr.s_addr = inet_addr("0.0.0.0");

    if((connect(sockfd, (struct sockaddr*)&remote_addr, len)) < 0){
        perror("connect");
        return EXIT_FAILURE;
    }

    sprintf(buffer, "1234\n");

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