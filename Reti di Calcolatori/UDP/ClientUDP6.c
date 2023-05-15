#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char** argv){

    int sockfd;
    struct sockaddr_in6 remote_addr;
    socklen_t len = sizeof(struct sockaddr_in6);
    char buffer[100];

    if(argc<3){
        perror("Inserisci IP e Porta");
        return 0;
    }

    sockfd = socket(AF_INET6, SOCK_DGRAM, 0);

    if(sockfd<0){
        perror("Erorre apertura socket");
        return -1;
    }

    memset(&remote_addr, 0, len);
    inet_pton(AF_INET6, argv[1], &(remote_addr.sin6_addr)); 
    remote_addr.sin6_family = AF_INET6;
    remote_addr.sin6_port = htons(atoi(argv[2]));

    scanf("%s", buffer);
    sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&remote_addr, len);

    close(sockfd);
    return 0;
}
