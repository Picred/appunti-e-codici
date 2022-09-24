#include <iostream>

using namespace std;

class Data
  {
    private :

      char buffer [80];

    public :

      Data ()                     { }
      Data (const char * str)     { strcpy (buffer, str); }

      const char * Get () const   { return buffer; }

  }; // End class Data


class Node
  {
    private :

      Data * ptr;
      Node * next;

    public :

      Node (Data d)
	   {
	     ptr = new Data (d.Get());
	     next = NULL;
	   }

      ~Node()  { delete ptr; }

      const Data * GetData () const     { return ptr; }
      Node *       GetNext () const     { return next; }
      void         SetNext (Node * x)   { next = x; }

  }; //End class Node


class List
  {
    private :

      Node * front;
      Node * rear;
      int NodesNumber;

    public :

      List () : front(NULL), rear(NULL), NodesNumber(0)  { }
      ~List ();

      void operator += (Data);
      const char * operator [ ] (int) const;

      void Show () const;

  }; //End class List


List::~List ()
  {
    Node * p,   *q = front;

    while ( (p = q) != NULL)
       {
  	     q = p -> GetNext();
	     delete p;
       }
  }


void List::operator += (Data d)
  {
    Node * aux = new Node (d);

    NodesNumber++;
    if (front == NULL)
       {
	     front = rear = aux;
       }
    else
       {
	     rear -> SetNext (aux);
	     rear = rear->GetNext();
       }
  }


const char * List::operator [ ] (int index) const
  {
    if (NodesNumber <= index)
       {
	     cout << "Non ci sono cosi' tanti elementi.\n";
	     return NULL;
       }
    
    Node * p = front;  
    while ( index > 1) 
       {
         p = p->GetNext();
         index--;
       }

    return p -> GetData() -> Get();
  }


void List::Show () const
  {
    Node * p = front;

    cout << "< ";
    while ( p != NULL)
       {
	     cout << p -> GetData() -> Get() << ", ";
	     p = p -> GetNext();
       }
    cout << "\b\b >";

  }



int main ()
  {
    const int Dim = 5;
    char * elements [Dim] = { 
         "Primo", "Secondo", "Terzo", "Quarto", "Quinto" };
    List lista;

    for (int i = 0; i<Dim; i++)
	  lista += Data(elements[i]);

    cout << "Il secondo elemento in lista e' : " << lista[2] << endl;

    cout << "LISTA : ";
    lista.Show ();
    cout << endl;
    
    //system("PAUSE");    // ns. comodo!
    return 0;
  }


//*****************************************************************
//*****************************************************************

