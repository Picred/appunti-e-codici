/*# Morra Cinese (semafori)
Creare un programma **morra-cinese.c** in linguaggio C che accetti invocazioni sulla riga di comando del tipo:
```bash
morra-cinese <numero-partite>
```

Il programma gestisce una serie di partite tra due giocatori virtuali (thread) P1 e P2 che giocano alla Morra Cinese.
Il programma creerà: due thread P1 e P2 che rappresenteranno i giocatori, un thread giudice G e un thread tabellone T.
I thread condivideranno una struttura dati e useranno un certo numero di semafori (minimo a scelta dello studente) da usare opportunamente.

La struttura dati dovrà contenere i dati relativi ad una singola partita con i seguenti specifici campi:
- **mossa_p1**: C(arta)/F(orbici)/S(asso)
- **mossa_p2**: C/arta/F(orbici)/S(asso)
- **vincitore**: 1 (giocatore 1)/2 giocatore(2)
- (eventuali dati ausiliari)

Iniziata una partita, P1 e P2 popolano i relativi campi con una propria mossa casuale; ognuno, fatta la mossa, deve segnalare la cosa al processo
G che valuterà chi ha vinto, se c'è un vincitore allora G popolerà il campo apposito e segnalerà la disponibilità di un nuovo esito al processo T;
se invece la partita è patta (stessa mossa), allora lancerà direttamente una nuova partita. Il processo T, in caso di vittoria,
aggiornerà la propria classifica interna e avvierà, se necessario, una nuova partita. Sempre T, alla fine della serie di partite,
decreterà l'eventuale vincitore.

I thread dovranno tutti terminare spontaneamente alla fine del torneo.
*/

#include "lib-misc.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <string.h>
#include <Windows.h>

#define DEFAULT_NUMERO_PARTITE 5
#define NUM_THREADS 4
#define CARTA 'C'
#define SASSO 'S'
#define FORBICE 'F'
#define PUNTI_VITTORIA 5
#define PUNTI_PAREGGIO 1

typedef struct {
    char mossaP1, mossaP2;
    int vincitore;
    unsigned int puntiP1, puntiP2, num_mosse, partite_rimanenti;

    sem_t tabellone, giudice, mossa;
} game_t;


typedef struct {
    pthread_t tid;
    char* name;

    game_t* game;
} thread_data_t;



void* player1_function(void* arg) {
    assert(arg);
    thread_data_t* data_ptr = (thread_data_t*)arg;
    printf("[%s] attivato...\n", data_ptr->name);

    assert(data_ptr->game->num_mosse>0);
    srand(time(NULL));

    while(data_ptr->game->partite_rimanenti>0){
        /* Non serve mutex */
        if (data_ptr->game->mossaP1 == ' '){
            int rnd = rand()%3;
            int err;
            switch (rnd){
                case 0:
                    data_ptr->game->mossaP1 = CARTA;
                    break;
                case 1:
                    data_ptr->game->mossaP1 = SASSO;
                    break;
                case 2:
                    data_ptr->game->mossaP1 = FORBICE;
                    break;
            }

            _lock_file(stdout);
            printf("[%s] ha scelto %c\n", data_ptr->name, data_ptr->game->mossaP1);
            _unlock_file(stdout);

            /* Mutex mossa Lock per le mosse */
            if((err = sem_wait(&data_ptr->game->mossa)) && data_ptr->game->num_mosse > 0 )
                exit_with_err("sem_wait", err);
            
            continue;
            data_ptr->game->num_mosse--;
            // printf("\n[P1] num_mosse: %d\n", data_ptr->game->num_mosse);

            if((data_ptr->game->num_mosse == 0 )|| (data_ptr->game->mossaP1 != ' ' && data_ptr->game->mossaP2 != ' '))
                sem_post(&data_ptr->game->giudice);
        }
    }
    
    if(data_ptr->game->partite_rimanenti == 0)
        pthread_exit(NULL);
}


void* player2_function(void* arg) {
    assert(arg);
    thread_data_t* data_ptr = (thread_data_t*)arg;
    printf("[%s] attivato...\n", data_ptr->name);
    
    srand(time(NULL));
    while(data_ptr->game->partite_rimanenti>0){

        /* Non serve mutex */
        if (data_ptr->game->mossaP2 == ' '){
            int rnd = rand()%3;
            int err;
            switch (rnd){
                case 0:
                    data_ptr->game->mossaP2 = FORBICE;
                    break;
                case 1:
                    data_ptr->game->mossaP2 = CARTA;
                    break;
                case 2:
                    data_ptr->game->mossaP2 = SASSO;
                    break;
            }

            _lock_file(stdout);
            printf("[%s] ha scelto %c\n", data_ptr->name, data_ptr->game->mossaP2);
            _unlock_file(stdout);

            /* Mutex Lock per il numero di mosse */
            if((err = sem_wait(&data_ptr->game->mossa)) && data_ptr->game->num_mosse > 0 )
                exit_with_err("sem_wait", err);
            continue;
            data_ptr->game->num_mosse--;
            // printf("\n[P2] num_mosse: %d\n", data_ptr->game->num_mosse);



        }
            if((data_ptr->game->num_mosse == 0 )|| (data_ptr->game->mossaP1 != ' ' && data_ptr->game->mossaP2 != ' '))
                sem_post(&data_ptr->game->giudice);
    }

    if(data_ptr->game->partite_rimanenti == 0)
        pthread_exit(NULL);
}



void* giudice_function(void* arg) {
    assert(arg);
    thread_data_t* data_ptr = (thread_data_t*)arg;
    printf("[%s] attivato...\n", data_ptr->name);
    int err;

    /* Mutex giudice Lock */
    while(data_ptr->game->partite_rimanenti>0){

        if((err = sem_wait(&data_ptr->game->giudice)))
            exit_with_err("sem_wait", err);

        /* Verifico se entrambi i player hanno fatto la loro mossa */

        // if(data_ptr->game->mossaP1 == ' ' || data_ptr->game->mossaP2 == ' ')
        //     if((err = sem_post(&data_ptr->game->mossa)))
        //         exit_with_err("sem_post", err);

        /* Debug */
        // printf("[GIUDICE] Sono stato sbloccato\n");
        // printf("[GIUDICE] MossaP1: %c\n",data_ptr->game->mossaP1);
        // printf("[GIUDICE] MossaP2: %c\n",data_ptr->game->mossaP2);

        // TODO: logica di vincita
        
        if(data_ptr->game->mossaP1 == data_ptr->game->mossaP2)
            data_ptr->game->vincitore = 0;
        else if(data_ptr->game->mossaP1 == CARTA && data_ptr->game->mossaP2 == SASSO)
            data_ptr->game->vincitore = 1;
        else if(data_ptr->game->mossaP1 == CARTA && data_ptr->game->mossaP2 == FORBICE)
            data_ptr->game->vincitore = 2;
        else if(data_ptr->game->mossaP1 == SASSO && data_ptr->game->mossaP2 == CARTA)
            data_ptr->game->vincitore = 2;
        else if(data_ptr->game->mossaP1 == SASSO && data_ptr->game->mossaP2 == FORBICE)
            data_ptr->game->vincitore = 1;
        else if(data_ptr->game->mossaP1 == FORBICE && data_ptr->game->mossaP2 == CARTA)
            data_ptr->game->vincitore = 1;
        else if(data_ptr->game->mossaP1 == FORBICE && data_ptr->game->mossaP2 == SASSO)
            data_ptr->game->vincitore = 2;

        // printf("[GIUDICE] Vincitore: %d\n", data_ptr->game->vincitore);

        /* Mutex tabellone unlock */
        if((err = sem_post(&data_ptr->game->tabellone)))
            exit_with_err("sem_post", err);
    }

    if(data_ptr->game->partite_rimanenti == 0)
        pthread_exit(NULL);
}



void* tabellone_function(void* arg) {
    assert(arg);
    thread_data_t* data_ptr = (thread_data_t*)arg;
    printf("[%s] attivato...\n", data_ptr->name);
    int err, game_winner;

    while(data_ptr->game->partite_rimanenti > 0){
    
        if((err = sem_wait(&data_ptr->game->tabellone)))
            exit_with_err("sem_wait", err);

        printf("[%s]---------------------Partite rimanenti: %d---------------------\n", data_ptr->name, data_ptr->game->partite_rimanenti);

        // TODO: logica dei punti per partite_rimanenti partite

        data_ptr->game->partite_rimanenti-=1;

        assert(data_ptr->game->vincitore == 1 || data_ptr->game->vincitore == 2 || data_ptr->game->vincitore == 0);

        switch(data_ptr->game->vincitore){
            case 0:
                data_ptr->game->puntiP1+=PUNTI_PAREGGIO;
                data_ptr->game->puntiP2+=PUNTI_PAREGGIO;
                break;
            case 1:
                data_ptr->game->puntiP1+=PUNTI_VITTORIA;
                break;
            case 2:
                data_ptr->game->puntiP2+=PUNTI_VITTORIA;
                break;
        }

        // Debug
        printf("[TABELLONE] Punti P1: %d\n", data_ptr->game->puntiP1);
        printf("[TABELLONE] Punti P2: %d\n", data_ptr->game->puntiP2);

        // reset mosse e vincitore
        data_ptr->game->mossaP1 = ' ';
        data_ptr->game->mossaP2 = ' ';
        data_ptr->game->num_mosse = 2;
        

        /* Pausa fra partite */
        Sleep(2);

        /* Mutex mosse unlock */
        if((err = sem_post(&data_ptr->game->mossa)))
            exit_with_err("sem_wait", err);
        
    }
    
    if(data_ptr->game->puntiP1 > data_ptr->game->puntiP2)
        game_winner=1;
    else
        game_winner=2;
    data_ptr->game->vincitore = -1;
    
    
    printf("[TABELLONE] Il vincitore e' P%d", game_winner);
    pthread_exit((void*)&game_winner); // winner = 1 o = 2 se P1 o P2 rispettivamente
}

int main(int argc, char** argv) {
    // srand(time(NULL));
    int err;
    game_t game;
    thread_data_t thread_data[NUM_THREADS];


    if (argc == 2) {
        assert(atoi(argv[1]) >= 0);
        game.partite_rimanenti = atoi(argv[1]);
    }
    else
        game.partite_rimanenti = DEFAULT_NUMERO_PARTITE;
    game.num_mosse=2;
    game.puntiP1=0;
    game.puntiP2=0;
    game.mossaP1=' ';
    game.mossaP2=' ';

    //inizializzazione mutex_sem e winner_sem
    if ((err = sem_init(&game.mossa, PTHREAD_PROCESS_PRIVATE, 1)) != 0)
        exit_with_err("sem_init", err);

    if ((err = sem_init(&game.tabellone, PTHREAD_PROCESS_PRIVATE, 0)) != 0)
        exit_with_err("sem_init", err);

    if ((err = sem_init(&game.giudice, PTHREAD_PROCESS_PRIVATE, 0)) != 0)
        exit_with_err("sem_init", err);
    
    //inizializzazione thread_data dei 4 thread Giudice, P1, P2 e Tabellone
    for (int i = 0; i < 4; i++){
        thread_data[i].game = &game;

    }

    /* creo 2 thread_player */
    printf("[main] Creazione dei 4 thread...\n");
    thread_data[0].name = malloc(strlen("Player1") + 1);
    thread_data[1].name = malloc(strlen("Player2") + 1);
    thread_data[2].name = malloc(strlen("Giudice") + 1);
    thread_data[3].name = malloc(strlen("Tabellone") + 1);

    strcpy(thread_data[0].name, "Player1");
    strcpy(thread_data[1].name, "Player2");
    strcpy(thread_data[2].name, "Giudice");
    strcpy(thread_data[3].name, "Tabellone");

    /* Thread Create Player 1 */
    if ((err = pthread_create(&thread_data[0].tid, NULL, player1_function, (void*)(&thread_data[0]))))
        exit_with_err("pthread_create", err);

    /* Thread Create Player 1 */
    if ((err = pthread_create(&thread_data[1].tid, NULL, player2_function, (void*)(&thread_data[1]))))
        exit_with_err("pthread_create", err);


    /* Thread Create Giudice*/
    if ((err = pthread_create(&thread_data[2].tid, NULL, giudice_function, (void*)(&thread_data[2]))))
        exit_with_err("pthread_create", err);

    /* Thread Create Tabellone */
    if ((err = pthread_create(&thread_data[3].tid, NULL, tabellone_function, (void*)(&thread_data[3]))))
        exit_with_err("pthread_create", err);


    printf("[main] Attesa della fine del torneo (join 4 thread)...\n");

    /* Attesa thread senza valori di ritorno */
    for (int i = 0; i < NUM_THREADS-1; i++)
        if ((err = pthread_join(thread_data[i].tid, NULL)))
            exit_with_err("pthread_join", err);

    /* Attesa Thread Tabellone per il risultato del vincitore del torneo */
    int* winner;
    if ((err = pthread_join(thread_data[NUM_THREADS-1].tid, (void**)&winner)))
            exit_with_err("pthread_join", err);
    
    /* 0 < winner < 3 */
    assert(*winner<3);
    assert(*winner>0);


    printf("[main] Il vincitore del torneo e' Player%s\n", *winner);

    /* Distruzione semafori */
    sem_destroy(&game.tabellone);
    sem_destroy(&game.mossa);

    for (int i = 0; i < NUM_THREADS; i++)
        free(thread_data[i].name);

    return EXIT_SUCCESS;
}

// Problemi: Non stampa le varie scelte dei player. Il tabellone non fa exit