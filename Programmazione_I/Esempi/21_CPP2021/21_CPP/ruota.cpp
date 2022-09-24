#include <iostream>
#include <cstdlib>
#include <ctime>

#include "ruota.h"

using namespace std; 

RuotaFortunata::RuotaFortunata(){
  srand(time(0));
  this->possibiliVal = new int[DEFAULT_NUM_VALUES]; 
  for(int i=DEFAULT_MIN_VALUES; i<=DEFAULT_MAX_VALUES; i++)
    this->possibiliVal[i] = i;
  this->numPossVal = DEFAULT_NUM_VALUES;
}

RuotaFortunata::RuotaFortunata(int num, int min, int max){
  srand(time(0));
  this->possibiliVal = new int[num]; 
  for(int i=min; i<=max; i++)
    this->possibiliVal[i] = i;
  this->numPossVal = num;
}

RuotaFortunata::RuotaFortunata(int num, int *values){
  srand(time(0));
  this->possibiliVal = new int[num]; 
  for(int i=0; i<num; i++)
    this->possibiliVal[i] = values[i]; 
  this->numPossVal=num;
}

RuotaFortunata::~RuotaFortunata(){
  cout << "~RuotaFortunata" << endl; 
  delete [] this->possibiliVal; 
}

void RuotaFortunata::gira(){
  this->valoreCorrente = this->possibiliVal[rand()%(this->numPossVal)];
} 

int RuotaFortunata::getValoreCorrente(){
  return this->valoreCorrente; 
}

int RuotaFortunata::getNumPossibiliVal(){
  return this->numPossVal; 
}

int *RuotaFortunata::possibiliValori(){
  int *ret = new int[this->numPossVal];
  for(int k=0; k<this->numPossVal; k++)
    ret[k] = this->possibiliVal[k];
  return ret; 
}
