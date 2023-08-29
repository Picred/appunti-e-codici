#include <fstream>
#include <iostream>
using namespace std;

template <class H> class Heap {
private:
  H *heap;
  int size;
  int heapsize;
  int fycalls;

  int parent(int i) { return i / 2; }

  int right(int i) { return (i * 2) + 1; }

  int left(int i) { return i * 2; }

  void heapify(int i) {
    if (heapsize >= 1)
      fycalls++;

    int r = right(i);
    int l = left(i);
    int m = i;

    // Min heap
    if (l <= heapsize && heap[l] < heap[m])
      m = l;

    if (r <= heapsize && heap[r] < heap[m])
      m = r;

    if (m != i) {
      swap(heap[m], heap[i]);
      heapify(m);
    }
  }

  void extract() {
    swap(heap[1], heap[heapsize--]);
    heapify(1);
  }

public:
  Heap(H *_heap, int _size) {
    heap = _heap;
    size = _size;
    heapsize = _size;
    fycalls = 0;
  }

  void build() {
    for (int i = size / 2; i >= 1; i--) {
      heapify(i);
    }
  }

  void heapsort() {
    for (int i = 1; i <= size; i++)
      extract();
  }

  void fprint(ofstream &out) {
    out << fycalls << " ";

    for (int i = 1; i <= size; i++)
      out << heap[i] << " ";

    out << endl;
  }
};

template <class H> void solve(ifstream &in, ofstream &out, int n) {
  H *data = new H[n + 1];

  for (int i = 1; i <= n; i++)
    in >> data[i];

  Heap<H> heap = Heap<H>(data, n);
  heap.build();
  heap.heapsort();
  heap.fprint(out);
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  for (int i = 0; i < 100; i++) {
    string type;
    int n;

    in >> type >> n;

    if (type == "int")
      solve<int>(in, out, n);

    else if (type == "double")
      solve<double>(in, out, n);

    else if (type == "char")
      solve<char>(in, out, n);

    else if (type == "bool")
      solve<bool>(in, out, n);
  }
}