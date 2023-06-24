/**
    @author Picred (https://github.com/picred)
    @file list.c
    @brief A simple implementation of a linked list in C, only insertions
    @date 24/06/2023
    @version 1.0
*/

#include <stdlib.h>
#include <stdio.h>


typedef struct node_s{
    int value;
    struct node_s* next;
} node_t;


typedef struct{
    node_t* head;
    // struct note_t* tail; 
    int size;
} list_t;



node_t* node_init(){
    node_t* node;
    node->next=NULL;
    node->value=0;
    return node;
}

node_t* node_init_with_val(int val){
    node_t* node;
    node->next=NULL;
    node->value=val;
    return node;
}

int node_get_val(node_t* node){
    return node->value;
}


void list_init(list_t* list){
    list->size = 0;
    list->head = NULL;
}


int list_get_size(list_t* list){
    return list->size;
}

int list_is_empty(list_t* list){
    return (list->head == NULL ? 0 : 1);
}

node_t* list_get_next(node_t* node){
    return node->next;
}

node_t* list_get_head(list_t* list){
    return list->head;
}

void list_print(list_t* list){
    node_t* ptr = malloc(sizeof(node_t)); 
    ptr = list_get_head(list);

    printf("List size: %d\n", list_get_size(list));
    printf("List head: %d\n\n", node_get_val(ptr));

    while(ptr != NULL){
        printf("Node: %d\n", node_get_val(ptr));
        ptr = list_get_next(ptr);
    }
}

void list_add_support(list_t* list, node_t* node){
    if(list_is_empty(list) == 0){
        list->head = node;
        list->size++;
        return;
    }

    node_t* ptr = malloc(sizeof(node_t)); 
    ptr = node_init_with_val(node_get_val(node));

    ptr->next=list->head;
    list->head = ptr;
    list->size++;
}

void list_add(list_t* list, int val){
    node_t* node = malloc(sizeof(node_t));
    node->value=val;
    node->next=NULL;
    list_add_support(list, node);
}



int main(int argc, char** argv){
    list_t* list = malloc(sizeof(list_t));

    list_init(list);

    list_add(list, 3);
    list_add(list, 725);
    list_add(list, 378);
    list_add(list, 169);
    list_add(list, 59);

    list_print(list);

    return EXIT_SUCCESS;
}
