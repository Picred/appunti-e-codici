#ifndef GRAPH_LIST_H
#define GRAPH_LIST_H

#include <iostream>
#include "list.h"
using namespace std;

//estendo la classe list in modo da avere il vertice nella head e la lista di adiacenza nei successori(next)
template<typename T>
class GraphVertex : public List<T>{
    public:
        GraphVertex(T key) : List<T>(){
            List<T>::insertTail(key); //in questo modo ho già il nodo in testa inserito
        }

        friend ostream& operator<<(ostream& out, GraphVertex<T>& v){
            out << "Graph Vertex with key " << v.getHead()->getVal() << ": ";
            out << "\tAdjecency List: ";
            Node<T>* ptr = v.getHead();
            while (ptr){
                out << " ->" << ptr->getVal();
                ptr=ptr->getNext();
            }
            return out;
        }
};

template <typename T>
class GraphList{
    List< GraphVertex<T> > vertices;
    int nVertices=0; //contatore dei vertici
    bool isOriented;
    public:
        GraphList(bool isOriented=true):isOriented(isOriented){}

        void addVertex(T key){
            GraphVertex<T> toAdd(key);
            vertices.insertTail(toAdd);
            nVertices++;
        }

        void addEdge(T key1, T key2){
            Node< GraphVertex<T> > *node1 = this->search(key1);
            Node< GraphVertex<T> > *node2 = this->search(key2);

            if(node1 && node2){ // node1 e node2 non sono nullptr, quindi sono stati trovati
                //vuol dire che devo aggiungere node1 alla lista di adiacenza di node2
                //vuol dire che devo aggiungere node2 alla lista di adiacenza di node1
                node1->getVal().insertTail(key2); //prendo la lista di node1 e aggiungo node2 con un insertTail
                if(!this->isOriented){
                    node2->getVal().insertTail(key1);
                }
            }
        }
        
        Node< GraphVertex<T> >* search(T key){
            if(nVertices==0){
                return NULL;
            }

            // GraphVertex<T>* ptr=vertices.getHead(); //è giusta la riga 46? cioè 48 in questo caso, no. Diventa
            Node< GraphVertex<T> >* ptr=vertices.getHead();
            while(ptr){
                if(key==ptr->getVal().getHead()->getVal()){ //la chiave è == alla head della lista del nodo?
                    return ptr;
                }
                ptr=ptr->getNext();
            }

            return NULL; //ptr è andato a null. Non ho trovato il valore cercato
        }

        friend ostream& operator<<(ostream& out,GraphList<T>& g){
            out << g.vertices ;
            return out;
        }
};

#endif