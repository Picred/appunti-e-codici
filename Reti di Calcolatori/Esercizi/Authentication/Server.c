#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include "user.h"
#include<stdbool.h>

void registeruser(struct User user, char* ip){
    FILE* file = fopen("users.txt", "a");
    char user_temp[100] = "";
    strcat(user_temp, user.username);
    strcat(user_temp, "(");
    strcat(user_temp, ip);
    strcat(user_temp, ")");
    strcat(user_temp, user.password);
    strcat(user_temp, "\0");

    fprintf(file, "%s\n", user_temp);
    fclose(file);
}


bool checkuser(struct User user, char* ip){
    char correct_user[100] = "";
    strcat(correct_user, user.username);
    strcat(correct_user, "(");
    strcat(correct_user, ip);
    strcat(correct_user, ")");
    strcat(correct_user, user.password);
    strcat(correct_user, "\0");
    strcat(correct_user, "\n");
    
    // Example of correct format ofregistered user: username(ip)password
    FILE* file = fopen("users.txt", "r");

    if(file == NULL){
        perror("Can't find user.txt file in the directory.");
        return false;
    }

    rewind(file);
    char test_user[100];
    while(!feof(file)){
        fgets(test_user, sizeof(test_user), file);
        if (strcmp(test_user, correct_user) == 0){
            fclose(file);
            return true;
        }
    }
    fclose(file);
    registeruser(user, ip);
    return false;
}


int main(int argc, char** argv){
    int sockfd;
    struct sockaddr_in local_addr, remote_addr;
    socklen_t len = sizeof(struct sockaddr_in);
    struct User user;
    bool logged = false;

    if(argc<2){
        perror("Usare: <Port>");
        return 0;
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if(sockfd<0){
        perror("Error socket opening\n");
        return -1;
    }

    memset(&local_addr,0,len);
    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(atoi(argv[1]));

    if(bind(sockfd, (struct sockaddr*)&local_addr, len)<0){
        perror("Bind error\n");
        return -1;
    }

    while(1 == 1){
        memset(&user, 0, sizeof(user));
        int n = recvfrom(sockfd, &user, sizeof(user), 0, (struct sockaddr*)&remote_addr, &len);

        char* ip = inet_ntoa(remote_addr.sin_addr);
        if(checkuser(user, ip) == true){
            printf("User  \"%s\" logged in using the following password: %s\n", user.username, user.password);
            logged = true;
        }
        else {
            printf("User \"%s\" failed to log in. Registered\n", user.username);
            logged = false;
        }

        // ACK
        sendto(sockfd, &logged, sizeof(logged), 0, (struct sockaddr*)&remote_addr, len);
    }

    close(sockfd);

    return 0;
}