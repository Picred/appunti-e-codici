#include <iostream>

#include <ctime>
#include <cstdlib>

using namespace std;

//stampa array
void printArr(const int *arr, int n){
  for(int i=0; i<n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

//Non va bene, res e' una variabile locale
//indirizzo restituito non sara' valido 
//per la funzione chiamante
int *sumLocal(const int *a, const int *b, int n){
  int res[n]; //WARNING in fase di compilazione

  for(int i=0; i<n; i++)
    res[i] = a[i] + b[i];

  return res;
}

//Ok, ret e' un puntatore ad un area di memoria 
//passata come parametro, allocata localmente 
//o dinamicamente 
void sumRet(const int *a, const int *b, int *ret, int n){
  
  for(int i=0; i<n; i++)
    ret[i] = a[i] + b[i];

}

//OK, il puntatore restituito fa riferimento 
//ad un'area di memoria allocata dinamicante, 
//indirizzo restituito sara' valido per il chiamante
int *sumDynamic(const int *a, const int *b, int n){
  int *res = new int[n]; //allocate the array into the free store

  for(int i=0; i<n; i++)
    res[i] = a[i] + b[i];
  
  return res;  
}

int main()
{
  int a[] = {1,2,3,4,5};
  int b[] = {2,3,6,7,9};
  int ret[5];

  int *p1 = sumLocal(a, b, 5); //NO!
  int *p2 = sumDynamic(a, b, 5); //OK
  sumRet(a, b, ret, 5); //OK

//  printArr(p1, 5); //Accesso "illecito" ad altra zona di memoria, segmentation fault su Linux

  printArr(p2, 5);

  printArr(ret, 5);
  
  return 0;
}

