#include "graph_matrix.h"

int main(){
    GraphMatrix<int> g(10);

    g.add_vertex(1);
    g.add_vertex(2);
    g.add_vertex(3);

    g.add_edge(1,3);

    cout << g;
}