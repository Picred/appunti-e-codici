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

  int getS() { return start; }

  int getE() { return end; }

  int getW() { return weight; }
};

template <class H> class Graph {
private:
  int totalnode;

  Edge **edges;
  int esize;
  int totaledge;

public:
  Graph(int totalnode, int totaledge) {
    this->totalnode = totalnode;
    this->totaledge = totaledge;

    edges = new Edge *[this->totaledge];
    esize = 0;
  }

  ~Graph() {}

  void addEdge(H x, H y, int p) { edges[esize++] = new Edge(x, y, p); }

  void bellmanFordP(H s, H f, int k, ofstream &out) {
    int source = s;
    int dest = f;

    int *dist = new int[totalnode];

    for (int i = 0; i < totalnode; i++)
      dist[i] = INT_MAX;

    dist[source] = 0;

    for (int i = 0; i < k; i++) {
      for (int j = 0; j < esize; j++) {
        int s = edges[j]->getS();
        int e = edges[j]->getE();
        int w = edges[j]->getW();

        if (dist[s] != INT_MAX && dist[s] + w < dist[e])
          dist[e] = dist[s] + w;
      }
    }

    if (dist[dest] == INT_MAX)
      out << "inf." << endl;
    else
      out << dist[dest] << endl;
  }
};

template <class H>
void solve(ifstream &in, ofstream &out, int n, int e, int k) {
  Graph<H> graph = Graph<H>(n, e);

  for (int j = 0; j < e; j++) {
    char tmp;
    H x, y;
    int p;
    in >> tmp >> x >> y >> p >> tmp;
    graph.addEdge(x, y, p);
  }

  H start, dest;
  in >> start >> dest;

  graph.bellmanFordP(start, dest, k, out);
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  for (int i = 0; i < 100; i++) {
    int n, e, k;
    in >> n >> e >> k;
    solve<int>(in, out, n, e, k);
  }
}