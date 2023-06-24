/**
    @author Picred (https://github.com/picred)
    @file alpha-stats.c
    @brief Conta le occorrenze di ogni lettera dell'alfabeto inglese in un file di testo
    @date 24/06/2023
    @version 1.0
*/

#include <pthread.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <libgen.h>
#include <ctype.h>
#include "../lib-misc.h"


#define NUM_THREADS 3
#define STATS_DIM 26
#define ALPBT_OFFSET 97

typedef enum {P, AL, MZ} thread_n;

typedef struct{
    char c;
    unsigned long stats[STATS_DIM];

    sem_t P, AL, MZ;
} shared_data_t;

typedef struct{
    pthread_t tid;
    char* filename;

    shared_data_t* shared_data;
} thread_data_t;



void P_function(void* arg){
    int err;
    thread_data_t* data_ptr = (thread_data_t*)arg;

    // File mapping
    int fd;
    struct stat fd_stats;
    char buffer[fd_stats.st_size];
    if ((fd = open(data_ptr->filename, O_RDONLY)) < 0 )
        exit_with_err_msg("Error opening file..\n");

    fstat(fd, &fd_stats);
    char* map_ptr = mmap(NULL, fd_stats.st_size, PROT_READ, MAP_SHARED, fd, 0);
    // End file mapping

    while(1){
        for(int i=0; i<fd_stats.st_size+1; i++){
            if((err = sem_wait(&data_ptr->shared_data->P)))
                exit_with_err("sem_wait", err);

            char letter = map_ptr[i];
            letter = (char)tolower(letter);

            strcpy(&data_ptr->shared_data->c, &letter);
            
            if((letter >= 'a' && letter <= 'l') || 
                (letter == '\n') || (letter == ' ') || (letter == '.') || (letter == ',')){
                if((err = sem_post(&data_ptr->shared_data->AL)))
                    exit_with_err("sem_post", err);
                    continue;

            } else if(letter >= 'm' && letter <= 'z'){ 
                if((err = sem_post(&data_ptr->shared_data->MZ)))
                    exit_with_err("sem_post", err);
                continue;    

            } else if( letter == '\0'){
                break;
            }
        }
        if((err = sem_post(&data_ptr->shared_data->MZ)))
            exit_with_err("sem_post", err);

        if((err = sem_post(&data_ptr->shared_data->AL)))
            exit_with_err("sem_post", err);        
        // Stampa statistiche
        int ascii_letter= 'a';
        
        flockfile(stdout);
        printf("[P]-----Statistiche finali-----\n");

        for(int i=0; i<STATS_DIM; i++){
            printf("[%c] = %lu ", (char)ascii_letter, data_ptr->shared_data->stats[i]);
            ascii_letter++;
            if(i!=0 && i%5== 0)
                printf("\n");
        }
        printf("----------\n[P]: terminazione...\n");
        
        funlockfile(stdout);
        pthread_exit(NULL);
    }
}


void AL_function(void* arg){
    int err;
    thread_data_t* data_ptr = (thread_data_t*)arg;

    flockfile(stdout);
    printf("[AL]: Thread inizializzato...\n");
    funlockfile(stdout);

    while(1){
        if((err = sem_wait(&data_ptr->shared_data->AL)))
            exit_with_err("sem_wait", err);

        if(data_ptr->shared_data->c == '\0'){
            flockfile(stdout);
            printf("[AL]: terminazione...\n");
            funlockfile(stdout);
            
            break;
        }
        // Gestione caso '\n'
        if(data_ptr->shared_data->c == '\n'){
            if((err = sem_post(&data_ptr->shared_data->P)))
                exit_with_err("sem_post", err);
            continue;
        }

        data_ptr->shared_data->stats[data_ptr->shared_data->c - ALPBT_OFFSET]++;

        if((err = sem_post(&data_ptr->shared_data->P)))
            exit_with_err("sem_post", err);
    }
    pthread_exit(NULL);
}


void MZ_function(void* arg){
    int err;
    thread_data_t* data_ptr = (thread_data_t*)arg;

    flockfile(stdout);
    printf("[MZ]: Thread inizializzato...\n");
    funlockfile(stdout);
    
    while(1){
        if((err = sem_wait(&data_ptr->shared_data->MZ)))
            exit_with_err("sem_wait", err);

        if(data_ptr->shared_data->c == '\0'){
            flockfile(stdout);
            printf("[MZ]: terminazione...\n");
            funlockfile(stdout);
            break;
        }

        data_ptr->shared_data->stats[data_ptr->shared_data->c - ALPBT_OFFSET]++;

        if((err = sem_post(&data_ptr->shared_data->P)))
            exit_with_err("sem_post", err);
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Usage: ./%s <input file>\n", basename(argv[0]));
        return EXIT_FAILURE;
    }
    int err;

    shared_data_t* shared_data = malloc(sizeof(shared_data_t));
    thread_data_t threads[NUM_THREADS];


    for(int i=0; i<STATS_DIM; i++)
        shared_data->stats[i] = 0;

    for(int i=0; i<NUM_THREADS; i++)
        threads[i].shared_data = shared_data;

    threads[P].filename = malloc(strlen(argv[1]));
    strcpy(threads[P].filename,argv[1]);

    threads[AL].filename = NULL;
    threads[MZ].filename = NULL;
    
    if((err = sem_init(&shared_data->P, 0, 1)))
        exit_with_err("sem_init", err);

    if((err = sem_init(&shared_data->AL, 0, 0)))
        exit_with_err("sem_init", err);

    if((err = sem_init(&shared_data->MZ, 0, 0)))
        exit_with_err("sem_init", err);


    if((err = pthread_create(&threads[P].tid, NULL, (void*)P_function, (void*)(&threads[P]))))
        exit_with_err("pthread_create", err);
    
    if((err = pthread_create(&threads[AL].tid, NULL, (void*)AL_function, (void*)(&threads[AL]))))
        exit_with_err("pthread_create", err);
    
    if((err = pthread_create(&threads[MZ].tid, NULL, (void*)MZ_function, (void*)(&threads[MZ]))))
        exit_with_err("pthread_create", err);
    

    for(int i=0; i<NUM_THREADS; i++)
        if((err = pthread_join(threads[i].tid, NULL)))
            exit_with_err("pthread_join", err);
    
    printf("Tutti i thread sono terminati con successo!\n");
    if((err = sem_destroy(&shared_data->AL)))
        exit_with_err("sem_destroy", err);
    
    if((err = sem_destroy(&shared_data->AL)))
        exit_with_err("sem_destroy", err);
    
    if((err = sem_destroy(&shared_data->AL)))
        exit_with_err("sem_destroy", err);

    free(shared_data);

    return EXIT_SUCCESS;
}