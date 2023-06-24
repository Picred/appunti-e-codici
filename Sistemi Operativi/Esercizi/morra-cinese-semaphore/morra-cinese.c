/**
    @author: Picred (https://github.    com/picred)
    @file morra-cinese.c
    @brief morra cinese con thread e semafori
    @version 1.0
    @date 24/06/2023    
*/

#include "../lib-misc.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <string.h>
#include <unistd.h>


#define DEFAULT_NUMERO_PARTITE 5
#define PUNTI_VITTORIA 5
#define NUM_THREADS 4
#define CARTA 'C'
#define SASSO 'S'
#define FORBICE 'F'

typedef struct {
    char mossaP1, mossaP2;
    int vincitore;
    unsigned int puntiP1, puntiP2, partite_rimanenti;

    sem_t tabellone, giudice, P1, P2;
} game_t;


typedef struct {
    pthread_t tid;
    char* name;

    game_t* game;
} thread_data_t;



void* player1_function(void* arg) {
    int err;

    assert(arg);
    thread_data_t* data_ptr = (thread_data_t*)arg;
    printf("[%s] attivato...\n", data_ptr->name);

    srand(time(NULL));

    while(1){
        /* Mutex mossa Lock per le mosse */
        if((err = sem_wait(&data_ptr->game->P1)))
            exit_with_err("sem_wait", err);

        if (data_ptr->game->partite_rimanenti == 0)
            break;
        
        unsigned int seed = 123456789;
        int rnd = rand_r(&seed)%3;
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

        flockfile(stdout);
        printf("[%s] ha scelto %c\n", data_ptr->name, data_ptr->game->mossaP1);
        funlockfile(stdout);

            
        if (( err = sem_post(&data_ptr->game->giudice)))
            exit_with_err("sem_post", err);
    
    }
    
    if (( err = sem_post(&data_ptr->game->giudice)))
        exit_with_err("sem_post", err);
    
    return (NULL);
}


void* player2_function(void* arg) {
    int err;
    assert(arg);
    thread_data_t* data_ptr = (thread_data_t*)arg;
    printf("[%s] attivato...\n", data_ptr->name);
    
    srand(time(NULL));
    while(1){
        if((err = sem_wait(&data_ptr->game->P2)))
            exit_with_err("sem_wait", err);
        
        if(data_ptr->game->partite_rimanenti==0)
            break;

        int rnd = rand()%3;
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

        flockfile(stdout);
        printf("[%s] ha scelto %c\n", data_ptr->name, data_ptr->game->mossaP2);
        funlockfile(stdout);

        if((err = sem_post(&data_ptr->game->giudice)))
            exit_with_err("sem_post", err);
        }

    if((err = sem_post(&data_ptr->game->giudice)))
        exit_with_err("sem_post", err);
    
    return (NULL);
}


void* giudice_function(void* arg) {
    assert(arg);
    thread_data_t* data_ptr = (thread_data_t*)arg;
    printf("[%s] attivato...\n", data_ptr->name);
    int err;

    while(1){

        if((err = sem_wait(&data_ptr->game->giudice)))
            exit_with_err("sem_wait", err);

        if((err = sem_wait(&data_ptr->game->giudice)))
            exit_with_err("sem_wait", err);

        if(data_ptr->game->partite_rimanenti==0)
            break;

        
        if(data_ptr->game->mossaP1 == data_ptr->game->mossaP2){
            if((err = sem_post(&data_ptr->game->P1)))
                exit_with_err("sem_post", err);

            if((err = sem_post(&data_ptr->game->P2)))
                exit_with_err("sem_post", err);
            
            continue;
        }
        else if(data_ptr->game->mossaP1 == CARTA && data_ptr->game->mossaP2 == SASSO ||
                data_ptr->game->mossaP1 == FORBICE && data_ptr->game->mossaP2 == CARTA||
                data_ptr->game->mossaP1 == SASSO && data_ptr->game->mossaP2 == FORBICE)
            data_ptr->game->vincitore = 1;
    
        else 
            data_ptr->game->vincitore = 2;

        printf("[GIUDICE] Vincitore round: Player%d\n", data_ptr->game->vincitore);

        /* Mutex tabellone unlock */
        if((err = sem_post(&data_ptr->game->tabellone)))
            exit_with_err("sem_post", err);
    }

    return (NULL);
}



void* tabellone_function(void* arg) {
    assert(arg);
    thread_data_t* data_ptr = (thread_data_t*)arg;
    printf("[%s] attivato...\n", data_ptr->name);
    int err;

    while(data_ptr->game->partite_rimanenti > 0){
    
        if((err = sem_wait(&data_ptr->game->tabellone)))
            exit_with_err("sem_wait", err);

        assert(data_ptr->game->vincitore == 1 || data_ptr->game->vincitore == 2 || data_ptr->game->vincitore == 0);
        data_ptr->game->partite_rimanenti-=1;
        printf("[%s]---------------------Partite rimanenti: %d---------------------\n", data_ptr->name, data_ptr->game->partite_rimanenti);

        switch(data_ptr->game->vincitore){
            case 1:
                data_ptr->game->puntiP1+=PUNTI_VITTORIA;
                break;
            case 2:
                data_ptr->game->puntiP2+=PUNTI_VITTORIA;
                break;
        }

        // Debug
        printf("[TABELLONE] Classifica temporanea:\n");
        printf("[TABELLONE] Punti P1: %d\n", data_ptr->game->puntiP1);
        printf("[TABELLONE] Punti P2: %d\n", data_ptr->game->puntiP2);

        // reset mosse e vincitore
        data_ptr->game->mossaP1 = ' ';
        data_ptr->game->mossaP2 = ' ';
        data_ptr->game->vincitore = -1;

        /* Mutex mosse unlock */

        sleep(2);
        if((err = sem_post(&data_ptr->game->P1)))
            exit_with_err("sem_wait", err);
        
        if((err = sem_post(&data_ptr->game->P2)))
            exit_with_err("sem_wait", err);
    }

    if((err = sem_post(&data_ptr->game->P1)))
        exit_with_err("sem_wait", err);
    
    if((err = sem_post(&data_ptr->game->P2)))
        exit_with_err("sem_wait", err);

    int winner;
    if(data_ptr->game->puntiP1 > data_ptr->game->puntiP2)
        winner = 1;
    else if(data_ptr->game->puntiP1 < data_ptr->game->puntiP2)
        winner = 2;
    else
        winner = 0;

    if(winner==0)
        printf("[TABELLONE] La partita e' terminata in parita'\n");
    else
        printf("[TABELLONE] Il vincitore e' P%d\n", winner);
    
    pthread_exit(NULL); // winner = 1 o = 2 se P1 o P2 rispettivamente
}

int main(int argc, char** argv) {
    int err;
    game_t game;
    thread_data_t thread_data[NUM_THREADS];


    if (argc == 2) {
        assert(atoi(argv[1]) >= 0);
        game.partite_rimanenti = atoi(argv[1]);
    }
    else
        game.partite_rimanenti = DEFAULT_NUMERO_PARTITE;
    game.puntiP1=0;
    game.puntiP2=0;
    game.mossaP1=' ';
    game.mossaP2=' ';

    //inizializzazione mutex_sem e winner_sem
    if ((err = sem_init(&game.P1, PTHREAD_PROCESS_PRIVATE, 1)) != 0)
        exit_with_err("sem_init", err);
    
    if ((err = sem_init(&game.P2, PTHREAD_PROCESS_PRIVATE, 1)) != 0)
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
    for (int i = 0; i < NUM_THREADS; i++)
        if ((err = pthread_join(thread_data[i].tid, NULL)))
            exit_with_err("pthread_join", err);


    printf("[main] Thread terminati correttamente\n");

    /* Distruzione semafori */
    sem_destroy(&game.tabellone);
    sem_destroy(&game.P1);
    sem_destroy(&game.P2);

    for (int i = 0; i < NUM_THREADS; i++)
        free(thread_data[i].name);

    return EXIT_SUCCESS;
}
