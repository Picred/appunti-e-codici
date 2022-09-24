#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 

NB: qui va usato il compilatore per il linguaggio C, gcc 

$ gcc -Wall 33_01.c 

La parola chiave struct ha origine con il linguaggio C. 

Utile a definire tipi composti, ovvero le strutture.

Membri accessibili con operatore "." oppure con 
operatore freccia "->" se si tratta di puntatore.  

L'unico modo di ``associare'' funzioni alle strutture 
e' quello di definire campi puntatori a funzione
all'interno della struttura stessa. 

*/ 

struct C_Test{
  int a; 
  float b; 
  char *s;
  
  //void print(struct C_test *);  // ONLY in C++.  
  void (*print)(struct C_Test *); //Declaring pointer to function
  void (*init)(struct C_Test *); // Pointer to function 
}; 

/* 
  Like a C++ constructor. 
*/ 
void myinit(struct C_Test *ct){ 
  ct->a = 10; 
  ct->b = 56.7; 
  ct->s = (char *) malloc(sizeof(char)*15); 
  strcpy(ct->s, "Hello World!"); 
}

/* Like a C++ member function */ 
void myprint(struct C_Test *ct_ptr){
  printf("a=%d, b=%f, s=%s\n", ct_ptr->a, ct_ptr->b, ct_ptr->s);
}


int main(){

  //must declare variables with struct <struct_name>
  struct C_Test ct; //automatic allocation 
  struct C_Test * ct_ptr = &ct; // a pointer to 


  typedef struct C_Test test; 
  test ct2; //OK 

  ct2.a = 30; 

  ct_ptr->print = myprint; //associating functions to the data structure
  ct_ptr->init = myinit;

  ct_ptr->init(ct_ptr); // call to functions to operate on data
  ct_ptr->print(ct_ptr); 

}
