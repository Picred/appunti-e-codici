#include <iostream>

using namespace std;

/* 
  BUBBLESORT  ``ottimizzato. 
  Evita di visitare la parte destra 
  dello array, gia' ordinata. 
*/



 // scambia due elementi di un array
static void swap ( int a[], int primo, int secondo )
   {
      int tmp;
      
      tmp = a[primo];         
      a[primo] = a[secondo];  
      a[secondo] = tmp;
   }
   
   
// BubbleSort
static void bubbleSort ( int array[], int length )
  {   
      int swapped = 1; 
      int step = 1; 
      while (swapped){
	swapped = 0; 
	//Ottimizzazione. Dopo il passo i-esimo, 
	// A[n-i-1...n-1] e' gia ordinato. Quindi: 
         for (int i = 0; i < length-1-step+1; i++)   {
	    cout << step << ": ";  
	    for(int k=0; k<length; k++)
	      cout << (k==i ? "[" : "") << + array[k] << (k==i+1 ? "] " : " ");
	    cout << endl; 
            if ( array[i] > array[i+1] ){
               swap( array, i, i+1 );	 
	      swapped = 1;
	    }
	  }
	  step++; 
	}
   }

int main()
{ 
   int numeri[] = { 8, 4, 6, 1, 2, 7, 5, 3 };
   //int numeri[] = { 8, 7, 6, 5, 4, 3, 2, 1 }; // WORST CASE

   bubbleSort(numeri, 8);

    cout << "RESULT: " << endl;       
   for (int i=0; i < 8; i++)
        cout << numeri[i] << " ";
   cout << endl;

    return 0; 
} // End main()
