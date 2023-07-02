//#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TRUE 0
#define FALSE -1

typedef struct _node{
    char* key;
    int val;
    struct _node* next;
}Node;

typedef struct{
    Node* head;
}List;

void list_init(List* list){
    list->head=NULL;
}

int list_is_empty(List* list){
    return (list->head == NULL ? TRUE:FALSE);
}


void list_insert(List* list, char* _key, int _val){
    if(list_is_empty(list) == TRUE){
        list->head = malloc(sizeof(Node));
        list->head->key=_key;
        list->head->val=_val;
        list->head->next=NULL;
        return;
    }

    Node* node = malloc(sizeof(Node));
    node->key=strdup(_key);
    node->val=_val;
    node->next=list->head;
    list->head=node;
}




//searchKey
int list_search_key(List* list, char* key){
    if(list_is_empty(list) == TRUE)
        return FALSE;
    
    Node* ptr = list->head;
    while(ptr!=NULL){
        if(strcmp(ptr->key, key) == 0)
            return ptr->val;
        ptr=ptr->next;
    }
    return FALSE;
}


int list_count_nodes(List* list){
    if(list_is_empty(list) == TRUE)
        return 0;
    
    int n_nodes=0;
    Node* ptr = list->head;
    while(ptr!=NULL){
        n_nodes++;
        ptr=ptr->next;
    }

    return n_nodes;
}

void list_print(List* list){
    if(list_is_empty(list) == TRUE){
        printf("List is empty\n");
        return;
    }
    Node* ptr = list->head;
    while(ptr!=NULL){
        printf("key: %s, val: %d\n", ptr->key, ptr->val);
        ptr=ptr->next;
    }
    printf("\n");
}