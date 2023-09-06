#include <fstream>
#include <iostream>

using namespace std;

template <class H> class Coppia {
private:
  H x;
  H y;

public:
  Coppia(H x, H y) {
    this->x = x;
    this->y = y;
  }

  friend bool operator>(Coppia &c1, Coppia &c2) {
    return ((c1.x > c2.x) || (c1.x == c2.x && c1.y > c2.y)) ? 1 : 0;
  }

  friend ostream &operator<<(ostream &os, Coppia &c) {
    return os << "(" << c.x << " " << c.y << ")";
  }
};

template <class H> class Heap {
private:
  Coppia<H> **heap;
  int heapsize;
  int size;
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

    if (l <= heapsize && *heap[l] > *heap[m])
      m = l;

    if (r <= heapsize && *heap[r] > *heap[m])
      m = r;

    if (m != i) {
      swap(heap[m], heap[i]);
      heapify(m);
    }
  }

  void extract() {
    swap(heap[1], heap[heapsize]);
    heapsize--;
    heapify(1);
  }

public:
  Heap(Coppia<H> **heap, int size) {
    this->heap = heap;
    this->size = size;
    this->heapsize = size;
    fycalls = 0;
  }

  void build() {
    for (int i = heapsize / 2; i >= 1; i--)
      heapify(i);
  }

  void heapsort() {
    for (int i = 1; i <= size; i++)
      extract();
  }

  void fprint(ostream &out) {
    out << fycalls << " ";

    for (int i = 1; i <= size; i++)
      out << *heap[i] << " ";

    out << endl;
  }
};

template <class H> void solve(ifstream &in, ofstream &out, int n) {
  Coppia<H> **v = new Coppia<H> *[n + 1];

  for (int i = 1; i <= n; i++) {
    char tmp;
    H x, y;

    in >> tmp >> x >> y >> tmp;
    v[i] = new Coppia<H>(x, y);
  }

  Heap<H> heap = Heap<H>(v, n);
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

    if (type == "int" || type == "bool")
      solve<int>(in, out, n);

    else if (type == "double")
      solve<double>(in, out, n);

    else if (type == "char")
      solve<char>(in, out, n);
  }
}