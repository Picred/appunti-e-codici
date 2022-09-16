#include "graph.h"

int main(){
    Graph<int> g(10);

    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);

    g.addEdge(0,1);
    g.addEdge(2,1);

    cout << g;

}