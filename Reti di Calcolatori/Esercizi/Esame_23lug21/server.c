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
#include <stdbool.h>


#define LOGIN_EFFETTUATO "Login effettuato"
#define REGISTRAZIONE_E_LOGIN "Registrazione e login effettuato"
#define MAX_USERNAME_LEN 50
#define MAX_FILES_STR 500
#define MAX_BUFFER_SIZE 500


char* check_user(const char* username) {
    FILE* users = fopen("users.txt", "r+");

    if (users == NULL) {
        perror("Errore apertura file degli utenti. Se non esiste, crealo!");
        return NULL;
    }

    char test_user[MAX_USERNAME_LEN];
    while (fgets(test_user, MAX_USERNAME_LEN, users) != NULL) {
        test_user[strlen(test_user) - 1] = '\0';
        if (strcmp(username, test_user) == 0) {
            //utente trovato, quindi è registrato
            return LOGIN_EFFETTUATO;
        }
    }

    //utente non registrato
    fseek(users, 0, SEEK_END);
    fprintf(users, "%s\n", username);
    fclose(users);
    return REGISTRAZIONE_E_LOGIN;
}


void save_user_info(const char* user, const char* ip, const int port, const char* list_of_files){
    mkdir(user);
    const char* sourceFile = "info.txt";
    const char* destinationFolder = user;

    FILE* file = fopen(sourceFile, "a"); //vedere modalità di scrittura

    // sprintf(port, "%d", port); //converto int in stringa (atoi è il contrario)
    //conversione di port in stringa
    char port_str[4];
    sprintf(port_str, "%d", port);

    //scrivo su file
    
    int info_len = strlen(user) + strlen(ip) + strlen(port_str) + strlen(list_of_files)
                + strlen("Username") + strlen("Ip") + strlen("Port") + strlen("List_of_files") + 4; // 4 per i 4 "\n"
    char to_write[info_len];

    strcat(to_write, "Username\n");
    strcat(to_write, user);
    strcat(to_write, "\nIp\n");
    strcat(to_write, ip);
    strcat(to_write, "\nPort\n");
    strcat(to_write, port_str);
    strcat(to_write, "\nList_of_files\n");
    strcat(to_write, list_of_files);

    fprintf(file, "%s" ,to_write);
    
    
    // Costruzione del comando di spostamento del file
    char command[100];
    snprintf(command, sizeof(command), "mv %s %s/%s", sourceFile, destinationFolder, sourceFile);

    // Esecuzione del comando di sistema per spostare il file
    int result = system(command);

    if (result == 0) 
        printf("Il file '%s' è stato scritto e spostato in '%s'.\n", sourceFile, destinationFolder);
    else 
        printf("Errore durante lo spostamento del file.\n");
        return;
}

int main(){
    // save_user_info("user", "192.192.192.192", 5656, "file1.txt,file2.txt");
    //funziona solo se si è root
    int n = rename("info.txt", "user/info.txt");
    printf("%d", n);
}


// -------- MAIN ----------------------------
int main2(int argc, char** argv) {
    int sockfd;
    struct sockaddr_in local_addr, client_addr;
    socklen_t len = sizeof(struct sockaddr_in);
    char buffer[MAX_BUFFER_SIZE];

    if (argc != 2) {
        perror("Usage: <server_port>\n");
        return 0;
    }

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Errore apertura socket");
        return -1;
    }

    memset(&local_addr, 0, len);
    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(atoi(argv[1]));
    local_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr*)&local_addr, len) < 0) {
        perror("Errore nella bind");
        return -1;
    }

    char user[MAX_USERNAME_LEN], list_of_files[MAX_FILES_STR];
    int n, user_port;

    //--------- ricevo username ---------------------------------------
    n = recvfrom(sockfd, buffer, MAX_USERNAME_LEN - 1, 0, (struct sockaddr*)&client_addr, &len);
    buffer[n] = 0;
    strcpy(user, buffer);
    strcpy(buffer, check_user(buffer));

    printf("%s -> %s\n", user, buffer); //log

    sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&client_addr, len); //risposta login effettuato (eventualmente + registrazione)

    //---------- ricevo file disponibili per la copia -------------------
    n = recvfrom(sockfd, list_of_files, MAX_FILES_STR - 1, 0, (struct sockaddr*)&client_addr, &len);
    list_of_files[n] = 0;

    printf("File disponibili per la copia per l'utente: %s \n -> %s \n", user, list_of_files); // log

    // --------- ricevo la porta di ascolto per questo user -------------
    n = recvfrom(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0, (struct sockaddr*)&client_addr, &len);
    buffer[n] = '\0';
    user_port = atoi(buffer);

    printf("Porta client: %d\n", user_port); //log
    /*
    fine punto 1
    */
    save_user_info(user, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), list_of_files);

    close(sockfd);
    return 0;
}
