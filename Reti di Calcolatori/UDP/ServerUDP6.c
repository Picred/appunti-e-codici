#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char** argv){
    int sockfd;
    struct sockaddr_in6 local_addr, remote_addr;
    socklen_t len = sizeof(struct sockaddr_in6);
    char buffer[100];
    char ipv6_addr[46];

    if(argc<2){
        perror("Inserisci Porta");
        return 0;
    }

    sockfd = socket(AF_INET6, SOCK_DGRAM, 0);
    if(sockfd<0){
        perror("Errore apertura socket");
        return -1;
    }

    memset(&local_addr, 0, len);
    local_addr.sin6_port = htons(atoi(argv[1]));
    local_addr.sin6_family = AF_INET6;

    if(bind(sockfd, (struct sockaddr*)&local_addr, len)<0){
        perror("Errore nella bind");
        return -1;
    }

    int n = recvfrom(sockfd, buffer, 100, 0, (struct sockaddr*)&remote_addr, &len);
    buffer[n]=0;

    printf("Messaggio: %s IP: %s, Porta: %d\n",
            buffer,
            inet_ntop(AF_INET6, &(remote_addr.sin6_addr), ipv6_addr, INET6_ADDRSTRLEN),
            ntohs(remote_addr.sin6_port));

    close(sockfd);    
    return 0;
}
