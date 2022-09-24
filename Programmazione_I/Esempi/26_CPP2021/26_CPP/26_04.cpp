#include <iostream>
#include <time.h>
#include <stdlib.h>
 
using namespace std;
 
#include <cstdarg> // Per usare l'ellipsi

// The ellipses must be the LAST PARAMETER
int sum(int nCount, ...) // the ellipsis is represented by three dots in a row: "..."
{
    long lSum = 0;
 
    //1. WE ACCESS THE ELLIPSES THROUGH A VA_LIST, SO LET'S DECLARE ONE
    //va_list e' un tipo accessibile in <cstdarg>
    va_list list;
 
    //2. WE INITIALIZE THE VA_LIST USING VA_START
    // secondo argomento, nome dell'ultimo argomento prima dell'ellipsi
    va_start(list, nCount); 
 
    //3. Loop nCount times
    for (int nArg=0; nArg < nCount; nArg++)
         // We use va_arg to get parameters out of our ellipses
         // The first parameter is the va_list we're using
         // THE SECOND PARAMETER IS THE TYPE OF THE PARAMETER
         lSum += va_arg(list, int);
 
    //4. Cleanup the va_list when we're done.
    va_end(list);
    return lSum; 
}
 
int main()
{
    cout << sum(5, 1, 2, 3, 4, 5) << endl;
    cout << sum(6, 1, 2, 3, 4, 5, 6) << endl;
    cout << sum(3, 1, 2, 3, 4, 5, 6) << endl;  //prendera' solo i primi 3 argomenti!!
   return 0;
} 
