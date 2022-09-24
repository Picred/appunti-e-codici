#include <iostream>
#include "serbatoio.h"

using namespace std;


int main()
{    
    //capacita e quantita iniziale
    Serbatoio s = Serbatoio(10,7);
    cout << s;
  
    //prelievo
    float inUscita = s.preleva(3);
    cout << "Prelevati: " << inUscita << " litri.\n"; 
    cout << s;

    //controllo stato 
    if (s.piuDiMeta())
       cout << "Abbondante!\n";
    else
       cout << "Scarseggia!\n";

    //prelievo totale
    inUscita += s.svuotaTutto();
    cout << "Serbatoio svuotato!\n";   
    cout << s;

    //deposita
    s.deposita(8);
    cout << "Depositati: 8 litri.\n";     
    cout << s;

    cout << "Contenuto prelevato in totale "
         << "dal serbatoio : " 
         << inUscita << " litri.\n";    

    return 0;
} 
