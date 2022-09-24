#include <iostream>
#include <cstdlib>
#include <ctime>

#define N_SAMPLES 10

using namespace std; 

int main(){

  const time_t now = time(nullptr); 

  srand(now); 

  for(int i=0; i<N_SAMPLES; i++)
    cout << rand()%100 << endl; 
       
}
