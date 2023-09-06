#include <fstream>
#include <iostream>

using namespace std;

template <class H> class Heap {

private:
  H *heap;
  int size;
  int maxsize;

  int parent(int i) { return i / 2; }

  void swap(int x, int y) {
    H tmp = heap[x];
    heap[x] = heap[y];
    heap[y] = tmp;
  }

public:
  Heap(int _size) {
    heap = new H[_size];
    maxsize = _size;
    size = 0;
  }

  ~Heap() { delete[] heap; }

  void enqueue(H key) {
    // Max size
    if (size == maxsize)
      return;

    // Inserimento
    heap[++size] = key;

    // Controllo
    int i = size;

    while (i > 1 && heap[parent(i)] > heap[i]) {
      swap(i, parent(i));
      i = parent(i);
    }
  }

  void fprint(ofstream &out) {
    for (int i = 1; i <= size; i++)
      out << heap[i] << "\t";
    out << "\n";
  }
};

template <class H> void solve(ifstream &in, ofstream &out, int size) {
  Heap<H> heap = Heap<H>(size + 1);

  for (int i = 1; i <= size; i++) {
    H key;
    in >> key;
    heap.enqueue(key);
  }

  heap.fprint(out);
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  for (int i = 0; i < 100; i++) {
    string type;
    int size;

    in >> type >> size;

    if (type == "int")
      solve<int>(in, out, size);

    else if (type == "double")
      solve<double>(in, out, size);

    else if (type == "bool")
      solve<bool>(in, out, size);

    else if (type == "char")
      solve<char>(in, out, size);
  }
}