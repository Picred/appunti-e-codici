#include "graph_list.h"

int main(){
    
    GraphList<int> oriented_graph;


    oriented_graph.add_vertex(10);
    oriented_graph.add_vertex(11);
    oriented_graph.add_vertex(12);
    oriented_graph.add_vertex(13);
    
    // aggiungo archi
    cout << "----------ORIENTED GRAPH----------" << endl;
    oriented_graph.add_edge(10,11); //10->11 12->13 13->11
    oriented_graph.add_edge(12,13);
    oriented_graph.add_edge(13,11);
    

    cout << oriented_graph;


    cout << "----------NOT ORIENTED GRAPH----------"<< endl;
    GraphList<int> not_oriented_graph(false);

    not_oriented_graph.add_vertex(21);
    not_oriented_graph.add_vertex(24);
    not_oriented_graph.add_vertex(26);
    not_oriented_graph.add_vertex(87);
    not_oriented_graph.add_vertex(37);

    not_oriented_graph.add_edge(21,37);
    not_oriented_graph.add_edge(21,26);
    not_oriented_graph.add_edge(87,26);
    not_oriented_graph.add_edge(24,37);

    cout << not_oriented_graph;

}