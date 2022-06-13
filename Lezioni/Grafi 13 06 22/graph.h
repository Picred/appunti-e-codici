#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

template <typename T>
class Vertex{
    private:
        T key;
        template <typename U>
        friend class Graph;
    
    public:
        Vertex(T key) : key(key){}
        Vertex():Vertex(NULL){}

        bool operator==(Vertex<T>& v){
            return this->key==v.key;
        }

        friend ostream& operator<< (ostream& out, Vertex<T>& v){
            out << v.key;
            return out;
        }
};

template <typename T>
class Graph{
    private:
        Vertex<T>** vertices; //vedi riga 38. Ho creato 
        bool** adj;
        int maxSize=0;
        int nVertices=0;
    public:
        Graph(int max_size) :maxSize(max_size){
            vertices=new Vertex<T>*[max_size]; //aggiungo * per avere un array di puntatori a vertici per evitare ambiguità con la new a riga 54 
            adj=new bool*[max_size];
            for(int i=0; i<max_size;i++){
                adj[i]=new bool[max_size] {0} ; //inizializzo tutto a false
                // for(int j=0; j<max_size; j++){
                    // adj[i][j]=false;
                // }
            }
        }

        void addVertex(T key){
            if(this->nVertices==this->maxSize){
                cerr << "Graph is full" << endl;
                return;
            }

            vertices[nVertices++]=new Vertex<T>(key);
        }

        void addEdge(T key1, T key2){
            int i=this->search(key1);
            int j=this->search(key2);

            if(i!=-1 && j!=-1){
                adj[i][j]=true;
                adj[j][i]=true;
            }
            else{
                if(i==-1)
                    cerr << "There is no vertex with key " << key1 << endl;
                else
                    cerr << "There is no vertex with key " << key2 << endl;
            }            
        }
        
        // Vertex<T>& search(T key){  //errata, modificata sotto
        //     if(this->nVertices==0)
        //         return NULL;
        //     for(int i=0; i<this->nVertices;i++){
        //         if(vertices[i].key==key){
        //             return vertices[i];
        //         }
        //     }
        //     return NULL;
        // }

        int search(T key){ //devo restituire un indice per accedere al vettore  
            if(this->nVertices==0)
                return -1;
            for(int i=0; i<this->nVertices;i++){
                if(vertices[i]->key==key){
                    return i;
                }
            }
            return -1;
        }

        friend ostream& operator<<(ostream& out, Graph<T>& g){
            for(int i=0; i<g.nVertices;i++){
                out << "v[" <<i<<"] = " << *(g.vertices[i])<<"\t";
            }

            out << endl;

            for(int i=0; i<g.nVertices;i++){
                for(int j=0;j<g.nVertices;j++){
                    if(g.adj[i][j]){
                        out << "(" << i << ", " << j << ")" << endl;
                    }
                }
            }

            return out;
        }
};
#endif