#include <iostream>
#include "serbatoio.h"

using namespace std;

int main()
{
   Serbatoio a(10,7);
   Serbatoio b(20);
 
   cout << a << endl << b;

    b.deposita(a.svuotaTutto());
	  
    cout << "Dopo il riversamento ..." << endl;
	  
    cout << a << endl << b;
    
    return 0;
} // end main()
