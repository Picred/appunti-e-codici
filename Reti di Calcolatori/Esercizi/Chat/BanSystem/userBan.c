#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main (int argc, char** argv){
    int sockfd, n;
    struct sockaddr_in dest_addr;
    socklen_t len = sizeof(struct sockaddr_in);
    char buffer[100];

    if (argc < 3){
        printf("Inserisci IP e Porta");
        return 0;
    }

    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
        printf("Errore apertura socket");
        return -1;
    }

    memset(&dest_addr, 0, len);

    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &(dest_addr.sin_addr));


    while(fgets(buffer,99,stdin) != NULL){

        sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&dest_addr, len);
        recvfrom(sockfd, buffer, 99, 0, (struct sockaddr*)&dest_addr, &len);
        buffer[strlen(buffer)] = '\0';

        printf("ACK: %s\n", buffer);
        memset(buffer, 0, strlen(buffer));

    }

    close(sockfd);

    return EXIT_SUCCESS;
}