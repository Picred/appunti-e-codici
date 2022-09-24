#include <iostream>

using namespace std;

template <class T> class LinkedQueue;


template <class T>
class Node
  {
    private :

      T data;
      Node<T> * link;

    public :

      friend class LinkedQueue<T>; // per accesso ai dati
  };


template <class T>
class LinkedQueue
  {
    private :

      Node<T> * front;
      Node<T> * rear;

    public :
      LinkedQueue  ()  { front = rear = 0; }
      ~LinkedQueue ();

      int IsEmpty () const    { return (! front); }

      T First () const;
      T Last  () const;

      LinkedQueue<T> & Enqueue  (const T & x);
      LinkedQueue<T> & Dequeue  (T & x);
  };


template <class T>
LinkedQueue<T>::~LinkedQueue ()
  {
    Node<T> * next;

    while (front)
       {
    	 next = front -> link;
	     delete front;
	     front = next;
       }
  }


template <class T>
T LinkedQueue<T>::First () const
  {
    if (IsEmpty ())
       {
         cout << "La coda Š vuota !!!\n";
	     return 0;
       }

    return front -> data;
  }


template <class T>
T LinkedQueue<T>::Last () const
  {
    if (IsEmpty ())
       {
	     cout << "La coda è vuota !!!\n";
         return 0;
       }

    return rear -> data;
  }


template <class T>
LinkedQueue<T> &  LinkedQueue<T>::Enqueue (const T & x)
  {
    Node<T> * ptr = new Node<T>;

    ptr -> data = x;
    ptr -> link = 0;

    if (front)             // Coda non vuota
       rear -> link = ptr;
    else                   // Coda vuota
       front = ptr;

    rear = ptr;

    return  *this;
  }


template <class T>
LinkedQueue<T> &  LinkedQueue<T>::Dequeue (T & x)
  {
    if (IsEmpty ())
       {
       	 cout << "La coda Š vuota !!!\n";
	     return *this;
       }

    x = front -> data;

    Node<T> * ptr = front;
    front = front -> link;
    delete ptr;

    return  *this;
  }



int main ()
  {
    LinkedQueue<int> Interi;

    Interi.Enqueue (1);
    Interi.Enqueue (2);
    Interi.Enqueue (3);        
    Interi.Enqueue (4);
    cout << Interi.Last() << "  " << Interi.First() << "\n\n";

    int i;
    Interi.Dequeue (i);   cout << i << '\n';
    Interi.Dequeue (i);   cout << i << '\t';
    cout << "\n\n";

    return 0;
  }
