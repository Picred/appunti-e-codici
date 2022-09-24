#include <iostream>
#include <cstdlib>

using namespace std;

class Data
  {
    public: 
       int   x; 
	     float y;
  };


int main()
  {
    // memberwise initialization
    const Data d1 = {63, 1.76};
    Data d2 = {61, 1.72};
    Data dataVec[4] = { {10, 0.98},
			   {65, 0.56},
			   {23, 0.98},
			   {37, 0.123}
			 };
    Data dataVec1[4]; 

    Data d = {12}; // equivalente a Data d{12, 0.0}; 
    cout << d.y << endl; 

    Data dempty = {}; //equivalente a Data dempty;

    //notare i valori degli indirizzi di memoria
    cout << &d1 << "\n " << &d1.x<< "\n " << &d1.y << endl; 

    return EXIT_SUCCESS;
}
