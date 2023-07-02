/**
    @author Picred (https://github.com/picred)
    @file lookup-database.c
    @brief Implementazione di un database che legge da file e permette di fare query
    @date 08/05/2023
    @version 1.0
*/

#include "list.h"
#include "../lib-misc.h"
#include <pthread.h>
#include <stdio.h>
#include <string.h>

#define DONE 3
#define QUIT 33

typedef struct{
    List* list;
    int done, quit;

    pthread_rwlock_t lock;
} shared_data_t;



typedef struct{
    pthread_t tid;
    char* filename;

    shared_data_t* shared;
} thread_data_t;


void file_reader_list_writer(void* arg){
    int err, res;
    thread_data_t* data_ptr = (thread_data_t*)arg;
    FILE* f;
    char buffer[BUFSIZ];

    if((f = fopen(data_ptr->filename, "r")) == NULL)
        exit_with_err_msg("fopen\n");

    //w_lock
    while(1){
        if(data_ptr->shared->quit == QUIT){
            printf("[DATABASE] Richiesta terminazione\n");
            break;
        }

        if((fgets(buffer, BUFSIZ, f))){
            buffer[strlen(buffer)-1] = '\0';

            char* key = strtok(buffer, ":");
            char* s_value = strtok(NULL, ":");

            if(key == NULL || s_value == NULL)
                exit_with_err_msg("strtok\n");

            int value = atoi(s_value);

            if((err = pthread_rwlock_wrlock(&data_ptr->shared->lock)))
                exit_with_err("pthread_rwlock_wrlock", err);

            list_insert(data_ptr->shared->list, key, value);          

            if ((err = pthread_rwlock_unlock(&data_ptr->shared->lock)))
                exit_with_err("pthread_rwlock_unlock", err);
            
            sleep(8);
        }
        else 
            break;
    }

    fclose(f);
    pthread_exit(NULL);
}


void q_function(void* arg){
    int err, res;
    thread_data_t* data_ptr = (thread_data_t*)arg;
    char buffer[BUFSIZ];

    //r_lock
    while(1){
        flockfile(stdout);
        printf("[QUERY]Inserisci la parola da ricercare: \n");
        funlockfile(stdout);
        scanf("%s", buffer);

        if(strcmp(buffer, "quit")==0){
            data_ptr->shared->quit = QUIT;
            break;
        }

        // lock list read
        if((err = pthread_rwlock_rdlock(&data_ptr->shared->lock)))
            exit_with_err("pthread_rwlock_rdlock", err);
        
        res = list_search_key(data_ptr->shared->list, buffer);

        if((err = pthread_rwlock_unlock(&data_ptr->shared->lock)))
            exit_with_err("pthread_rwlock_unlock", err);

        if(res > 0)
            printf("[QUERY](%s,%d)\n",buffer, res);
        else
            printf("[QUERY] (%s) No entry...\n",buffer);

    }

    pthread_exit(NULL);
}



void c_function(void* arg){
    int err, n_nodes;
    thread_data_t* data_ptr = (thread_data_t*)arg;

    //r_lock
    while(1){
        if(data_ptr->shared->quit == QUIT){
            break;    
        }
        if((err = pthread_rwlock_rdlock(&data_ptr->shared->lock)))
            exit_with_err("pthread_rwlock_rdlock", err);

        n_nodes = list_count_nodes(data_ptr->shared->list);

        if((err = pthread_rwlock_unlock(&data_ptr->shared->lock)))
            exit_with_err("pthread_rwlock_unlock", err);
        
        flockfile(stdout);
        printf("[COUNT] Data: +%d\n", n_nodes);
        funlockfile(stdout);
        
        sleep(8);
    }
    pthread_exit(NULL);
}


int main(int argc, char** argv){
    if(argc<2){
        printf("Usage: %s <n_threads>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int n_files = argc-1;
    int err;

    shared_data_t* shared_data = malloc(sizeof(shared_data_t));
    thread_data_t threads[n_files+2];

    shared_data->list=malloc(sizeof(List));
    shared_data->done=0;
    shared_data->quit=0;
    list_init(shared_data->list);


    if((err = pthread_rwlock_init(&shared_data->lock, NULL)))
        exit_with_err("pthread_rwlock_init", err);
    
    for(int i=0; i<n_files; i++){
        threads[i].filename = argv[i+1];
        threads[i].shared = shared_data;

        if((err = pthread_create(&threads[i].tid, NULL, (void *)file_reader_list_writer, (void *)&threads[i])))
            exit_with_err("pthread_create", err);   
    }

    //Q threads[n_files] e C threads[n_files+1]

    threads[n_files].shared = shared_data;
    threads[n_files].filename = NULL;
    threads[n_files+1].shared = shared_data;
    threads[n_files+1].filename = NULL;

    if((err = pthread_create(&threads[n_files].tid, NULL,(void*)q_function, (void *)&threads[n_files])))
        exit_with_err("pthread_create", err);


    if((err = pthread_create(&threads[n_files+1].tid, NULL,(void*)c_function, (void *)&threads[n_files+1])))
        exit_with_err("pthread_create", err);

    for(int i=0; i<n_files+2; i++){
        pthread_join(threads[i].tid, NULL);
    }

    return EXIT_SUCCESS;
}
