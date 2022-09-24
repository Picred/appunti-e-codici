
#include <iostream>

using namespace std;

//
// I PARAMETRI DEI TEMPLATE POSSONO AVERE ARGOMENTI 
// COSTANTI (ANCHE NEL TIPO)
//


//argomento standard per T e DIM
template <class T = double, int DIM = 10>
class Stack
  {
    private :

      int top;            // Punta alla prima locazione libera
      T   dati [DIM];     // Contiene i dati

    public :

      Stack () : top(0)  { }
      ~Stack ()  { cout << "Distrutto DIM = " << DIM << endl; }
      void Push (T);
      T Pop ();
  };


template <class T, int DIM>
void Stack<T, DIM>::Push (T dato)
  {
    if (top < DIM)    dati [top++] = dato;
  }


template <class T, int DIM>
T Stack<T, DIM>::Pop ()
  {
    if (!top)  return 0;

    return  dati [--top];
  }



int main ()
  {
    Stack <> st;    
    Stack <float> Reali;
    Stack <char, 99> Caratteri;

    Reali.Push (1.1);
    Reali.Push (2.2);
    Reali.Push (3.3);

    cout << Reali.Pop () << '\t';
    cout << Reali.Pop () << '\t';
    cout << Reali.Pop () << '\t';
    cout << Reali.Pop () << '\n';
    
    //system("PAUSE");    // ns. comodo!
    return 0;
  }


//*****************************************************************
//*****************************************************************
