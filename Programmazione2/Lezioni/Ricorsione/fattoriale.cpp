#include <iostream>

using namespace std;

// funzione ricorsiva fattoriale

int fattoriale(int n) {
	if(n==0)
		return 1;
	return n*fattoriale(n-1);
}

int main(){
	
	int fatt2=fattoriale(2);
	int fatt3=fattoriale(3);
	int fatt10=fattoriale(10);
	
	cout << "il fattoriale di 2 e':" << fatt2 << endl;
	cout << "il fattoriale di 3 e':" << fatt3 << endl;
	cout << "il fattoriale di 10 e':" << fatt10 << endl;

	return 0;
}