#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX(a,b) (a>b ? a : b)

#define A 10

/* 
* Ok, il compilatore fara' il suo meglio per sostituire 
* alla chiamata di funzione il codice della funzione stessa..
*/ 
inline int f (int n)
  {
    int k = n;

    k = 3*k;
    if (k<100)   
      return k;
    else   
      return k-100;
  }

/*  inline, MA funzione e' RICORSIVA
*   L'uso di inline non offre alcuna certezza che il compilatore 
*   operi delle sostituzioni in modo da ottenere una espressione costante...
*/
inline long ifatt (int n)
  {
    cout << "ifatt(), n=" << n << endl; 
    return  (n<2 ? 1 : n*ifatt(n-1));
  }

/* 
* constexpr indica al compilatore che l'espressione 
* va OBBLIGATORIAMENTE valuata a compile-time... 
*/ 
constexpr long cfatt (int n)   
  {
  //Non e' possibile inserire espressioni non-const all'interno della funzione..
//    cout << "cfatt(), n=" << n << endl; //not possible! non-constexpr expressioni..
    return  (n<2 ? 1 : n*cfatt(n-1));
  }

/* 
* La somma dei primi n numeri interi..
*/ 
inline long simpleRecursive (int n)
  {
    cout << "simpleRecursive(), n=" << n << endl;
    return (n==1 ? 1 : n+simpleRecursive(n-1));
  }

int main()
  {    
    long i = 20; 
    long iresult = ifatt(i); //fattoriale calcolato nel modo classico
    cout << "ifatt(" << i << ")= " << iresult << endl; 

    i = 10000; 
    //i = 10000000. Cosa succede? Troppe chiamata di funzione si accumulano nello stack...
    iresult = simpleRecursive(i); // esaurimento dello stack? 
    cout << "simpleRecursive(" << i << ")= " << iresult << endl; 

    //questa dara' ERRORE in fase di compilazione (overflow!). 
    //constexpr int a = 100; 
    constexpr int a = 20; // OK 
    constexpr long ret = cfatt(a); 
    cout << "cfatt(" << a << ")=" << ret << endl; 

    return 0;
  }

//*****************************************************************
//*****************************************************************
