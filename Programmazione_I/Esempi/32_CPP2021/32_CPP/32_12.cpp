#include <iostream>

using namespace std;

/* 
   Questo programma implementa una versione
   ricorsiva del SelectionSort.
*/


// scambia due elementi di un array
void swap ( int a[], int primo, int secondo )
   {
      int tmp;
      
      tmp = a[primo];         
      a[primo] = a[secondo];  
      a[secondo] = tmp;
   }
   
   
// trova l'indice dell'elemento minimo nella
// porzione di array delimitata da left e right
int trovaIndiceDelMinimo (int array[], int left, int right)
   {
      int min = left;
      
      for (int i = left+1;  i<=right;  i++)
         if (array[i] < array[min])   min = i;
      
      return min;
   }


// SelectionSort ricorsivo
void selectionSortRicorsivo 
                     (int array[], int left, int right)
   {
      cout << "selectionSortricorsivo(left=" << left << ", right=" << right << ")" << endl; 
      if (left >= right)   return;
      
      int min = trovaIndiceDelMinimo (array, left, right);
      swap (array, left, min);
      selectionSortRicorsivo (array, left+1, right);  
   }


// Evitiamo i parametri superflui
void selectionSort (int array[], int length)
   {
      selectionSortRicorsivo (array, 0, length-1);  
   }
   

int main()
{ 
   int numeri[] = { 8, 4, 6, 1, 2, 7, 5, 3 };

   selectionSort( numeri, 8 );
      
   for (int i=0; i < 8; i++)
        cout << numeri[i] << "\t";
   cout << endl;

   return EXIT_SUCCESS;
} // End main()
