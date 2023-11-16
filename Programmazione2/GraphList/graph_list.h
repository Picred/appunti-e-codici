#ifndef GRAPH_LIST_H
#define GRAPH_LIST_H

#include "list.h"
#include <iostream>

using namespace std;

template <class T>
class GraphVertex : public List<T>{
    public:
        GraphVertex(T key) : List<T>(){
            List<T>::insertTail(key);
        }

        friend ostream& operator<<(ostream& os, GraphVertex<T>& v){
            os << "Graph Vertex with key=" << v.getHead()->getVal();
            os << "\tAdjacency list: ";
            
            Node<T>* ptr = v.getHead();

            while(ptr){
                os << ptr->getVal() << "->";
                ptr=ptr->getNext();
            }

            return os;
        }
};


template <class T>
class GraphList{
    private:
        List< GraphVertex<T>> vertices;
        int n_vertices=0;
        bool is_oriented;
    public:
        GraphList(bool oriented=true) : is_oriented(oriented){}

        void add_vertex(T key){
            GraphVertex<T> to_add=key;
            vertices.insertTail(to_add);
            n_vertices++;
        }

        Node< GraphVertex<T> >* search(T key){
            if(n_vertices==0){
                return NULL;
            }

            Node< GraphVertex<T> >* ptr = vertices.getHead();

            while(ptr){
                if(key==ptr->getVal().getHead()->getVal()){
                    return ptr;
                }
                ptr=ptr->getNext();
            }
            return NULL;
        }

        void add_edge(T key1, T key2){
            Node< GraphVertex<T> >* node1=this->search(key1);
            Node< GraphVertex<T> >* node2=this->search(key2);

            if(node1!=nullptr && node2!=nullptr){
                node1->getVal().insertTail(key2);
                if(!this->is_oriented){
                    node2->getVal().insertTail(key1);
                }
            }
        }


        friend ostream& operator<< (ostream& os, GraphList<T>& g){ 
            os << g.vertices;
            return os;
        }
};

#endif
