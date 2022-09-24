#include <iostream>

using namespace std;

/* 
   Questo programma usa una funzione che 
   implementa il SelectionSort.
*/



 // scambia due elementi di un array
static void swap ( int a[], int primo, int secondo )
   {
      int tmp;
      
      tmp = a[primo];         
      a[primo] = a[secondo];  
      a[secondo] = tmp;
   }
   
   
// SelectionSort
void selectionSort (int array[], int length)
  {
    int min;

    for (int index = 0; index < length-1; index++)
      {
	//ricerca del minimo
        min = index;
        for (int i = index+1; i < length; i++)
            if (array[i] < array[min])  
	       min = i;

	//OUTPUT 
	for(int j=0; j<length; j++)
	  cout << ((j==index || j==min )? "[" : "") << array[j] << (j==index || j==min ? "] " : " ");
	cout << endl;  

	//scambia minimo ed elemento di indice index
        swap(array, min, index);
      }
   }


int main()
{ 
   int numeri[] = { 8, 4, 6, 1, 2, 7, 5, 3 };

   selectionSort (numeri, 8);
   
   for (int i=0; i < 8; i++)
        cout << numeri[i] << "\t";
   cout << endl;

   return 0;
} // End main()
