#include <iostream>

using namespace std;

class Base{
	protected:
		int n;
};

class Derivata1: protected Base{
	public:
		// Base::n; //modifico la visibilità di n in questa classe
};

class Derivata2 : protected Base{
	public:
        Base::n;
};

int main(){
	Derivata1 d1;
	Derivata2 d2;
    cout << d1.n << endl; //errore
	d2.n = 0; //corretto perchè ho la riga 17
}