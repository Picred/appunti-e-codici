// Coded by Picred (https://github.com/Picred)

#include <iostream>
#include <fstream>
#include <string>
#include <climits>

//da rivedere perchè stampa output sbagliato. (con 3 input funziona ma con 100 no)

using namespace std;

class Edge{
    private:
        int start, end, w; // w=weight
    public:
        Edge(int start, int end, int w){
            this->start = start;
            this->end = end;
            this->w = w;
        }

    int getStart(){
        return start;
    }

    int getEnd(){
        return end;
    }

    int getWeight(){
        return w;
    }
};

template<class T>
class Graph{
    private:
        T* nodes;
        int nNodes, maxNodes;

        Edge** edges;
        int nEdges, maxEdges;

    int search_node_index(T node){
        for(int i = 0; i<nNodes; i++){
            if (nodes[i] == node){
                return i;
            }
        }
        return -1;
    }

    public:
        Graph(int maxN, int maxE){
            this->maxNodes = maxN;
            this->maxEdges= maxE;
            nodes = new T[maxNodes];
            edges = new Edge*[maxEdges];
            nNodes = 0;
            nEdges = 0;
        }

        void addNode(T key){
            nodes[nNodes] = key;
            nNodes++;
        }

        void addEdge(T key1, T key2, int w){
            int u = this->search_node_index(key1);
            int v = this->search_node_index(key2);
            edges[nEdges++] = new Edge(u, v, w);
        }

        void bellman_ford(T s, T d, ofstream& out){
            int source = search_node_index(s);
            int dest = search_node_index(d);

            int* dist = new int[nNodes];
            for(int i=0; i<nNodes; i++)
                dist[i] = INT_MAX;
            dist[source] = 0;

            for(int i=1; i<nNodes; i++){
                for(int j=0; j<nEdges; j++){    
                    int start = edges[j]->getStart();
                    int end = edges[j]->getEnd();
                    int weight = edges[j]->getWeight();

                    if(dist[start] != INT_MAX && dist[start] + weight < dist[end])
                        dist[end] = dist[start] + weight;
                }
            }

            for(int j = 1; j < nEdges; j++){
                int start = edges[j]->getStart();
                int end = edges[j]->getEnd();
                int weight = edges[j]->getWeight();

                if(dist[start] != INT_MAX && dist[start] + weight < dist[end]){
                    out << "undef." << endl;
                    return;
                }
            }
            
            if (dist[dest] == INT_MAX)
                out << "inf.";
            else
                out << dist[dest];

            out << endl;
        }
};


template<class T> void solve(ifstream& in, ofstream& out, int nodes, int edges){
    Graph<T> g = Graph<T>(nodes, edges);

    for(int i=0; i<nodes; i++){
        T node;
        in >> node;
        g.addNode(node);
    }

    for(int i=0; i < edges; i++){
        char tmp;
        T u,v;
        int p;
        in >> tmp >> u >> tmp >> v >> tmp >> p >> tmp;
        g.addEdge(u, v, p);
    }

    T source, dest;
    in >> source >> dest;
    g.bellman_ford(source, dest, out);
}


int main(int argc, char const *argv[]){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int nodes, edges;
    string type; // (int double)

    for(int i=0; i<100; i++){
        in >> nodes >> edges >> type;
        if(type == "double")
            solve<double>(in, out, nodes, edges);

        if(type == "int")
            solve<int>(in, out, nodes, edges);
    }
}