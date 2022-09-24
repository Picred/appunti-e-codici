#include <iostream>

using namespace std;


int main()
{ 
     const int PER_LINEA = 5;

      
     int numero, limite;
     cout << "Inserisci un numero positivo : ";
     cin >> numero;
     
     cout << "\nInserisci il valore limite : ";
     cin >> limite;
      
     int i, cont = 0;
      
      
     cout << "\nI multipli di " << numero << " tra " << numero 
          << " e " << limite << " sono: \n";

     for (i = numero;  i <= limite;  i += numero)
        {
           cout << i << "\t";

           // Stampa PER_LINEA valori per riga
           cont++;
           if (cont % PER_LINEA == 0)   cout << endl;
         }
     
     cout << endl;            
     
     system("PAUSE");
     return EXIT_SUCCESS;
}
