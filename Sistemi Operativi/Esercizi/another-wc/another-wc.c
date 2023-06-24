
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "../lib-misc.h"
#include <fcntl.h>
#include <libgen.h>


#define NUM_THREADS 2
#define DONE 'v' //(=='v') => fine operazione, (!='v') => viceversa

typedef enum {MAIN, CHILD} thread_n;
typedef struct{
    char letter;
    char done;

    sem_t main, child;
} shared_data_t;

typedef struct {
    pthread_t tid;
    FILE* file;

    shared_data_t* shared_data;
} thread_data_t;

void main_function(void* arg){
    int err, spaces = 0, lines = 1, letters = 0;
    thread_data_t* data_ptr = (thread_data_t*)arg;

    while(1){
        if((err = sem_wait(&data_ptr->shared_data->main)))
            exit_with_err("sem_wait", err);

        if(data_ptr->shared_data->done == DONE){
            letters++; //conteggio anche il carattere di terminazione
            // data_ptr->shared_data->done = DONE;
            break;
        }

        switch(data_ptr->shared_data->letter){
            case '\n':
                lines++;
                break;
            case ' ':
                spaces++;
                break;
            case '.':
            case '!':
            case '?':
            case ':':
            case ';':
                break;
            default:
                letters++;
        }

        if((err = sem_post(&data_ptr->shared_data->child)))
            exit_with_err("sem_post", err);
    }

    flockfile(stdout);
    printf("[my-wc] Letters: %d - Lines: %d - Spaces: %d\n", letters, lines, spaces);
    funlockfile(stdout);
    
    pthread_exit(NULL);
}

void child_function(void* arg){
    int err, nbytes;
    char buffer;
    thread_data_t* data_ptr = (thread_data_t*)arg;

    while(1){
        if((err = sem_wait(&data_ptr->shared_data->child)))
            exit_with_err("sem_wait", err);
        
        if(data_ptr->shared_data->done == DONE)
            break;
        
        if((fscanf(data_ptr->file, "%c", &data_ptr->shared_data->letter)) == EOF){
            data_ptr->shared_data->done = DONE;
            break;
        }
        
        if((err = sem_post(&data_ptr->shared_data->main)))
            exit_with_err("sem_post", err);
            
    }
    if((err = sem_post(&data_ptr->shared_data->main)))
            exit_with_err("sem_post", err);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int err;
    FILE* file = malloc(sizeof(FILE*));

    if(argc == 2){
        if((file = fopen(argv[1], "r")) == NULL)
            exit_with_err_msg("File specificato non trovato.\n");
    } else if (argc == 1){
        if((file = fopen("input_stdin.txt", "w+")) == NULL)
            exit_with_err_msg("open");

        printf("Non hai inserito argomenti. Digita quello che vuoi analizzare e creero' il file per te\nDigita \"quit\" per terminare\n");
        while(1){
            char buffer[BUFSIZ];
            fgets(buffer, sizeof(buffer), stdin);
            
            if(strcmp(buffer, "quit\n") == 0)
                break;
            
            fputs(buffer, file);
        }
        rewind(file);
    } else {
        exit_with_err_msg("Usage: ./%s [<file.txt>]\n", basename(argv[0]));
    }

    shared_data_t* shared_data = malloc(sizeof(shared_data_t));
    thread_data_t threads[NUM_THREADS];

    for(int i=0; i<NUM_THREADS;i++)
        threads[i].shared_data = shared_data;

    shared_data->done= 'x';
    threads[CHILD].file = file;
    threads[MAIN].file = NULL;

    if((err = sem_init(&shared_data->child, 0, 1)))
        exit_with_err("sem_init", err);


    if((err = sem_init(&shared_data->main, 0, 0)))
        exit_with_err("sem_init", err);


    if((err = pthread_create(&threads[MAIN].tid, NULL, (void*)main_function, (void*)&threads[MAIN])))
        exit_with_err("pthread_create", err);


    if((err = pthread_create(&threads[CHILD].tid, NULL, (void*)child_function, (void*)&threads[CHILD])))
        exit_with_err("pthread_create", err);
    // printf("%lu\n", sizeof(shared_data_t));


    for(int i=0; i<NUM_THREADS; i++)
        if((err = pthread_join(threads[i].tid, NULL)))
            exit_with_err("pthread_join", err);
    
    free(shared_data);
    free(file);
    sem_destroy(&shared_data->child);
    sem_destroy(&shared_data->main);

    return EXIT_SUCCESS;
}