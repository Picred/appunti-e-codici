#include <iostream>

using namespace std;


int main()
{ 
    int indice = 0;  // variabile indice 
         
    cout << "Esperimento 1\n"
         << "-------------\n";      
    cout << "dove indice parte da 1, e la condizione è (indice <= 5)\n";
    // quante volte viene eseguito il ciclo?
      
    for (indice = 1; indice <= 5 ; indice++) 
       { 
         cout << "indice = " << indice << endl;
       } 
       
       
    cout << "\nEsperimento 2\n"
         << "-------------\n";      
    cout << "dove indice parte da 1, e la condizione è (indice < 5)\n";
    // quante volte viene eseguito il ciclo?
    for (indice = 1; indice < 5 ; indice++) 
       { 
         cout << "indice = " << indice << endl;
       } 
       
       
    cout << "\nEsperimento 3\n"
         << "-------------\n";      
    cout << "dove indice parte da 0, e la condizione è (indice <= 5)\n";
    // quante volte viene eseguito il ciclo?
   
    for (indice = 0; indice <= 5 ; indice++)
       { 
         cout << "indice = " << indice << endl;
       } 
       
       
    cout << "\nEsperimento 4\n"
         << "-------------\n";      
    cout << "dove indice parte da 0, la condizione è (indice < 5)\n";
    // quante volte viene eseguito il ciclo?
      
    for (indice = 0; indice < 5 ; indice++) 
       { 
         cout << "indice = " << indice << endl;
       } 
   system("PAUSE");
   return EXIT_SUCCESS;
}
