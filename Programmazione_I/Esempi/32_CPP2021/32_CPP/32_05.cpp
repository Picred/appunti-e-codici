#include <iostream>

using namespace std;

/* 
   Questo programma esegue la ricerca del 
   massimo elemento in un array
*/




int main()
{ 
   int  A[100]; 
   int  i = 0;  // indice dell'array
   int  max;    // conterrà il massimo

   srand(time(0));  
   while (i<100) 
      {
        A[i] = rand()%1000 + 1;
        i++;     
      }
             
   i = 1;
   max = A[0];  
   while (i<100)
      {
        if (max < A[i])   max = A[i];
        i++; 
      }
   cout << "Il massimo e'" << max << endl;
        
   return EXIT_SUCCESS;
} // End main()
