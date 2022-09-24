#include <iostream>
#include <iomanip>

#define MSG_L 15
#define PTR_L 15
#define V_L 8

#define SIZE 5

using namespace std; 

/* Stampa gli elementi del vettore 
  mediante aritmetica dei 
  puntatori e operatore [] + indici 
*/ 
void f(int a[]){
  cout << endl; 
  //stampa il puntatore 
  cout << setw(MSG_L) << "f(), a: " << setw(PTR_L) << a << endl;  
  //stampa il valore all'indice 0 (primo elemento) 
  cout << setw(MSG_L) << "f(), a[0]: " << setw (V_L) << a[0] << endl; 
  //stampa il valore del primo elemento 
  cout << setw(MSG_L) << "f(), *a: " << setw(V_L) << *a << endl;

  //stampa il valore del puntatore del secondo elemento 
  cout << setw(MSG_L) << "f(), (a+1): " << setw(PTR_L) << (a+1) << endl; 
  //stampa il valore dello elemento all'indice 1
  cout << setw(MSG_L) << "f(), a[1]: " << setw (V_L) << a[1] << endl; 
  //stampa il valore del secondo elemento 
  cout << setw(MSG_L) << "f(), *(a+1): " << setw(V_L) << *(a+1) << endl; 
}

/* 
  Mostra la relazione 
  tra gli indirizzi del 
  vettore passato come argomento, 
  per mostrare che lo array e' fatto di 
  celle di memoria contigue. 
*/ 
void showAddr(int  *v, int n){
  cout << "showAddr()" << endl; 
  int *prev = nullptr; 
   for(int i=0; i<n; i++){
      cout << "Address-of(v[" << i << "])=" << &(v[i]); 
      if(&v[i] == prev+1)
	cout << " == Address-of(v[" << (i-1) << "])+1" << endl;  
      else 
	cout <<  endl; 
      prev = &v[i];
    }
}


int main(){

  //Array allocato sullo stack 
  int a[SIZE] = {1,2,3,4,5};

  showAddr(a, SIZE); 

  f(a);
}
