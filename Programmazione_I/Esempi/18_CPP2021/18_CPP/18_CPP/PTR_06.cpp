#include <iostream>

#include <ctime>
#include <cstdlib>

using namespace std;

//prototipo della funzione,
//di norma si scrive in un file header
//la fuzione non potra' modificare i valori degli elementi puntati da a e b
int *sum(const int *a, const int *b, int n); 

int main()
{
    
  srand(time(0));

  int *p1 = new int[10];	
  int *p2 = new int[10];

  for(int i=0; i<10; i++ ){ //random values
    p1[i] = rand()%100;
    p2[i] = rand()%100;
  }

  for(int i=0; i<10; i++ ){ //print values
    cout << p1[i] <<  " ";
  }

  cout << endl;
  
  for(int i=0; i<10; i++ ){ //print values
    cout << p2[i] << " "; 
  }

  cout << endl;

  int *c = sum(p1, p2, 10);

  for(int i=0; i<10; i++ ){ //print values
    cout << c[i] << " " ;
  }

  cout << endl;

 return 0;
}

int *sum(const int *a, const int *b, int n){
  int *res = new int[n]; //allocate the array into the free store

  for(int i=0; i<n; i++)
    res[i] = a[i] + b[i];
  
  return res;  
}
