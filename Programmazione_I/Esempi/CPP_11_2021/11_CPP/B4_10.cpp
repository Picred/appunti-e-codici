#include <iostream>

using namespace std;


int main()
{ 
    int i, j;
        
    cout << "Primo for:\n";
    for (i=1, j=0;   i<5;   i++, j++)
       cout << "i= " << i << " j= " << j << endl;
    
    /* 
       nel successivo for si usano due indici: i e j
       i viene incrementato di una unità al termine di ogni esecuzione del ciclo
       j viene raddoppiato al termine di ogni esecuzione del ciclo
       il controllo è eseguito solo sul valore della i
    */
    
    cout << "\nSecondo for:\n";			
    for (i=1, j=i+10;  i<5;  i++, j=i*2) 
       cout << "i= " << i << " j= " << j << endl; 
                  
                  
   system("PAUSE");
   return EXIT_SUCCESS;
}
