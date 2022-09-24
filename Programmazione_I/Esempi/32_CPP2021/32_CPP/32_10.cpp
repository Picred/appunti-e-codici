#include <iostream>

using namespace std;

/* 
  INSERTION SORT 
*/


// InsertionSort
void insertionSort (int array[], int length)
  {
    for (int index = 1; index < length; index++)
       {
         int key = array[index]; // elemento da inserire
         int position = index; // posizione corrente elemento da inserire

	for(int k = 0; k<length; k++)
	  cout << (k==0 ? "[" : "") << array[k] << (k==index-1 ? "] " : " "); 
	cout << endl ; 
   
         // shifta i valori più grandi di key a destra
         while (position > 0 && array[position-1] > key)
            {
              array[position] = array[position-1]; 
              position--;
            }
         
         array[position] = key;
       }
  }



int main()
{ 
   int numeri[] = { 8, 4, 6, 1, 2, 7, 5, 3 };

   insertionSort (numeri, 8);

  cout << "RESULT: " << endl;    
   for (int i=0; i < 8; i++)
        cout << numeri[i] << " ";
   cout << endl;

   return 0; 
} // End main()
