#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include "user.h"


int main(int argc, char** argv){
    int sockfd;
    struct sockaddr_in remote_addr;
    socklen_t len = sizeof(struct sockaddr_in);
    char buffer[100];
    bool logged = false;

    if(argc<3){
        perror("Usage: <IPv4 Remote_Address> <Port>");
        return 0;
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if(sockfd<0){
        perror("Error opening socket!");
        return -1;
    }

    memset(&remote_addr,0,len);

    remote_addr.sin_addr.s_addr = inet_addr(argv[1]);
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_port = htons(atoi(argv[2]));

    struct User user;
    memset(&user, 0, sizeof(user));

    //richiesta input
    printf("Username: ");
    scanf("%s", buffer);
    strcpy(user.username, buffer);

    printf("Password: ");
    scanf("%s", buffer);
    strcpy(user.password, buffer);


    sendto(sockfd, &user, sizeof(user),0, (struct sockaddr*)&remote_addr, len);
    
    printf("Waiting server answer...\n");
    recvfrom(sockfd, &logged, sizeof(bool), 0, (struct sockaddr*)&remote_addr, &len);

    
    if(logged == true){
        printf("Logged in\n");
        //codice seguente
    }
    else{
        printf("Invalid or non-existent credentials! If you're not, you are now registered\n");
    }
    
    close(sockfd);
    return 0;
}