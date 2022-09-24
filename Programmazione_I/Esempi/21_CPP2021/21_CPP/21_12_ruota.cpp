#include "ruota.h"
#include <string>
#include <iostream>

using namespace std; 

int main(){  

  RuotaFortunata r(10, 0, 9);
  
  const int numeroFortunato = 8;

  const int maxTentativi = 10;

  cout << "La ruota fortunata, tot caselle=" << r.getNumPossibiliVal() << endl;

  int numTentativi = 0;
  while(numTentativi++<maxTentativi){
    r.gira();
    cout << "Risultato tentativo: " << r.getValoreCorrente() << endl;
    if(r.getValoreCorrente() == numeroFortunato){
      cout << "Hai vinto!" << endl;
      break;
    }
  }

  cout << "Num. tentativi: " << numTentativi-1 << endl;
}
