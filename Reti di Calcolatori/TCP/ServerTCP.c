#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(int argc, char** argv){
    // 2 socket. una iniziale e una per la connect
    int sockfd, newsocket, n;
    struct sockaddr_in remote_addr, local_addr;
    socklen_t len = sizeof(struct sockaddr_in);
    char sendline[1000];
    char recvline[1000];


    if(argc != 2){
        printf("Errore. Inserire la porta");
        return 0;
    }

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("Errore apertura socket");
        return -1;
    }

    memset(&local_addr, 0, len);
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = htonl(INADDR_ANY); //per evitare che quel ip non venga messo come si deve
    local_addr.sin_port = htons(atoi(argv[1]));

    if ((bind(sockfd, (struct sockaddr*)&local_addr, len)) < 0){
        printf("Errore nella bind\n");
        return -1;
    }

    listen(sockfd, 5);

    for(;;){
        newsocket = accept(sockfd, (struct sockaddr*)&remote_addr, &len);

        if(!fork()){ //figlio
            close(sockfd);

            for(;;){
                n = recv(newsocket, recvline, 999, 0);
                recvline[n]=0;

                printf("Messaggio: %s, IP: %s, Port: %d", 
                recvline,
                inet_ntoa(remote_addr.sin_addr), 
                ntohs(remote_addr.sin_port));
                
                send(newsocket, recvline, n, 0);
            }
            close(newsocket);
        } else
            close(newsocket);

    }

    close(sockfd);
    return 0;
}