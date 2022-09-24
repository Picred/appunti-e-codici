#include <iostream>

using namespace std; 

//allocazione dinamica di intero (HEAP) 
//allocazione statica di variabile puntatore (DATA) 
//Scope del puntatore global globale!! 
int *p_global = new int(2); 

//allocazione statica di intero (DATA) 
// Scope globale!!
int global = 10; 

void foo(){
  
  cout << "*p_global: " << *p_global << ", global:" << global; 

  //Si provi a decommentare la seg. linea di codice..
  //cout << "*dynamic: " << *dynamic << ", local: " << local << endl; 
}

int main(){

  cout << "*p_global: " << *p_global << ", global: " << global << endl; 

  //allocazione automatica (STACK) 
  //scope della variabile local locale!!
  int local = 1; 

  //allocazione dinamica (HEAP) 
  //scope del puntatore dynamic locale!! 
  int *dynamic = new int(3);

  foo();
  
}
