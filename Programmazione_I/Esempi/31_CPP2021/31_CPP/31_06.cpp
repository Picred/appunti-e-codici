
#include <iostream>

using namespace std;

//
// I PARAMETRI DEI TEMPLATE POSSONO ESSERE DI UNO DEI TIPI
// DI DATI FONDAMENTALI E I CORRISPONDENTI ARGOMENTI DEVONO
// ESSERE ESPRESSIONI COSTANTI.
//

// Per l'uso del template, "typename" è equivalente a "class"

template <typename T, int DIM>
class Stack
  {
    private :

      int top;            // Punta alla prima locazione libera
      T   dati [DIM];     // Contiene i dati

    public :

      Stack () : top(0)  { }
      ~Stack ()  { };
      void Push (T);
      T Pop ();
  };


template <typename T, int DIM>
void Stack<T, DIM>::Push (T dato)
  {
    if (top < DIM)    dati [top++] = dato;
  }


template <typename T, int DIM>
T Stack<T, DIM>::Pop ()
  {
    if (!top)  return 0;

    return  dati [--top];
  }



int main ()
  {
    //parametro template e' costante (10)
    Stack <float, 10> Reali;

    Reali.Push (1.1);
    Reali.Push (2.2);
    Reali.Push (3.3);

    cout << Reali.Pop () << '\t';
    cout << Reali.Pop () << '\t';
    cout << Reali.Pop () << '\t';
    cout << Reali.Pop () << '\n';
    
  //  system("PAUSE");    // ns. comodo!
    return 0;
  }

//*****************************************************************
//*****************************************************************
