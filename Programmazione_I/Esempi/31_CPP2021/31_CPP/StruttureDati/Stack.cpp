#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class ADT
  {
    protected :
      bool modify;   

    public :
      ADT (bool m = true) : modify(m)   {  }
  };


// Per semplicita' le derivazioni seguenti sono di tipo
// "public" ma dovrebbero essere ragionate ...


class Counter : public virtual ADT
  {
    private :
      int value;

    public :
      Counter (int v=0, int m=0) :  value(v), ADT(m)   {  }

      int  Get () const   { return value; }
      void Inc ()         { if (modify) value ++; }
      void Dec ()         { if (modify) value --; }
  };




template <class T> class Stack;

template <class T>
ostream &  operator << (ostream & sx, const Stack<T> & dx);

// le due dichiarazioni forward sono necessarie per evitare un problema al linker



template <class T>
class Stack : public virtual  ADT
  {
    protected :
      T * ptr;
      int top;
      int maxsize;

    public :
      Stack  (int=3, bool=true);
      Stack  (Stack &);
      ~Stack ();

      void Push  (const T);
      T    Pop   ();
      int  Empty () const;

      friend ostream & operator << <>(ostream &, const Stack &);
      // const Stack &  operator = (const Stack &);
  };



template <class T> class STACK;

template <class T>
ostream &  operator << (ostream & sx, const STACK<T> & dx);

// le due dichiarazioni forward sono necessarie per evitare un problema al linker



template <class T>
class STACK : public Counter, public Stack<T>
  {
    public :
      STACK  (int = 2);
      ~STACK ();

      void Push   (const T);
      T    Pop    ();
      int  Length () const;

      STACK operator+ (STACK &);
      friend ostream & operator << <> (ostream &, const STACK &);
  };


// ************************ Stack ***************************


template <class T>
Stack<T>::Stack (int dim, bool modify) :
       maxsize(dim), top(-1), ADT(modify)
  {
    ptr = new T [maxsize];
  }

template <class T>
Stack<T>::Stack (Stack<T> & s) :
	 maxsize(s.maxsize), top(s.top),  ADT(s.modify)
  {
    ptr = new T [maxsize];
    for (int i=0; i<=top; i++)   ptr[i] = s.ptr[i];
  }

template <class T>
Stack<T>::~Stack ()
  {
    delete  [] ptr;
  }

template <class T>
void Stack<T>::Push (const T data)
  {
    if (! modify || top>=maxsize-1) return;
    ptr[++top] = data;
  }

template <class T>
T Stack<T>::Pop ()
  {
    if (! modify || Empty()) return 0;
    return ptr[top--];
  }

template <class T>
int Stack<T>::Empty () const
  {
    return (top == -1);
  }

template <class T>
ostream & operator << (ostream & left, const Stack<T> & s)
  {
    char buffer[200] = "Stack = { ",   buf[10];

    for (int i=0; i<=s.top; i++)
       {
	sprintf (buf, "%d, ", s.ptr[i]);
	strcat (buffer, buf);
       }
    return  left << buffer << " }\n";
  }


// ************************ STACK ***************************


template <class T>
STACK<T>::STACK (int size) :
	  Stack<T>(size,1), Counter()
  {  }

template <class T>
STACK<T>::~STACK ()
  {  }

template <class T>
void STACK<T>::Push (const T data)
  { 
    if ( Stack<T>::maxsize == Get() )
       {
       	 T * aux = new T [2*Stack<T>::maxsize];
	     for (int i=0; i<=Stack<T>::top; i++)   aux[i] = Stack<T>::ptr[i];
	     Stack<T>::~Stack();
	     Stack<T>::ptr = aux;
	     Stack<T>::maxsize *= 2;
       }
    Stack<T>::Push (data);
    Inc ();
  }

template <class T>
T STACK<T>::Pop ()
  {
    if (Get () < 1) return 0;
    Dec ();
    return Stack<T>::Pop ();
  }

template <class T>
int STACK<T>::Length () const
  {
    return  Get ();
  }

template <class T>
STACK<T> STACK<T>::operator+ (STACK<T> & s)
  {
    STACK<T> tmp(Stack<T>::maxsize+s.maxsize);
    int i;

    for (i=0; i <= (Stack<T>::top < s.top ? Stack<T>::top : s.top); i++)
       {
       	 tmp.ptr[2*i]   = Stack<T>::ptr[i];     
         tmp.Inc();
	     tmp.ptr[2*i+1] = s.ptr[i];   
         tmp.Inc();
       }

    int j = 2*i;
    if (Stack<T>::top < s.top)
       for (; i<=s.top; i++)
	     {
	       tmp.ptr[j++] = s.ptr[i];   tmp.Inc();
	     }
    else
       for (; i<=Stack<T>::top; i++)
	     {
	       tmp.ptr[j++] = Stack<T>::ptr[i];   tmp.Inc();
	     }
    tmp.top = j-1;
    return tmp;
  }

template <class T>
ostream & operator << (ostream & left, const STACK<T> & s)
  {
    char buffer[200] = "Stack = { ",   buf[10];

    for (int i=0; i<=s.top; i++)
       {
	     sprintf (buf, "%d, ", s.ptr[i]);
	     strcat (buffer, buf);
       }
    return  left << buffer << " }\n";
  }


// ************************* main ***************************


int main ()
  {
     Stack<int> a(3);

     a.Push(2);
     a.Push(3);
     a.Push(4);
     a.Push(5);

     Stack<int> b = a;

     cout << a;   a.Pop();   a.Pop();   cout << a << '\n';
     cout << b;   b.Pop();   b.Pop();   cout << b;

     STACK<int> c, d;

     c.Push(19); /*  c.Push(29);   c.Push(39);
     d.Push(17);   d.Push(27);
     cout << "Prima :\n" << c << d;

     STACK<int> somma;
     somma = d+c+d;
     cout << somma;
     d.Pop();   d.Pop();    d.Pop();
     
     cout  << "Dopo :\n" << c << d << somma;
     */
  }


//*****************************************************************
//*****************************************************************

