#include "array_ptr.h"

//*************************************************************
// Definition of function showArray.                          *
// This function displays the contents of array. size is the  *
// number of elements.                                        *
//*************************************************************


void showArray(int array[], int size) // <--> void showArray(int *arr, int size)
{
   for (int count = 0; count < size; count++)
      cout << array[count] << " ";
   cout << endl;
}

//**************************************************************
// Definition of function showArrPtr.                          *
// This function displays the contents of the array pointed to *
// by array. size is the number of elements.                   *
//**************************************************************

void showArrPtr(int *array[], int size)
{
   for (int count = 0; count < size; count++)
      cout << *(array[count]) << " ";
   cout << endl;
}


//****************************************************************
// Definition of function arrSelectSort.                         *
// This function performs an ascending order selection sort on   *
// array, which is an array of pointers. Each element of array   *
// points to an element of a second array. After the sort,       *
// array will point to the elements of the second array in       *
// ascending order.                                              *
//****************************************************************
void arrSelectSort(int *array[], int size)
{
   int startScan, minIndex;
   int *minElem;

   for (startScan = 0; startScan < (size - 1); startScan++)
   {
      minIndex = startScan;
      minElem = array[startScan];
      cout<<"OUTER LOOP: minElem: "<<minElem<<" *minElem: "<<*minElem<<endl;

      for(int index = startScan + 1; index < size; index++)
      {
         cout<<"  (array["<<index<<"]): "<<(array[index])<<" *minElem: "<<*minElem<<endl;

         if (*(array[index]) < *minElem)
         {
            minElem = array[index];
            minIndex = index;
            cout<<"NEW minElem= "<<*minElem<<endl;
         }
      }
      array[minIndex] = array[startScan];
      array[startScan] = minElem;

      cout<<"After loop on startScan="<<startScan<<endl;
      for (int k=0;k<size;k++) cout<<array[k]<<" "; cout<<endl;
      for (int k=0;k<size;k++) cout<<*array[k]<<" ";cout<<endl;
   }
}
