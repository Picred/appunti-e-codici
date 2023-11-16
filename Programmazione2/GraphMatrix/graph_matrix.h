#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

#include <iostream>

using namespace std;

template <typename T>
class Vertex {
    private:
        T key;
        template <typename U>
        friend class GraphMatrix;

    public:
        Vertex(T key) : key(key){}
        Vertex() : Vertex(NULL){}

        friend ostream& operator<< (ostream& os, Vertex<T>& v){
            os << "Vertex with key " << v.key;
            return os;
        }

        void setKey(T key){
            this->key=key;
        }

};

template <typename T>
class GraphMatrix{
    private:
        Vertex<T>** vertices;
        bool** adj;
        int n_vertices=0;
        int max_size=0;
    public:
        GraphMatrix(int max) : max_size(max){
            vertices = new Vertex<T>*[max_size];

            adj = new bool*[max_size];

            for(int i=0; i<max_size; i++){
                adj[i] = new bool[max_size] {};
            }
        }

        void add_vertex(T key){
            if(this->n_vertices == this->max_size){
                cerr << "Graph is full!" <<endl;
                return;
            }

            vertices[n_vertices++]= new Vertex<T>(key);
        }

        int search(T key){
            if(this->n_vertices==0){
                cerr << "Empty graph, no search!" << endl;
                return -1;
            }

            for(int i=0; i<this->n_vertices; i++){
                if(vertices[i]->key == key){
                    return i;
                }
            }

            return -1;
        }

        void add_edge(T key1, T key2){
            int i=this->search(key1);
            int j=this->search(key2);

            if(i!=-1 && j!=-1){
                adj[i][j]=true;
                adj[j][i]=true;
            }

            if(i == -1)
                cerr << "Vertex with key " << key1 << " not found" << endl;
            if(j==-1)
                cerr << "Vertex with key " << key2 << " not found" << endl;
            
        }

        friend ostream& operator<<(ostream& os, GraphMatrix<T>& g){
            os << "--------Vertices--------" << endl;
            for(int i=0; i < g.n_vertices; i++)
                os << "v[" << i << "] = " << *g.vertices[i] << "\t";
            
            os << endl << "-----Adjacency Matrix--------" << endl;

            for(int i=0; i<g.n_vertices; i++){
                for(int j=0; j<g.n_vertices; j++){
                    os << g.adj[i][j] << "  ";
                }
                os << endl;
            }
            return os;
        }
};

#endif
