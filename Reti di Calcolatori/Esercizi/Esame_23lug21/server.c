/*
    Realizzare il seguente servizio di trasferimento file. La rete è formata da un server e da vari client, tutti uguali.

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


char* get_lista_utenti() {
    FILE* users = fopen("users.txt", "r");

    if (users == NULL){
        perror("Errore apertura file degli utenti. Se non esiste, crealo!");
        return NULL;
    }

    char lista_utenti[10000];
    memset(lista_utenti, 0, sizeof(lista_utenti));  // Inizializza la stringa a zero

    char temp_user[100];  // Array temporaneo per la lettura di ogni riga
    memset(temp_user, 0, sizeof(temp_user));  // Inizializza l'array temporaneo a zero

    while(fgets(temp_user, sizeof(temp_user), users) != NULL){
        strcat(lista_utenti, temp_user);
    }

    fclose(users);

    char* result = malloc(strlen(lista_utenti) + 1);  // Alloca memoria per la stringa risultante
    strcpy(result, lista_utenti);  // Copia la stringa nella memoria allocata

    return result;
}

char* get_user_files(const char* username) {
    char path[strlen(username) + strlen(".txt")];
    strcpy(path, username);
    strcat(path, ".txt");

    FILE* user = fopen(path, "r");

    // Leggo il file fino a quando non trovo la stringa "List_of_files\n"
    char read_line[100];

    while(fgets(read_line, 100, user) != NULL) {
        if (strcmp(read_line, "List_of_files\n") == 0)
            break;
    }

    fscanf(user, "%s", read_line); // Leggo la riga della lista dei file
    fclose(user);

    char* result = malloc(strlen(read_line) + 1); // +1 per il terminatore null
    strcpy(result, read_line);

    return result;
}


// int main(){
//     printf("result: %s\n", get_user_files("picred"));
// }

char* get_user_info(const char* username) {
    char path[strlen(username) + strlen(".txt")];
    strcpy(path, username); 
    strcat(path, ".txt");

    FILE* user = fopen(path, "r");

    // leggo il file fino a quando non trovo la stringa "List_of_files\n"
    char read_line[100];
    char to_return[20];
    int num_op = 0;

    while(fgets(read_line, 100, user) != NULL && num_op < 2){
        if (strcmp(read_line, "Ip\n") == 0){
            fscanf(user, "%s", to_return);
            num_op++;
        }

        if (strcmp(read_line, "Port\n") == 0){
            fscanf(user, "%s", to_return);
            num_op++;
        }
    }

    fclose(user);
    char* result = malloc(strlen(read_line) + 1); // +1 per il terminatore null
    strcpy(result, read_line);

    return result;
}


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


int save_user_info(const char* user, const char* ip, const int port, const char* list_of_files){
    char user_file[strlen(user) + strlen(".txt")];
    strcpy(user_file, user);
    strcat(user_file, ".txt");

    FILE* file = fopen(user_file, "a"); //apro il file in append mode, se non esiste lo creo

    if (file == NULL) {
        perror("Errore apertura file utente");
        return -1;
    }

    //verifico se il file esiste già oppure no. Se esiste già, non lo riscrivo
    if(ftell(file) != 0)
        return 1;
    
    char port_str[6];
    sprintf(port_str, "%d", port); // conversione da int a stringa

    // Scrivo su file
    int info_len = strlen(user) + strlen(ip) + strlen(port_str) + strlen(list_of_files)
                + strlen("Username") + strlen("Ip") + strlen("Port") + strlen("List_of_files") + 4 + 1; // 4 per i 4 "\n"
    char to_write[info_len];

    memset(to_write, 0, sizeof(to_write));

    strcat(to_write, "Username\n");
    strcat(to_write, user);
    strcat(to_write, "\nIp\n");
    strcat(to_write, ip);
    strcat(to_write, "\nPort\n");
    strcat(to_write, port_str);
    strcat(to_write, "\nList_of_files\n");
    strcat(to_write, list_of_files);

    fprintf(file, "%s" ,to_write);

    fclose(file);
    return 1;
}


// -------- MAIN ----------------------------
int main(int argc, char** argv) {
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
    
    int result = save_user_info(user, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), list_of_files);

    if (result < 0) {
        perror("Errore salvataggio informazioni utente");
        return -1;
    }

    // for per attesa dei prossimi comandi
    
    // exit = esce dal ciclo e chiude il server
    // lista_utenti = invia la lista degli utenti registrati
    // get_user_list_of_files() = invia la lista di file disponibili per la copia di un user
    // get_user_info(user) = invia le informazioni di un utente (ip, porta)


    for(;;) {
        n = recvfrom(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0, (struct sockaddr*)&client_addr, &len);
        buffer[n] = '\0';

        char comando[n];
        strcpy(comando, buffer);

        if (strcmp(comando,"lista_utenti") == 0){
            if (get_lista_utenti() == NULL)
                break;
            sendto(sockfd, get_lista_utenti(), strlen(get_lista_utenti()), 0, (struct sockaddr*)&client_addr, len);
            continue;
        }


        if (strstr(comando, "get_user_files") != NULL) {
            char separatore[] = "get_user_files -";
            char user[100];

            user[0] = '\0'; // Assicurati che l'array sia inizializzato come stringa vuota
            char* user_ptr = strstr(comando, separatore);
            if (user_ptr != NULL) {
                user_ptr += strlen(separatore);
                sendto(sockfd, get_user_files(user), strlen(get_user_files(user)), 0, (struct sockaddr*)&client_addr, len);
            } else {
                // Gestione del caso in cui la sottostringa non viene trovata
                sendto(sockfd, "Errore: nome utente non specificato", strlen("Errore: nome utente non specificato"), 0, (struct sockaddr*)&client_addr, len);
            }
            continue;
        }



        if (strstr(comando, "get_user_info") != NULL){
            char separatore[] = "get_user_info -";
            char *user;

            user = strstr(comando, separatore);
            if (user != NULL)
                user += strlen(separatore);
            
            sendto(sockfd, get_user_info(user), strlen(get_user_info(user)), 0, (struct sockaddr*)&client_addr, len);
            continue;
        }

    }

    close(sockfd);
    return 0;
}


// int main() {
//     char comando[100];
//     printf("Inserisci il comando: ");
//     fgets(comando, sizeof(comando), stdin);

//     // Rimuovi il carattere di newline dalla stringa letta da fgets
//     size_t len = strlen(comando);
//     if (len > 0 && comando[len - 1] == '\n') {
//         comando[len - 1] = '\0';
//     }


//     char separatore[] = "get_user_files -";
//     if (strncmp(comando, separatore, strlen(separatore)) == 0) {
//         char user[100];
//         strcpy(user, comando + strlen(separatore));
//         printf("files: %s", get_user_files(user));
        
//     } else {
//         printf("fail");
//     }
//     return 0;
// }
