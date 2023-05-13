#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(int argc, char** argv){
    int sockfd, n;
    struct sockaddr_in dest_addr;
    socklen_t len = sizeof(struct sockaddr_in);
    char sendline[1000];
    char recvline[1000];
    
    if(argc != 3){
        printf("Errore, inserisci IP e Porta");
        return 0;
    }

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("Errore apertura socket");
        return -1;
    }

    memset(&dest_addr, 0, len);
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = inet_addr(argv[1]);
    dest_addr.sin_port = htons(atoi(argv[2]));

    int c = connect(sockfd, (struct sockaddr* )&dest_addr, len);

    if(c <0){
        printf("Errore nella connessione con il server");
        return -1;
    }    
    
    while(fgets(sendline, 1000, stdin) != NULL){
        send(sockfd, sendline, strlen(sendline), 0);
        n = recv(sockfd, recvline, 999, 0);
        recvline[n] = 0;

        printf("Messaggio: %s, IP: %s, Port: %d", 
                recvline,
                inet_ntoa(dest_addr.sin_addr), 
                ntohs(dest_addr.sin_port));
    }
    
    close(sockfd);    
    return 0;
}
