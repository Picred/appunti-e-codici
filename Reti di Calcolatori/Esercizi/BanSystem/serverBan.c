#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>

#define TRUE 1
#define FALSE 0

// Controlla se l'ip è bannato nel file
int isbanned(char* ip){
    FILE* file = fopen("banlist.txt", "r");

    if (file == NULL) {
        printf("Errore apertura file\n");
        return FALSE;
    }

    char test_ip[16];

    while(fscanf(file, "%15s", test_ip) != EOF){
        //legge una riga e vede se l'ip è presente nel file
        if (strcmp(ip,test_ip) == 0) {
            fclose(file);
            return TRUE;
        }
    }
    fclose(file);
    return FALSE;
}

// scrive l'ip da bannare nel file
int ban(char* ip){
    FILE* file = fopen("banlist.txt", "a");

    if (file == NULL) {
        printf("Errore apertura file\n");
        return FALSE;
    }

    if ((isbanned(ip)) == TRUE){
        fclose(file);
        return FALSE; //utente già bannato
    }
    
    fprintf(file, "%s\n", ip);

    if (fclose(file) != 0) {
        printf("Errore chiusura file\n");
        return FALSE;
    }

    return TRUE;
}


// unbanna l'utente con l'ip indicato
int unban(char* ip){
    if(isbanned(ip)){
        FILE* file = fopen("banlist.txt", "r");
        FILE* tmp_file = fopen("tmp_file.txt", "w");
        char test_ip[16];

        if (file == NULL || tmp_file == NULL) {
            printf("Errore apertura file\n");
            return FALSE;
        }

        while(fscanf(file, "%15s", test_ip) != EOF){
            if(strcmp(ip,test_ip) == 0)
                continue;
            fprintf(tmp_file, "%s\n", test_ip);
        }

        if (fclose(file) != 0) {
            printf("Errore chiusura file\n");
            return FALSE;
        }

        if (fclose(tmp_file) != 0) {
            printf("Errore chiusura file\n");
            return FALSE;
        }

        if (remove("banlist.txt") != 0) {
            printf("Errore rimozione file\n");
            return FALSE;
        }

        if (rename("tmp_file.txt", "banlist.txt") != 0) {
            printf("Errore rinomina file\n");
            return FALSE;
        }

        return TRUE;
    } else{ //già unbannato
        return FALSE;
    }
}


int main (int argc, char** argv){
    int sockfd, n;
    struct sockaddr_in local_addr, dest_addr;
    socklen_t len = sizeof(struct sockaddr_in);
    char buffer[100];

    if (argc < 2){
        printf("Inserisci la porta");
        return 0;
    }

    //socket()
    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
        printf("Errore apertura socket");
        return -1;
    }

    memset(&local_addr, 0, len);
    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(atoi(argv[1]));

    //bind()
    if (bind(sockfd, (struct sockaddr *)&local_addr, len) < 0){
        printf("Errore! Inserisci un numero di porta valido\n");
        return -1;
    }

    // recvfrom()
    for(;;){
        n = recvfrom(sockfd, buffer, 100, 0, (struct sockaddr *)&dest_addr, &len);
        buffer[n] = 0;
        //log
        printf("Messaggio: %s, IP: %s, Port: %d \n", 
                buffer, 
                inet_ntoa(dest_addr.sin_addr),
                ntohs(dest_addr.sin_port));


        //rendo tutto minuscolo
        for(int i=0; buffer[i] != '\0'; i++)
            buffer[i] = tolower(buffer[i]);

        //try ban
        if((strcmp(buffer,"ban\n")) == 0){
            printf("Ricevuta richiesta di ban dall'IP %s\n", inet_ntoa(dest_addr.sin_addr));

            if( (ban(inet_ntoa(dest_addr.sin_addr))) == TRUE)
                strcpy(buffer, "Successfully banned!");
            else
                strcpy(buffer, "Already banned!");

        }

        // try unban
        if((strcmp(buffer,"unban\n")) == 0){
            printf("Ricevuta richiesta di unban dall'IP %s\n", inet_ntoa(dest_addr.sin_addr));
            if( (unban(inet_ntoa(dest_addr.sin_addr))) == TRUE)
                strcpy(buffer, "Successfully unbanned!");
            else
                strcpy(buffer, "Already unbanned!");
        }


        sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&dest_addr, len);
    }

    close(sockfd);
    return 0;
}
