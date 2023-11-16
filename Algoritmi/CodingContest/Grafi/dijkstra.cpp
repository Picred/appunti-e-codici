#include <fstream>
#include <iostream>
#include <limits.h>

using namespace std;

class Edge {
    private:
        int start;
        int end;
        int weight;

    public:
        Edge(int start, int end, int weight) {
            this->start = start;
            this->end = end;
            this->weight = weight;
        }
        int getS() { return start;}
        int getE() { return end;}
        int getW() { return weight;}
};

template <class T> class Graph {
private:
    T *nodes;
    int totalnode;
    int nsize;

    Edge **edges;
    int totaledge;
    int esize;

    int find_node_index(T x) {
        for (int i = 0; i < nsize; i++)
            if (nodes[i] == x)
                return i;
        return -1;
    }

public:
    Graph(int totalnode, int totaledge) {
        this->totalnode = totalnode;
        this->totaledge = totaledge;
        edges = new Edge *[this->totaledge];
        nodes = new T[this->totalnode];
        esize = nsize = 0;
    }

    void addNode(T x) { 
        nodes[nsize++] = x; 
    }

    void addEdge(T x, T y, int p) {
        int posx = find_node_index(x);
        int posy = find_node_index(y);

        edges[esize++] = new Edge(posx, posy, p);
    }

    void dijkstra(T s, T f, ofstream &out) {
        int source = find_node_index(s);
        int dest = find_node_index(f);

        int *dist = new int[nsize];

        for (int i = 0; i < nsize; i++)
            dist[i] = INT_MAX;

        dist[source] = 0;
        // array nodi visitati
        bool *visit = new bool[nsize]{0};

        for (int i = 0; i < nsize; i++) {
            // find min
            int min = INT_MAX;
            int posmin = 0;

            for (int m = 0; m < nsize; m++) {
                if (visit[m] == 0 && dist[m] < min) {
                    min = dist[m];
                    posmin = m;
                }
            }
            visit[posmin] = 1;

            for (int j = 0; j < esize; j++) {
                int s = edges[j]->getS();
                int e = edges[j]->getE();
                int w = edges[j]->getW();

                if (s == posmin && dist[s] + w < dist[e])
                    dist[e] = dist[s] + w;
            }
        }

        if (dist[dest] == INT_MAX)
            out << "inf." << endl;
        else
            out << dist[dest] << endl;
    }
};

template <class T> void solve(ifstream &in, ofstream &out, int n, int e) {
    Graph<T> graph = Graph<T>(n, e);

    for (int j = 0; j < n; j++) {
        T val;
        in >> val;
        graph.addNode(val);
    }

    for (int j = 0; j < e; j++) {
        char tmp;
        T x, y;
        int p;
        in >> tmp >> x >> y >> p >> tmp;
        graph.addEdge(x, y, p);
    }

    T start, dest;
    in >> start >> dest;

    graph.dijkstra(start, dest, out);
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    for (int i = 0; i < 100; i++){
        int n, e;
        string type;
        in >> n >> e >> type;

    if (type == "int")
        solve<int>(in, out, n, e);

    if (type == "double")
        solve<double>(in, out, n, e);
    }
}