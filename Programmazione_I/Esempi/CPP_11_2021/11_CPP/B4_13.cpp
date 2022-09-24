#include <iostream>

using namespace std;


int main()
{ 
      int tabella [5][10];
      int r,c;

      // Inizializza la tabella con dei valori
      for (r=0; r < 5; r++)
         for (c=0; c < 10; c++)
            tabella[r][c] = r * 10 + c;

      // Visualizza la tabella
      for (r=0; r < 5; r++)
      {
         for (c=0; c < 10; c++)
            cout << tabella[r][c] << "\t";
         cout << endl;
      }
     cout << endl;            
     
     system("PAUSE");
     return EXIT_SUCCESS;
}
