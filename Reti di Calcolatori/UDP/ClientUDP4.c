#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char** argv){
    int sockfd, n;
    struct sockaddr_in dest_addr; // Indirizzo remoto
    socklen_t len = sizeof(struct sockaddr_in); //dimensione della struttura
    char buffer[100];


    if (argc < 3){
        printf("Errore, inserici Ip e porta\n");
        return 0;
    }
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd < 0){
        printf("Errore nell'apertura di socket!");
        return -1;
    }
    
    
    memset(&dest_addr, 0, len); //dest_addr deve essere inizializzato a 0; metti tutto a 0 da 0 alla fine della lung. della struct
    dest_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &(dest_addr.sin_addr));
    dest_addr.sin_port = htons(atoi(argv[2]));


    // printf("Inserisci il numero di messaggi da inviare\n");
    // scanf("%s", &n);
    
    
    // for(int i=0; i<10; i++){ //invio 10 pacchetti -> si potrebbe modificare con while con fgets per leggere dall'input e inviarli al server
    //     sprintf(buffer, "%d", i+n); //mette nel buffer un intero che è (i+n)
    //     sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&dest_addr, len);
    //     n = recvfrom(sockfd, buffer, 99, 0, (struct sockaddr *)&dest_addr, &len);
    //     buffer[n]=0;

    //     printf("Messaggio: %s, IP: %s, Port: %d \n", 
    //             buffer, 
    //             inet_ntoa(dest_addr.sin_addr),
    //             ntohs(dest_addr.sin_port));
        
    //     if(strcmp(buffer, "fine") == 0){
    //         break;
    //     }
    // }


    while(fgets(buffer,10,stdin) != NULL){ //mette nel buffer, dallo stdin, max 99 elementi
        sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&dest_addr, len);
        n = recvfrom(sockfd, buffer, 99, 0, (struct sockaddr *)&dest_addr, &len);
        // buffer[n]= 0; //all'esame cambia solo questo buffer. Per il resto è uguale

        printf("Messaggio: %s, IP: %s, Port: %d \n", 
                buffer, 
                inet_ntoa(dest_addr.sin_addr),
                ntohs(dest_addr.sin_port));
        
        if(strcmp(buffer, "fine") == 0){
            break;
        }
    }

    // scanf("%s",buffer);
    sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&dest_addr, len);

    close(sockfd);

    return 0;

    // ./sender.exe <ip_dest> <porta> 
}

// Esercizio per la prossima volta da presentare: se il client invia una determinata parola, quell'indirizzo ip deve essere bannato in un file di testo. Ogni volta che si riceve un messaggio da un ip bannato, si deve mandare un print(errore)
// gestire un sistema di autenticazione e user e psw con i file di testo. Gestire anche l'eliminazione di un utente o cambio psw. ovviamente si deve registrare IP -> username -> psw. Gestire utenti gia presenti nell'elenco
// fare gli stessi esercizi anche con ipv6