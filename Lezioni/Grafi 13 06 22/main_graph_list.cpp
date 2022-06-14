#include "graph_list.h"

int main(){
    GraphList<int> g;

    g.addVertex(10);
    g.addVertex(11);
    g.addVertex(12);
    g.addVertex(13);

    //aggiungo archi
    g.addEdge(10,11);
    g.addEdge(12,13);
    g.addEdge(13,11);

    cout << g;
}