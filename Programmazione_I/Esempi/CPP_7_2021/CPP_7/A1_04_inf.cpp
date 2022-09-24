#include <iostream>
#include <iomanip>

#include <cmath> //Infinity, NAN, pow, sqrt, log, 

using namespace std;

int main()
{   
   double unoZero = 0.0; 
   double unValoreNonNullo = 1.0; 
   double unValoreStrano = NAN; //valore "Not A Number"
   
   cout << "Un double che vale zero : " << unoZero << endl;
   cout << "Un double che vale uno : " << unValoreNonNullo << endl;                       
   cout << "\nUn double che non vale un numero : " 
        << unValoreStrano;  
        // -1.#IND -> Indeterminato
          
	//IEEE 754 
	//1/0 = Inf
   cout << "\nSe divido uno per zero ho : " 
        << unValoreNonNullo/unoZero << endl;
             
	//-1/0 = -Inf     
   cout << "\nSe divido meno uno per zero ho : " 
        << (-unValoreNonNullo)/unoZero << endl;
          
	//0/0 = NAN
    cout << "\nSe divido zero per zero ho : " 
       << unoZero/unoZero << endl;

	//-Inf/Inf=NAN
	   cout << "\nSe divido -Inf per -INf: " 
       << -INFINITY/-INFINITY << endl;

      
	//0^0=1, 1^+Inf=1, 5^(-Inf)=0, 0^(-Inf)=Inf
   cout << "\nSe innalzo zero a zero ho : " 
        << pow(unoZero,unoZero) << " !!!  " << endl
        << "ed anche 1 a piu' infinito : "
        << pow(1.0, 1.6E308*1.6E308) << " !!!" << endl
        << "invece 5 elevato a meno infinito : "
        << pow(5, - 1.6E308*1.6E308) << " !!!" << endl
        << "infine 0 elevato a meno infinito : "
        << pow(0, - 1.6E308*1.6E308) << " !!!" << endl;

   cout << "\nIl valore infinito negativo : " << endl
		<< -INFINITY << " ... " 
        << -1.0/0.0  << " ... "  
        << log(0)    << " ... " 
        << endl << endl;

   cout << "\nIl valore \"Not A Number\" :  "
        << sqrt(-1) << endl; 
  
	//x/-Inf = -0
   cout << "Ancora un passaggio al limite : "
        << unValoreNonNullo/-INFINITY << endl << endl;
  
   float z=3.4E38;
   float w=3.4E38;
   float x=z*w;
   // int v=5/0;
   cout << "E per i float ? " << x << endl; 

	int a=1000000000;
	int b=1000000000; 
	//Per gli interi, avremo overflow!
	cout << "1 billion x 1 billion: " << a*b << endl;

    return 0;
} // end main()
