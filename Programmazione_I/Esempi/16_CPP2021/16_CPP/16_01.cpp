#include <iostream>
#include <cstdlib>
#include <ctime>

#define N_SAMPLES 10

using namespace std; 

int main(){

  const int primo_seme = 11223344; 
  const int secondo_seme = 22334455; 

  srand(primo_seme); 

  cout << "Primo campionamento, seme=" << primo_seme << endl;

  for(int i=0; i<N_SAMPLES; i++)
    cout << rand()%100 << endl; 


  srand(primo_seme); 

  cout << "Secondo campionamento, seme=" << primo_seme << endl; 

  for(int i=0; i<N_SAMPLES; i++)
    cout << rand()%100 << endl;

  srand(secondo_seme); 

  cout << "Terzo campionamento, seme=" << secondo_seme << endl; 

  for(int i=0; i<N_SAMPLES; i++)
    cout << rand()%100 << endl;
       
}
