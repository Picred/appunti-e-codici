/*Codificare un programma in linguaggio C++ che calcoli e
stampi l’ipotenusa di un triangolo rettangolo.
L’utente dovr`a inserire i due cateti a e b da tastiera. Il
programma dovr`a controllare che i valori inseriti siano positivi.
.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main () {

	float cateto1, cateto2, ipotenusa, somma;
	
	cout << "Inserisci il valore del primo cateto: " << endl;
	cin >> cateto1;
	
	
	cout << "Inserisci il valore del secondo cateto: " << endl;
	cin >> cateto2;
			
			if (cateto1>0 && cateto2>0) {
			
			
			cateto1=cateto1*cateto1;
			cateto2=cateto2*cateto2;
			somma=cateto1+cateto2;
			ipotenusa= sqrt(somma);
			
	cout << "Il valore dell'ipotenusa e': " << ipotenusa;
			} 
			else {
				
				cout << "Inserisci solo valori positivi, ritenta.";
			}			


}