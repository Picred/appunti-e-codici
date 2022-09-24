#include <iostream>

using namespace std;

template <class T, class C>
//oppure: template <class T> 
// 1. Vanno passati due 
// argomenti di egual tipo, altrimenti errore di compilazione 
// (argument deduction)
void Scambia (T & a, C & b) // passaggio by reference
  {
    T aux;

    aux = a;
    a = b;
    b = aux;
  }

//DUE tipi generici 
template <class T, typename C>
void foo(T c, C a){ 
// 2. se scrivo: 
// MA il tipo C non e' presente tra i parametri formali, allora
// errore di argument deduction
  cout << a << "," <<  c << endl;
}

//DUE tipi generici 
template <class T, typename C>
//prototipo ok 
void foo1(T c, C a){ 
  cout << a << "," <<  c << endl;
}

int main ()
  {
    int   i = 6,    j = 9;
    float x = 1.6,  y = 3.3;
    char  a = 'a',  b = 'b';

    cout << "Prima : " << i << "  " << j << "\n";
    Scambia (i, j);
    cout << "Dopo  : " << i << "  " << j << "\n\n";

    cout << "Prima : " << x << "  " << y << "\n";
    Scambia (x, y);
    cout << "Dopo  : " << x << "  " << y << "\n\n";

    cout << "Prima : " << a << "  " << b << "\n";
    Scambia (a, b);
    cout << "Dopo  : " << a << "  " << b << "\n\n";

    /* 1. Errore a compile-time (argument deduction)  con la seg. chiamata*/
    //cout << "Prima : " << i << "  " << x << "\n";
    Scambia (i, x);   // Errore di compilazione (vedi sopra)
    //cout << "Dopo  : " << i << "  " << x << "\n\n";

    // 2. Errore a compile-time (vedi sopra)
    foo(i, j);

    return 0;
  }
