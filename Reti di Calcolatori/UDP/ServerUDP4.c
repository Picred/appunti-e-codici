// Server riceve un msg. Lo stampa. Risponde al client come se fosse un ACK.
//Se il client scrive FINE, allora il server chiude la connessione con QUEL CLIENT MA rimane attivo perchè deve ascoltare eventuali altri client

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char** argv){
    int sockfd, n; //descrittore socket
    struct sockaddr_in local_addr, dest_addr;
    socklen_t len = sizeof(struct sockaddr_in); //lunghezza della struct 
    char buffer[100];

    if (argc < 2){
        printf("Errore: Inserisci la porta\n");
        return 0;
    }
    
    
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
        printf("\nErrore nell'apertura di socket!");
        return -1;
    }


    memset(&local_addr, 0, len); //da questo indirizzo metti 0 fino alla sua dimensione
    local_addr.sin_family = AF_INET; //setto la famiglia di local_addr
    local_addr.sin_port = htons(atoi(argv[1])); //setto anche la porta

    //devo riservare al processo quella porta. Tutti i pacchetti li devi mandare a quel processo esclusivamente
    if (bind(sockfd, (struct sockaddr *)&local_addr, len) < 0){
        printf("Errore! Inserisci un numero di porta valido\n"); // Porta gia in uso
        return -1;
    }
    
    for(;;){
        n = recvfrom(sockfd, buffer, 99, 0, (struct sockaddr *)&dest_addr, &len); //99=max dim. 0=flag che non ci serve
        // n = numero di informazioni ricevute
        buffer[n] = 0;
        printf("Messaggio: %s, IP: %s, Port: %d \n", 
                buffer, 
                inet_ntoa(dest_addr.sin_addr),
                ntohs(dest_addr.sin_port));
        sendto(sockfd, buffer, strlen(buffer),0, (struct sockaddr*)&dest_addr, len);
    }

    close(sockfd);

    return 0;

    // ./Receiver.exe 5533 ->va in mod: ascolto sulla porta 5533
}