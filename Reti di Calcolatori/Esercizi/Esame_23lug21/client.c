/*Realizzare il seguente servizio di trasferimento file. La rete è formata da un server e da vari client, tutti uguali. 

• Il client si registra sul server, fornendo una username, una lista di file disponibili per la copia ed una 
porta di ascolto (TCP, vedi oltre) 

• Suna volta registrato, un client può chiedere al server la lista degli altri utenti registrati e la lista dei file 
condivisi da ciascun client (identificato con username). 

• Quando vuole scaricare un file, il client chiede al server le informazioni associate allo username con cui 
vuole connettersi, ovvero l’indirizzo IP e la porta TCP di ascolto (il trasferimento avviene su un canale 
TCP) 

• Il download avviene connettendosi direttamente col client, fornendo il nome del file da scaricare. 

• Periodicamente il server interroga i client, per: 
    a. verificare che sono ancora attivi 
    b. aggiornare la lista dei file condivisi 

• Tutti i messaggi tra client e server sono UDP. 

Usare C o C++. Niente grafica. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

void connect_to(const char* ip){
    // Setto la ip e porta da tastiera e mi connetto TCP all'user
    int sockfd, newsockfd, port;
    struct sockaddr_in remote_client_addr;
    socklen_t len = sizeof(struct sockaddr_in);

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("Errore apertura socket");
        return;
    }

    memset(&remote_client_addr, 0, len);
    remote_client_addr.sin_family = AF_INET;
    remote_client_addr.sin_port = htons(port);
    remote_client_addr.sin_addr.s_addr = inet_addr(ip);

    if(connect(sockfd, (struct sockaddr*) &remote_client_addr, len) < 0){
        perror("Errore connessione con l'ip fornito perchè non è in ascolto: ");
        return;
    }

    printf("Connesso con l'ip %s\n", ip);

    // comunicazione con l'altro client -> invio il nome del file da scaricare
    for(;;){

    }


}


int main(int argc, char** argv){
    int sockfd;
    struct sockaddr_in local_addr, server_addr;
    socklen_t len = sizeof(struct sockaddr_in);
    char buffer[500];
    char list_of_files[500];

    if(argc != 3){
        perror("Usage: <server_ip> <server_port>\n");
        return 0;
    }

    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
        perror("Errore apertura socket");
        return -1;
    }

    memset(&server_addr, 0, len);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);


    // richiesta Username
    printf("Connesso con il server: %s.\nInserisci username: ", inet_ntoa(server_addr.sin_addr));
    scanf("%s", buffer);

    // (login) o (registrazione + login)
    sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&server_addr, len);

    int n = recv(sockfd, buffer, 499, 0); // server ACK
    buffer[n]= 0;

    printf("Messaggio ricevuto dal server: %s\n", buffer);

    // ricevo lista file disponibili per la copia e li invio
    printf("Inserisci i file che sono disponibili per la copia usando il formato <file1.txt,file2.txt>: ");
    scanf("%s", list_of_files);
    sendto(sockfd, list_of_files , strlen(list_of_files), 0, (struct sockaddr*)&server_addr, len);

    //invio la porta di ascolto
    char user_port[4];
    printf("Inserisci la porta di ascolto per tutti i client che vuoi usare. <4 cifre>: ");
    scanf("%s", user_port);
    sendto(sockfd, user_port, sizeof(user_port), 0, (struct sockaddr*)&server_addr, len);

    char command[50];
    do{
        printf("Inserisci il comando: <exit> <lista_utenti> <get_user_files -user> <get_user_info -user> <connect_to -ip>: ");
        scanf("%s", command);
        sendto(sockfd, command, strlen(command), 0, (struct sockaddr*)&server_addr, len);

        if(strstr(command, "connect_to -")){
            char separatore[] = "connect_to -";
            char *ip;

            ip = strstr(command, separatore);
            if (ip != NULL)
                ip += strlen(separatore);
            
            connect_to(ip);
            break;
        }

        n = recvfrom(sockfd, buffer, 499, 0, (struct sockaddr*)&server_addr, &len);
        buffer[n] = 0;
        printf("Risposta ricevuta al comando dal server: %s\n", buffer);

    } while(strcmp(command, "exit") != 0);

    close(sockfd);
    return 0;
}
