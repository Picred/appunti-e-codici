#include "graph_list.h"

int main(){
    cout << "----------ORIENTED GRAPH----------" << endl;
    GraphList<int> oriented_graph;

    oriented_graph.addVertex(10);
    oriented_graph.addVertex(11);
    oriented_graph.addVertex(12);
    oriented_graph.addVertex(13);

    //aggiungo archi
    oriented_graph.addEdge(10,11); //10->11 12->13 13->11 
    oriented_graph.addEdge(12,13);
    oriented_graph.addEdge(13,11);

    cout << oriented_graph;


    cout << "----------NOT ORIENTED GRAPH----------"<< endl;
    GraphList<int> not_oriented_graph(false);

    not_oriented_graph.addVertex(21);
    not_oriented_graph.addVertex(24);
    not_oriented_graph.addVertex(26);
    not_oriented_graph.addVertex(87);
    not_oriented_graph.addVertex(1);
    not_oriented_graph.addVertex(37);

    not_oriented_graph.addEdge(21,37);
    not_oriented_graph.addEdge(21,26);
    not_oriented_graph.addEdge(87,26);
    not_oriented_graph.addEdge(1,37);
    not_oriented_graph.addEdge(24,37);

    cout << not_oriented_graph;

}