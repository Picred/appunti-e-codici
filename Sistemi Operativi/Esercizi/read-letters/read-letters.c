/**
    * @author Picred
    * @file read-letters.c
    * @brief  Letter counter from input file
    *
    * @date 2020-05-10
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include "lib-misc.h"
#include <ctype.h>

#define NUM_THREADS 2
#define DONE 0

typedef enum {AL, MZ} thread_n;

typedef struct {
    int STATS_al;
    int STATS_mz;
    int done;

    sem_t sem_al, sem_mz, sem_main;
} shared_stats_t;


typedef struct {
    pthread_t tid;

    shared_stats_t* shared_stats;
} thread_data_t;


typedef struct {
    pthread_t tid;
    int fd;

    shared_stats_t* shared_stats;
} thread_main_data_t;



void main_function(void* arg){
    int err, res;
    thread_main_data_t* data_ptr = (thread_main_data_t*)arg;
    
    //readed character
    char character;
    
    while(1){
        if((err = sem_wait(&data_ptr->shared_stats->sem_main)))
            exit_with_err("sem_wait", err);

        // Ended file? Break
        if ((res = read(data_ptr->fd, &character, 1)) == 0){
            data_ptr->shared_stats->done = DONE;

            if((err = sem_post(&data_ptr->shared_stats->sem_al)))
                exit_with_err("sem_post", err);

            if((err = sem_post(&data_ptr->shared_stats->sem_mz)))
                exit_with_err("sem_post", err);

            break; 
        }

        character = tolower((int)character);
        
        // special character?
        switch (character){
            case '.': case ',': case ';': case ':': case '!': case '?': case '-': case '_': case '(': case ')': case '[': case ']': case '{': case '}': case '\n': case ' ':
                if((err = sem_post(&data_ptr->shared_stats->sem_main)))
                    exit_with_err("sem_post", err);
                continue;
        }

        //TODO: check if it's a number
        
        if((character>='a' && character <= 'l'))
            if((err = sem_post(&data_ptr->shared_stats->sem_al)))
                exit_with_err("sem_post", err);

        if((character>='m' && character <= 'z'))
            if((err = sem_post(&data_ptr->shared_stats->sem_mz)))
                exit_with_err("sem_post", err);
    }

    pthread_exit(NULL);
}


void al_function(void* arg){
    int err;
    thread_data_t* data_ptr = (thread_data_t*)arg;

    while(1){
        if((err = sem_wait(&data_ptr->shared_stats->sem_al)))
            exit_with_err("sem_wait", err);
        
        if(data_ptr->shared_stats->done == DONE)
            break;

        data_ptr->shared_stats->STATS_al++;

        if((err = sem_post(&data_ptr->shared_stats->sem_main)))
            exit_with_err("sem_post", err);
    }

    pthread_exit(NULL);
}


void mz_function(void* arg){
    int err;
    thread_data_t* data_ptr = (thread_data_t*)arg;

    while(1){
        if((err = sem_wait(&data_ptr->shared_stats->sem_mz)))
            exit_with_err("sem_wait", err);

        if(data_ptr->shared_stats->done == DONE)
            break;

        data_ptr->shared_stats->STATS_mz++;

        if((err = sem_post(&data_ptr->shared_stats->sem_main)))
            exit_with_err("sem_post", err);
    }

    pthread_exit(NULL);
}



int main(int argc, char* argv[]){
    int err;
    if(argc != 2){
        fprintf(stderr, "Usage: %s <filename.txt>\n", argv[0]);
        return EXIT_FAILURE;
    }

    shared_stats_t* shared_stats = malloc(sizeof(shared_stats_t));
    thread_main_data_t main_thread_data;
    thread_data_t threads[NUM_THREADS];


    shared_stats->STATS_al = 0;
    shared_stats->STATS_mz = 0;
    shared_stats->done = 1;
    
    for(int i=0; i<NUM_THREADS; i++)
        threads[i].shared_stats = shared_stats;

    main_thread_data.shared_stats = shared_stats;

    if ((main_thread_data.fd = open(argv[1], O_RDONLY)) < 0)
        exit_with_err_msg("File doesn't exist..\n");

    if((err = sem_init(&shared_stats->sem_al, 0, 0))){
        exit_with_err("sem_init", err);
    }

    if((err = sem_init(&shared_stats->sem_mz, 0, 0))){
        exit_with_err("sem_init", err);
    }

    if((err = sem_init(&shared_stats->sem_main, 0, 1))){
        exit_with_err("sem_init", err);
    }

    /* Thread Thread main Creation*/
    if((err = pthread_create(&main_thread_data.tid, NULL , (void*)main_function, (void*)&main_thread_data)))
        exit_with_err("pthread_create", err);

    /* Thread AL creation*/
    if((err = pthread_create(&threads[AL].tid, NULL, (void*)al_function, (void*)&threads[AL])))
        exit_with_err("pthread_create", err);
    
    /* Thread MZ creation*/
    if((err = pthread_create(&threads[MZ].tid, NULL, (void*)mz_function, (void*)&threads[MZ])))
        exit_with_err("pthread_create", err);


    /* join AL-MZ threads*/
    for (int i = 0; i < NUM_THREADS; i++) {
        if ((err = pthread_join(threads[i].tid, NULL)))
            exit_with_err("pthread_join", err);
    }

    /* join main thread*/
    if((err = pthread_join(main_thread_data.tid, NULL)))
        exit_with_err("pthread_join", err);
    

    printf("[%s]\n(a-l)(A-L) characters: %d\n(m-z)(M-Z) characters: %d\n", argv[1], shared_stats->STATS_al, shared_stats->STATS_mz);

    close(main_thread_data.fd);
    sem_destroy(&shared_stats->sem_al);
    sem_destroy(&shared_stats->sem_mz);
    sem_destroy(&shared_stats->sem_main);
    free(shared_stats);

    return EXIT_SUCCESS;
}