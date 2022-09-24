#include <iostream>
#include <sstream>

using namespace std;

int main()
{

    //STRINGSTREAM USATA COME STANDARD INPUT: DATI >> VARIABILI    
    string s1 = "12345"; // integer
    string s2 = "345.678";// floating point number 
  
    // object from the class stringstream 
    stringstream ss1(s1); 
    stringstream ss2(s2); 
  
    //Possiamo convertire la stringa contenuta in ss1 in 
    //un intero
    int x = 0;
    ss1 >> x;

    //now convert the string s2 into a floating point number 
    float y = 0; 
    ss2 >> y; 
  
    cout << "Value of x : " << x << "\n"; 
    cout << "Value of y : " << y << "\n"; 

    ss1.str("a");
    ss2.str(""); // reset the content to an empty string 

    cout << "Value of ss1 after clearing the content : " << ss1.str() << endl;
    cout << "Value of ss1 after clearing the content : " << ss2.str() << endl;

    //B stringstream usata per raccogliere dati (numeri) e stringhe 

    x=10;
    y=12.34;
    double z = 30.5;

    ss1.clear(); // Si provi a commentare questa riga di codice..
    ss1 << "Il numero x e'" << x << ", poi y=" << y << ", e z=" << z;

    cout << ss1.str() << endl;
  
    return 0;
} 
