#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>

#define BUFFER_SIZE 16

int main(int argc, char** argv){
    int sockfd;
    struct sockaddr_in remote_addr;
    socklen_t len = sizeof(struct sockaddr_in);
    char buffer[BUFFER_SIZE];
    
    if(argc != 3){
        printf("Usage: ./%s <ip> <port>\n", basename(argv[0]));
        return EXIT_FAILURE;
    }

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket()");
        return EXIT_FAILURE;
    }

    memset(&remote_addr, 0, len);
    remote_addr.sin_addr.s_addr = inet_addr(argv[1]);
    remote_addr.sin_port = htons(atoi(argv[2]));
    remote_addr.sin_family = AF_INET;
    
    if((connect(sockfd, (struct sockaddr*)&remote_addr, len)) < 0){
        perror("connect()");
        return EXIT_FAILURE;
    }

    printf("Inserisci un numero e il Server ti calcolera' il suo cubo: ");
    fgets(buffer, BUFFER_SIZE, stdin);

    send(sockfd, buffer, strlen(buffer), 0);
    
    int n = recv(sockfd, buffer, BUFFER_SIZE, 0);

    if (n < BUFFER_SIZE) {
        buffer[n] = '\0';
    }

    printf("Risposta Server: %d\n", atoi(buffer));

    close(sockfd);
    
    return EXIT_SUCCESS;
}
