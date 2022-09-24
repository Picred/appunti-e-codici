#include <iostream>
#include <cstdlib> // per usare il generatore random
#include <ctime>

using namespace std; 

//dichiarazione funzioni OBBLIGATORIA 
//all'interno di namespace
namespace gaetano{  
  int estrai(int *v, int l); 
}

namespace claudio{
  int estrai(int *v, int l); 
}

//Definizione metodo 
// di puo' fare anche fuori 
// dal namespace
int gaetano::estrai(int *v, int l){
  return v[rand()%l]; 
}

int claudio::estrai(int *v, int l){
  return v[l/2];
}

int main(){

srand(time(0)); 

int v[] = {0,1,2,3,4,5,6,7,8,9}; 

//using gaetano::estrai; 
//using claudio::estrai;  

cout << "Using some implementation of estrai()" << endl; 
for(int i=0; i<10; i++)
  cout << gaetano::estrai(v, 10) << endl;

cout << "Using some implementation of estrai()" << endl; 
for(int i=0; i<10; i++)
  cout << claudio::estrai(v, 10) << endl;

}
