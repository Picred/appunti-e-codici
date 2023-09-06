// build-max-heap

#include <fstream>
#include <iostream>
using namespace std;

template <class T> class MaxHeap {
private:
  T *array;
  int length;
  int heapSize;

  int left(int i) { return 2 * i; }
  int right(int i) { return (2 * i) + 1; }
  int parent(int i) { return i / 2; }

  int max(int i, int j) {
    if (array[i] >= array[j])
      return i;
    else
      return j;
  }
  void heapify(int i) {
    while (i <= heapSize) {
      if (left(i) <= heapSize) {
        int maxim;
        if (right(i) <= heapSize) {

          maxim = max(max(left(i), right(i)), i);

          swap(array[i], array[maxim]);
          if (i != maxim)
            i = maxim;
          else
            break;

        } else {
          maxim = max(left(i), i);

          swap(array[i], array[maxim]);
          if (i != maxim)
            i = maxim;
          else
            break;
        }

      } else
        break;
      ;
    }
  }

  void buildHeap() {
    for (int i = heapSize / 2; i > 0; i--) {
      heapify(i);
    }
  }

public:
  MaxHeap(T *_array, int n) {
    length = n;
    heapSize = n;
    array = new T[length + 1];
    for (int i = 0; i < length; i++)
      array[i + 1] = _array[i];
    buildHeap();
  }
  void print(ofstream &out) {
    for (int i = 1; i <= heapSize; i++) {
      out << array[i] << " ";
    }
    out << endl;
  }
};

template <class T> void computa(T *array, int n, ifstream &in, ofstream &out) {
  for (int i = 0; i < n; i++) {
    in >> array[i];
  }

  MaxHeap<T> heap(array, n);
  heap.print(out);
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");
  string type;
  int n;
  for (int i = 0; i < 100; i++) {
    in >> type >> n;
    if (type == "bool")
      computa(new bool[n], n, in, out);
    else if (type == "int")
      computa(new int[n], n, in, out);
    else if (type == "double")
      computa(new double[n], n, in, out);
    else
      computa(new char[n], n, in, out);
  }
  return 0;
}

// build-min-heap

#include <fstream>
#include <iostream>

using namespace std;

int **create_matrix(int n, int m) {
  int **v = new int *[n];

  for (int i = 0; i < n; i++)
    v[i] = new int[m]{0};

  return v;
}

void delete_matrix(int **v, int n, int m) {
  for (int i = 0; i < n; i++)
    delete[] v[i];

  delete[] v;
}

string lcs(string x, int n, string y, int m) {
  int **v = create_matrix(n + 1, m + 1);

  // LCS
  for (int i = 1; i < n + 1; i++)
    for (int j = 1; j < m + 1; j++)
      x[i - 1] == y[j - 1]
          ? v[i][j] = v[i - 1][j - 1] + 1            // Prev diagonal value + 1
          : v[i][j] = max(v[i - 1][j], v[i][j - 1]); // Max between left or top

  int maxseq = v[n][m];

  // Print LCS
  string slcs;

  int i = n;
  int j = m;

  while (i > 0 && j > 0) {
    if (x[i - 1] == y[j - 1]) { // Equal char: copy and move in diagonal
      slcs = x[i - 1] + slcs;
      i--;
      j--;
    }

    else if (v[i - 1][j] > v[i][j - 1]) // up > right move up
      i--;

    else // right > up move right
      j--;
  }

  // Free
  delete_matrix(v, n, m);
  return slcs;
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  for (int i = 0; i < 100; i++) {
    int m, n;
    string x, y;
    in >> m >> n >> x >> y;
    out << lcs(x, m, y, n) << endl;
  }
}

// min-enqueue

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

// greedy-knapsack

#include <fstream>
#include <iostream>
using namespace std;

namespace sort {

void swap(int *v, int x, int y) {
  int tmp = v[x];
  v[x] = v[y];
  v[y] = tmp;
}

void insertionSort(int *v, int n) {
  for (int i = 1; i < n; i++) {
    int index = i;

    while (index >= 1 && v[index] > v[index - 1]) { // Desc order
      swap(v, index, index - 1);
      index--;
    }
  }
}
} // namespace sort

void knapsack(ofstream &out, int *v, int n, int p) {
  sort::insertionSort(v, n);
  int max = 0;

  for (int i = 0; i < p; i++)
    max += v[i];

  out << max << endl;
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  for (int i = 0; i < 100; i++) {
    int n, p;
    in >> n >> p;

    int *v = new int[n];

    for (int j = 0; j < n; j++)
      in >> v[j];

    knapsack(out, v, n, p);
    delete[] v;
  }
}

// hash-chain-div

#include <fstream>
#include <iostream>
using namespace std;

template <class T> class Node {
private:
  Node *next;
  T key;

public:
  Node(T key, Node<T> *next) {
    this->next = next;
    this->key = key;
  }

  Node<T> *getNext() { return next; }
  void setNext(Node<T> *next) { this->next = next; }

  T getKey() { return key; }
  void setKey(T key) { this->key = key; }
};

template <class T> class LinkedList {
private:
  Node<T> *head;
  Node<T> *tail;

  int size;

public:
  LinkedList() {
    head = new Node<T>(0, NULL);
    tail = new Node<T>(0, NULL);
    head->setNext(tail);
    size = 0;
  }

  // Inserimento in testa O(1)
  void insert(T key) {
    Node<T> *tmp = new Node<T>(key, head->getNext());
    head->setNext(tmp);
    size++;
  }

  int getSize() { return size; }
};

template <class T> class HashTable {
protected:
  LinkedList<T> **bucket;
  int size;

public:
  HashTable(int size) {
    bucket = new LinkedList<T> *[size];

    for (int i = 0; i < size; i++)
      bucket[i] = new LinkedList<T>();

    this->size = size;
  }

  void printBucketSize(ofstream &out) {
    for (int i = 0; i < size; i++)
      out << bucket[i]->getSize() << " ";

    out << endl;
  }

  virtual void insert(T key) = 0;
};

template <class T> class HashDiv : public HashTable<T> {
public:
  HashDiv(int size) : HashTable<T>(size) {}

  void insert(T key) {
    int pos = (int)key % this->size;
    this->bucket[pos]->insert(key);
  }
};

template <class T> void solve(ifstream &in, ofstream &out, int bucket, int n) {
  HashDiv<T> table = HashDiv<T>(bucket);
  T key;

  for (int i = 0; i < n; i++) {
    in >> key;
    table.insert(key);
  }

  table.printBucketSize(out);
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  for (int i = 0; i < 100; i++) {
    string type;
    int bucket, n;

    in >> type >> bucket >> n;

    if (type == "int")
      solve<int>(in, out, bucket, n);

    else if (type == "bool")
      solve<bool>(in, out, bucket, n);

    else if (type == "double")
      solve<double>(in, out, bucket, n);

    else if (type == "char")
      solve<char>(in, out, bucket, n);
  }
}

// hash-chain-mult

#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;

template <class T> class Node {
private:
  Node *next;
  T key;

public:
  Node(T key, Node<T> *next) {
    this->next = next;
    this->key = key;
  }

  Node<T> *getNext() { return next; }
  void setNext(Node<T> *next) { this->next = next; }

  T getKey() { return key; }
  void setKey(T key) { this->key = key; }
};

template <class T> class LinkedList {
private:
  Node<T> *head;
  Node<T> *tail;

  int size;

public:
  LinkedList() {
    head = new Node<T>(0, NULL);
    tail = new Node<T>(0, NULL);
    head->setNext(tail);
    size = 0;
  }

  // Inserimento in testa O(1)
  void insert(T key) {
    Node<T> *tmp = new Node<T>(key, head->getNext());
    head->setNext(tmp);
    size++;
  }

  int getSize() { return size; }
};

template <class T> class HashTable {
protected:
  LinkedList<T> **bucket;
  int size;

public:
  HashTable(int size) {
    bucket = new LinkedList<T> *[size];

    for (int i = 0; i < size; i++)
      bucket[i] = new LinkedList<T>();

    this->size = size;
  }

  void printBucketSize(ofstream &out) {
    for (int i = 0; i < size; i++)
      out << bucket[i]->getSize() << " ";

    out << endl;
  }

  virtual void insert(T key) = 0;
};

template <class T> class HashMult : public HashTable<T> {
private:
  const float A = 0.61803;

public:
  HashMult(int size) : HashTable<T>(size) {}

  void insert(T key) {
    int pos = this->size * fmod(key * A, 1);
    this->bucket[pos]->insert(key);
  }
};

template <class T> void solve(ifstream &in, ofstream &out, int bucket, int n) {
  HashMult<T> table = HashMult<T>(bucket);
  T key;

  for (int i = 0; i < n; i++) {
    in >> key;
    table.insert(key);
  }

  table.printBucketSize(out);
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  for (int i = 0; i < 100; i++) {
    string type;
    int bucket, n;

    in >> type >> bucket >> n;

    if (type == "int")
      solve<int>(in, out, bucket, n);

    else if (type == "bool")
      solve<bool>(in, out, bucket, n);

    else if (type == "double")
      solve<double>(in, out, bucket, n);

    else if (type == "char")
      solve<char>(in, out, bucket, n);
  }
}

// max-heap

#include <fstream>
#include <iostream>
#include <sstream>
#include <typeinfo>
using namespace std;

template <class H> class Heap {

private:
  H *heap;
  int size;
  int heapsize;
  int heapifycalls;

  int parent(int i) { return i / 2; }

  int right(int i) { return (i * 2) + 1; }

  int left(int i) { return i * 2; }

  void heapify(int i) {
    if (heapsize >= 1)
      heapifycalls++;

    int r = right(i);
    int l = left(i);
    int max = i;

    if (l <= heapsize && heap[l] > heap[max])
      max = l;

    if (r <= heapsize && heap[r] > heap[max])
      max = r;

    if (i != max) {
      swap(heap[max], heap[i]);
      heapify(max);
    }
  }

public:
  Heap(int _size) {
    heapifycalls = 0;
    size = _size;
    heapsize = 0;
    heap = new H[size];
  }

  ~Heap() { delete[] heap; }

  Heap *enqueue(H x) {
    if (heapsize == size)
      return NULL;

    // Inserimento
    heap[++heapsize] = x;

    // Controllo
    int i = heapsize;

    while (i > 1 && heap[i] > heap[parent(i)]) {
      swap(heap[i], heap[parent(i)]);
      i = parent(i);
    }

    return this;
  }

  Heap *extract() {
    heap[1] = heap[heapsize--];
    heapify(1);
  }

  void fprint(ofstream &out) {
    out << heapifycalls << " ";

    for (int i = 1; i <= heapsize; i++)
      out << heap[i] << " ";

    out << endl;
  }
};

template <class H> void solve(ifstream &in, ofstream &out, int n) {
  Heap<H> heap = Heap<H>(n + 1);

  for (int i = 0; i < n; i++) {
    string tmp;
    in >> tmp;

    if (tmp == "extract")
      heap.extract();
    else {

      stringstream s(tmp.substr(2));
      H key;
      s >> key;
      heap.enqueue(key);
    }
    tmp = "";
  }

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

    else if (type == "bool")
      solve<bool>(in, out, n);

    else if (type == "char")
      solve<char>(in, out, n);
  }
}

// min-heap

#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

template <class H> class Heap {

private:
  H *heap;
  int size;
  int heapsize;
  int heapifycalls;

  int parent(int i) { return i / 2; }

  int right(int i) { return (i * 2) + 1; }

  int left(int i) { return i * 2; }

  void heapify(int i) {
    if (heapsize >= 1)
      heapifycalls++;

    int r = right(i);
    int l = left(i);
    int max = i;

    if (l <= heapsize && heap[l] < heap[max])
      max = l;

    if (r <= heapsize && heap[r] < heap[max])
      max = r;

    if (i != max) {
      swap(heap[max], heap[i]);
      heapify(max);
    }
  }

public:
  Heap(int _size) {
    heapifycalls = 0;
    size = _size;
    heapsize = 0;
    heap = new H[size];
  }

  ~Heap() { delete[] heap; }

  Heap *enqueue(H x) {
    if (heapsize == size)
      return NULL;

    // Inserimento
    heap[++heapsize] = x;

    // Controllo
    int i = heapsize;

    while (i > 1 && heap[i] < heap[parent(i)]) {
      swap(heap[i], heap[parent(i)]);
      i = parent(i);
    }

    return this;
  }

  Heap *extract() {
    heap[1] = heap[heapsize--];
    heapify(1);
  }

  void fprint(ofstream &out) {
    out << heapifycalls << " ";

    for (int i = 1; i <= heapsize; i++)
      out << heap[i] << " ";

    out << endl;
  }
};

template <class H> void solve(ifstream &in, ofstream &out, int n) {
  Heap<H> heap = Heap<H>(n + 1);

  for (int i = 0; i < n; i++) {
    string tmp;
    in >> tmp;

    if (tmp == "extract")
      heap.extract();
    else {
      stringstream s(tmp.substr(2));
      H key;
      s >> key;
      heap.enqueue(key);
    }
  }

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

    else if (type == "bool")
      solve<bool>(in, out, n);

    else if (type == "char")
      solve<char>(in, out, n);
  }
}

// heapify

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

    if (l <= heapsize && heap[l] > heap[m])
      m = l;

    if (r <= heapsize && heap[r] > heap[m])
      m = r;

    if (m != i) {
      swap(heap[m], heap[i]);
      heapify(m);
    }
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

  void extractall() {
    while (heapsize > 0) {
      swap(heap[1], heap[heapsize--]);
      heapify(1);
    }
  }

  void fprint(ofstream &out) { out << fycalls << endl; }
};

template <class H> void solve(ifstream &in, ofstream &out, int n) {
  H *data = new H[n + 1];

  for (int i = 1; i <= n; i++)
    in >> data[i];

  Heap<H> heap = Heap<H>(data, n);
  heap.build();
  heap.extractall();
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

// heapsort

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

    if (l <= heapsize && heap[l] > heap[m])
      m = l;

    if (r <= heapsize && heap[r] > heap[m])
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

// reverse-heapsort

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

// countingsort

#include <fstream>
#include <iostream>

using namespace std;

void countingSort(ostream &out, int *v, int n) {
  int min = v[0];
  int max = v[0];

  // Trovo il massimo e il minimo
  for (int i = 0; i < n; i++) {
    if (v[i] < min)
      min = v[i];

    else if (v[i] > max)
      max = v[i];
  }

  // Operazioni counting
  int range = (max - min) + 1;
  int *c = new int[range]{0};

  for (int i = 0; i < n; i++)
    c[v[i] - min]++;

  for (int i = 1; i < range; i++)
    c[i] += c[i - 1];

  // Sorting
  int *s = new int[n];

  for (int i = n - 1; i >= 0; i--)
    s[--c[v[i] - min]] = v[i];

  // Output
  for (int i = 0; i < range; i++)
    out << c[i] << " ";

  for (int i = 0; i < n; i++)
    out << s[i] << " ";

  out << endl;
}

void fprint(ostream &out) {}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  for (int i = 0; i < 100; i++) {
    int n;
    in >> n;
    int *array = new int[n];

    for (int i = 0; i < n; i++)
      in >> array[i];

    countingSort(out, array, n);
  }
}

// rotazioni-BST

#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

enum Rotations { RIGHT, LEFT };

template <class H> class Node {

private:
  H value;
  Node<H> *parent;
  Node<H> *right;
  Node<H> *left;

public:
  Node(H _value, Node<H> *_parent = NULL, Node<H> *_right = NULL,
       Node<H> *_left = NULL) {
    value = _value;
    parent = _parent;
    right = _right;
    left = _left;
  }

  H getKey() { return value; }
  void setKey(H _value) { value = _value; }

  Node<H> *getParent() { return parent; }
  void setParent(Node<H> *_parent) { parent = _parent; }

  Node<H> *getRight() { return right; }
  void setRight(Node<H> *_right) { right = _right; }

  Node<H> *getLeft() { return left; }
  void setLeft(Node<H> *_left) { left = _left; }
};

template <class H> class BSTree {

private:
  Node<H> *root;

  // Trova il minimo (si trova nel sottoalbero sinistro)
  Node<H> *minimum(Node<H> *node) {
    Node<H> *min = node;

    while (min->getLeft())
      min = min->getLeft();

    return min;
  }

  // Trova l'elemento piu' piccolo nel sottoalbero di destra
  Node<H> *successor(Node<H> *node) {

    // Caso 1: Il nodo ha il sottoalbero destra
    if (node->getRight() != NULL)
      return minimum(node->getRight());

    // Caso 2: Il nodo non ha il sottoalbero di destra (es: foglie)
    // In questo caso il successore va cercato nei vari parent
    Node<H> *parent = node->getParent();

    while (parent != NULL && node == parent->getRight()) {
      node = parent;
      parent = parent->getParent();
    }

    return parent;
  }

  // replace

  void rotation(Rotations way, Node<H> *node) {
    Node<H> *child = way == RIGHT ? node->getLeft() : node->getRight();
    Node<H> *parent = node->getParent();

    // Figlio non esiste: impossibile ruotare
    if (child == NULL)
      return;

    // Cambio il figlio del nodo da ruotare con il figlio del figlio
    // e assegno al figlio il suo padre
    way == RIGHT ? (node->setLeft(child->getRight()), child->setRight(node))
                 : (node->setRight(child->getLeft()), child->setLeft(node));

    // N.B: Il padre non esiste quando la rotazione viene effettuata sulla
    // radice
    parent != NULL ? (node == parent->getRight() ? parent->setRight(child)
                                                 : parent->setLeft(child))
                   : (void)(root = child);

    // Sistemiamo i padri
    child->setParent(parent);
    node->setParent(child);

    way == RIGHT ? (node->getLeft() != NULL ? node->getLeft()->setParent(node)
                                            : (void)NULL)
                 : (node->getRight() != NULL ? node->getRight()->setParent(node)
                                             : (void)NULL);
  }

  void inorder(Node<H> *node, ofstream &out) {
    if (node != NULL) {
      inorder(node->getLeft(), out);
      out << node->getKey() << " ";
      inorder(node->getRight(), out);
    }
  }

  void preorder(Node<H> *node, ofstream &out) {
    if (node != NULL) {
      out << node->getKey() << " ";
      preorder(node->getLeft(), out);
      preorder(node->getRight(), out);
    }
  }

  void postorder(Node<H> *node, ofstream &out) {
    if (node != NULL) {
      postorder(node->getLeft(), out);
      postorder(node->getRight(), out);
      out << node->getKey() << " ";
    }
  }

public:
  BSTree() { root = NULL; }

  BSTree *insert(H key) {
    Node<H> *node = new Node<H>(key);

    // Caso 1: la radice non esiste
    if (root == NULL) {
      root = node;
      return this;
    }

    // Caso 2: Scansione per trovare la nuova posizione del nodo
    Node<H> *next = root;
    Node<H> *prev = NULL;

    while (next != NULL) {
      prev = next;
      next = key > next->getKey() ? next->getRight() : next->getLeft();
    }

    // Inserimento del nodo
    node->setParent(prev);
    key > prev->getKey() ? prev->setRight(node) : prev->setLeft(node);
    return this;
  }

  Node<H> *search(H key) {
    Node<H> *node = root;

    while (node != NULL && key != node->getKey())
      node = key > node->getKey() ? node->getRight() : node->getLeft();

    return node;
  }

  BSTree *remove(H key) {
    Node<H> *node = search(key);
    Node<H> *parent = node->getParent();

    // Caso 1: Non ci sono figli
    if (node->getLeft() == NULL && node->getRight() == NULL) {
      parent != NULL ? (parent->getRight() == node ? parent->setRight(NULL)
                                                   : parent->setLeft(NULL))
                     : (void)(root = NULL);

      delete node;
    }

    // Caso 2: Ha un figlio
    else if (node->getRight() != NULL && node->getLeft() == NULL ||
             node->getRight() == NULL && node->getLeft() != NULL) {
      Node<H> *child =
          node->getRight() != NULL ? node->getRight() : node->getLeft();

      parent != NULL ? (parent->getRight() == node ? parent->setRight(child)
                                                   : parent->setLeft(child))
                     : (void)(root = child);

      child->setParent(parent);
    }

    // Caso 3: Entrambi i figli
    else if (node->getRight() != NULL && node->getLeft() != NULL) {
      H key = successor(node)->getKey();
      remove(key);
      node->setKey(key);
    }

    return this;
  }

  void rotate(Rotations way, H key) {
    Node<H> *node = search(key);
    rotation(way, node);
  }

  void orderby(ofstream &out, string type) {
    if (type == "inorder")
      inorder(root, out);

    else if (type == "preorder")
      preorder(root, out);

    else if (type == "postorder")
      postorder(root, out);

    out << endl;
  }
};

template <class H>
void solve(ifstream &in, ofstream &out, string visit, int operation) {
  BSTree<H> tree = BSTree<H>();

  for (int i = 0; i < operation; i++) {
    string todo;
    in >> todo;

    string name = todo.substr(0, todo.find(":"));
    stringstream s(todo.substr(todo.find(":") + 1, todo.length()));
    H value;
    s >> value;

    // cout << endl << "o: " << name << " v: " << value << endl;

    if (name == "ins")
      tree.insert(value);

    else if (name == "canc")
      tree.remove(value);

    else if (name == "left")
      tree.rotate(LEFT, value);

    else if (name == "right")
      tree.rotate(RIGHT, value);
    // tree.orderby(out, visit);
  }

  tree.orderby(out, visit);
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  for (int i = 0; i < 100; i++) {
    string type, visit;
    int n, r;

    in >> type >> n >> r >> visit;

    if (type == "int")
      solve<int>(in, out, visit, n + r);

    else if (type == "double")
      solve<double>(in, out, visit, n + r);
  }
}

// lcs

#include <fstream>
#include <iostream>

using namespace std;

int **create_matrix(int n, int m) {
  int **v = new int *[n];

  for (int i = 0; i < n; i++)
    v[i] = new int[m]{0};

  return v;
}

void delete_matrix(int **v, int n, int m) {
  for (int i = 0; i < n; i++)
    delete[] v[i];

  delete[] v;
}

int lcs(string x, int n, string y, int m) {
  int **v = create_matrix(n + 1, m + 1);

  // LCS
  for (int i = 1; i < n + 1; i++)
    for (int j = 1; j < m + 1; j++)
      x[i - 1] == y[j - 1]
          ? v[i][j] = v[i - 1][j - 1] + 1            // Prev diagonal value + 1
          : v[i][j] = max(v[i - 1][j], v[i][j - 1]); // Max between left or top

  // Free
  int length = v[n][m];
  delete_matrix(v, n, m);
  return length;
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  for (int i = 0; i < 100; i++) {
    int m, n;
    string x, y;
    in >> m >> n >> x >> y;
    out << lcs(x, m, y, n) << endl;
  }
}

// edit

#include <fstream>
#include <iostream>

using namespace std;

int **create_matrix(int n, int m) {
  int **v = new int *[n];

  for (int i = 0; i < n; i++)
    v[i] = new int[m]{0};

  return v;
}

void delete_matrix(int **v, int n, int m) {
  for (int i = 0; i < n; i++)
    delete[] v[i];

  delete[] v;
}

int edit(string x, int n, string y, int m) {
  int **v = create_matrix(n + 1, m + 1);

  // Righe
  for (int i = 0; i < n + 1; i++)
    v[i][0] = i;

  // Colonne
  for (int i = 0; i < m + 1; i++)
    v[0][i] = i;

  // EDIT
  for (int i = 1; i < n + 1; i++)
    for (int j = 1; j < m + 1; j++)
      x[i - 1] == y[j - 1]
          ? v[i][j] = v[i - 1][j - 1] // Prev diagonal value + 1
          : v[i][j] = min(min(v[i - 1][j], v[i][j - 1]), v[i - 1][j - 1]) +
                      1; // Min between left or top

  // Free
  int length = v[n][m];
  delete_matrix(v, n, m);
  return length;
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  for (int i = 0; i < 100; i++) {
    int m, n;
    string x, y;
    in >> m >> n >> x >> y;
    out << edit(x, m, y, n) << endl;
  }
}

// resto

#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>

using namespace std;

int min_coins_v2(int *v, int n, int r) {
  int *t = new int[r + 1]{0};

  for (int i = 1; i < r + 1; i++)
    t[i] = INT_MAX;

  for (int i = 1; i < r + 1; i++) {
    for (int j = 0; j < n; j++) {
      if (v[j] <= i) {
        // Selezione del sottoproblema
        int sub = t[i - v[j]];

        // Se la soluzione del sottoproblema esiste
        if (sub != INT_MAX)
          t[i] = min(sub + 1, t[i]);
      }
    }
  }

  return t[r];
}

// Con ordinamento
int min_coins(int *v, int n, int r) {
  int *t = new int[r + 1]{0};
  for (int i = 1; i < r + 1; i++)
    t[i] = INT_MAX;

  std::sort(v, v + n);
  int min = INT_MAX;

  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= r; j++) {
      int sub = t[j - v[i]];
      if (v[i] <= j && sub != INT_MAX)
        t[j] = std::min(sub + 1, t[j]);
    }

    if (t[r] < min)
      min = t[r];
  }

  return min;
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  for (int i = 0; i < 100; i++) {
    int r, n;
    in >> r >> n;

    int *v = new int[n];
    for (int j = 0; j < n; j++)
      in >> v[j];

    out << min_coins_v2(v, n, r) << endl;
  }
}

// greedy-activity

#include <fstream>
#include <iostream>
using namespace std;

class Activity {

private:
  int s;
  int e;

public:
  Activity(int start, int end) {
    s = start;
    e = end;
  }

  int start() { return s; }

  int end() { return e; }

  // Si ordina per i tempi di fine
  static void sort(Activity **v, int n) {
    for (int i = 1; i < n; i++) {
      int index = i;

      while (index > 0 && v[index]->end() < v[index - 1]->end()) {
        swap(v[index], v[index - 1]);
        index--;
      }
    }
  }

  static int select(Activity **v, int n) {
    int max = 1;
    int last = 0;

    for (int i = 1; i < n; i++) {
      if (v[i]->start() >= v[last]->end()) {
        max++;
        last = i;
      }
    }

    return max;
  }

  static void print(Activity **v, int n) {
    cout << "TOTAL: " << n << " -> ";
    for (int i = 0; i < n; i++)
      cout << "(s: " << v[i]->start() << " e: " << v[i]->end() << ") ";
    cout << endl;
  }
};

void solve(ifstream &in, ofstream &out, int n) {
  Activity **v = new Activity *[n];

  for (int i = 0; i < n; i++) {
    char tmp;
    int start, end;
    in >> tmp >> start >> end >> tmp;
    v[i] = new Activity(start, end);
  }

  Activity::sort(v, n);
  // Activity::print(v, n);
  out << Activity::select(v, n) << endl;
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  for (int i = 0; i < 100; i++) {
    int n;
    in >> n;
    solve(in, out, n);
  }
}

// coppie-heapsort

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

// terne-heapsort

#include <fstream>
#include <iostream>

using namespace std;

template <class H> class Terna {
private:
  H x;
  H y;
  H z;

public:
  Terna(H x, H y, H z) {
    this->x = x;
    this->y = y;
    this->z = z;
  }

  friend bool operator>(Terna &a, Terna &b) {
    if (a.x > b.x)
      return 1;

    else if (a.x == b.x && a.y > b.y)
      return 1;

    else if (a.x == b.x && a.y == b.y && a.z > b.z)
      return 1;

    return 0;
  }

  friend ostream &operator<<(ostream &os, Terna &c) {
    return os << "(" << c.x << " " << c.y << " " << c.z << ")";
  }
};

template <class H> class Heap {
private:
  Terna<H> **heap;
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
  Heap(Terna<H> **heap, int size) {
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
  Terna<H> **v = new Terna<H> *[n + 1];

  for (int i = 1; i <= n; i++) {
    char tmp;
    H x, y, z;

    in >> tmp >> x >> y >> z >> tmp;
    v[i] = new Terna<H>(x, y, z);
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

// ordinamento-lineare

#include <fstream>
#include <iostream>
#include <typeinfo>
using namespace std;

int *countingSort(ofstream &out, int *v, int n) {
  int min = v[0];
  int max = v[0];

  // Trovo il massimo e il minimo
  for (int i = 0; i < n; i++) {
    if (v[i] < min)
      min = v[i];

    else if (v[i] > max)
      max = v[i];
  }

  // Operazioni counting
  int range = (max - min) + 1;
  int *c = new int[range]{0};

  for (int i = 0; i < n; i++)
    c[v[i] - min]++;

  for (int i = 1; i < range; i++)
    c[i] += c[i - 1];

  // Sorting
  int *s = new int[n];

  for (int i = n - 1; i >= 0; i--)
    s[--c[v[i] - min]] = v[i];

  // Output
  for (int i = 0; i < range; i++)
    out << c[i] << " ";

  return s;
}

template <class H> void solve(ifstream &in, ofstream &out, int n) {
  int *array = new int[n];

  for (int i = 0; i < n; i++) {
    H value;
    in >> value;
    typeid(H) == typeid(double) ? array[i] = value * 10 : array[i] = value;
  }

  int *s = countingSort(out, array, n);

  for (int i = 0; i < n; i++) {
    if (typeid(H) == typeid(double))
      out << (double)s[i] / 10;

    else if (typeid(H) == typeid(char))
      out << (char)s[i];

    else
      out << s[i];

    out << " ";
  }

  out << endl;
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  for (int i = 0; i < 100; i++) {
    string type;
    int n;
    in >> type;
    in >> n;

    if (type == "int" || type == "bool")
      solve<int>(in, out, n);

    else if (type == "char")
      solve<char>(in, out, n);

    else if (type == "double")
      solve<double>(in, out, n);
  }
}

// coppie-counting

#include <fstream>
#include <iostream>

using namespace std;

class Coppia {
private:
  int x, y;

public:
  Coppia(double x, double y) {
    this->x = x * 10;
    this->y = y * 10;
  }

  int getx() { return x; }

  int gety() { return y; }

  friend ostream &operator<<(ostream &out, Coppia &c) {
    out << "(" << (double)c.getx() / 10 << " " << (double)c.gety() / 10 << ")";
  }
};

Coppia **countingSort(ostream &out, Coppia **v, int n) {
  int min = v[0]->getx();
  int max = v[0]->getx();

  // Trovo il massimo e il minimo
  for (int i = 0; i < n; i++) {
    if (v[i]->getx() < min)
      min = v[i]->getx();

    else if (v[i]->getx() > max)
      max = v[i]->getx();
  }

  // Operazioni counting
  int range = (max - min) + 1;
  int *c = new int[range]{0};

  for (int i = 0; i < n; i++)
    c[v[i]->getx() - min]++;

  for (int i = 1; i < range; i++)
    c[i] += c[i - 1];

  // Sorting
  Coppia **s = new Coppia *[n];

  for (int i = n - 1; i >= 0; i--)
    s[--c[v[i]->getx() - min]] = v[i];

  // Output
  for (int i = 0; i < range; i++)
    out << c[i] << " ";

  return s;
}

void solve(ifstream &in, ofstream &out, int n) {
  Coppia **array = new Coppia *[n];

  for (int i = 0; i < n; i++) {
    char tmp;
    double x, y;

    in >> tmp >> x >> y >> tmp;
    array[i] = new Coppia(x, y);
  }

  Coppia **s = countingSort(out, array, n);

  for (int i = 0; i < n; i++) {
    out << *s[i];
    out << " ";
  }

  out << endl;
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  for (int i = 0; i < 100; i++) {
    int n;
    in >> n;
    solve(in, out, n);
  }
}

// terne-counting

#include <fstream>
#include <iostream>

using namespace std;

class Terna {
private:
  int x, y, z;

public:
  Terna(double x, double y, double z) {
    this->x = x * 10;
    this->y = y * 10;
    this->z = z * 10;
  }

  int getx() { return x; }

  int gety() { return y; }

  int getz() { return z; }

  friend ostream &operator<<(ostream &out, Terna &c) {
    out << "(" << (double)c.getx() / 10 << " " << (double)c.gety() / 10 << " "
        << (double)c.getz() / 10 << ")";
  }
};

Terna **countingSort(ostream &out, Terna **v, int n) {
  int min = v[0]->getx();
  int max = v[0]->getx();

  // Trovo il massimo e il minimo
  for (int i = 0; i < n; i++) {
    if (v[i]->getx() < min)
      min = v[i]->getx();

    else if (v[i]->getx() > max)
      max = v[i]->getx();
  }

  // Operazioni counting
  int range = (max - min) + 1;
  int *c = new int[range]{0};

  for (int i = 0; i < n; i++)
    c[v[i]->getx() - min]++;

  for (int i = 1; i < range; i++)
    c[i] += c[i - 1];

  // Sorting
  Terna **s = new Terna *[n];

  for (int i = n - 1; i >= 0; i--)
    s[--c[v[i]->getx() - min]] = v[i];

  // Output
  for (int i = 0; i < range; i++)
    out << c[i] << " ";

  return s;
}

void solve(ifstream &in, ofstream &out, int n) {
  Terna **array = new Terna *[n];

  for (int i = 0; i < n; i++) {
    char tmp;
    double x, y, z;

    in >> tmp >> x >> y >> z >> tmp;
    array[i] = new Terna(x, y, z);
  }

  Terna **s = countingSort(out, array, n);

  for (int i = 0; i < n; i++)
    out << *s[i] << " ";

  out << endl;
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  for (int i = 0; i < 100; i++) {
    int n;
    in >> n;
    solve(in, out, n);
  }
}

// insert-RBTree

#include <fstream>
#include <iostream>
#define RED 0
#define BLACK 1
#define DBLACK 2
using namespace std;

template <class T> class TNode {
public:
  TNode(T Key, TNode<T> *NilNode) {
    left = right = parent = NilNode;
    key = new T(Key);
    color = RED;
  }

  TNode() {
    left = right = parent = NULL;
    key = NULL;
    color = BLACK;
  }

  TNode<T> *getLeft() { return left; }
  TNode<T> *getRight() { return right; }
  TNode<T> *getParent() { return parent; }

  int &getColor() { return color; }
  T &getKey() { return *key; }

  void setLeft(TNode<T> *left) { this->left = left; }
  void setRight(TNode<T> *right) { this->right = right; }
  void setParent(TNode<T> *parent) { this->parent = parent; }
  void setColor(int color) { this->color = color; }
  void setKey(T Key) { *(this->key) = Key; }

  ~TNode() { delete key; }

private:
  TNode<T> *left;
  TNode<T> *right;
  TNode<T> *parent;
  T *key;
  int color;
};

template <class T> class RBTree {
public:
  RBTree() {
    NilNode = new TNode<T>();
    Root = NilNode;
  }

  RBTree &insert(T Key) {
    TNode<T> *node = new TNode<T>(Key, NilNode);
    TNode<T> *pointer = Root;
    TNode<T> *previous = pointer;
    while (pointer != NilNode) {
      previous = pointer;
      if (Key <= pointer->getKey())
        pointer = pointer->getLeft();
      else
        pointer = pointer->getRight();
    }

    if (previous == NilNode) {
      Root = node;
    } else {
      if (Key <= previous->getKey())
        previous->setLeft(node);
      else
        previous->setRight(node);
    }
    node->setParent(previous);
    insertFixUp(node);
    return *this;
  }

  void printInOrder(ofstream &output) {
    _printInOrder(Root, output);
    output << endl;
  }

  void printPreOrder(ofstream &output) {
    _printPreOrder(Root, output);
    output << endl;
  }

  void printPostOrder(ofstream &output) {
    _printPostOrder(Root, output);
    output << endl;
  }

private:
  char map(int color) {
    if (color == RED)
      return 'R';
    if (color == BLACK)
      return 'B';
    if (color == DBLACK)
      return 'DB';
  }

  void _printInOrder(TNode<T> *pointer, ofstream &output) {
    if (pointer != NilNode) {
      _printInOrder(pointer->getLeft(), output);
      output << "(" << pointer->getKey() << " " << map(pointer->getColor())
             << ") ";
      _printInOrder(pointer->getRight(), output);
    }
  }

  void _printPreOrder(TNode<T> *pointer, ofstream &output) {
    if (pointer != NilNode) {
      output << "(" << pointer->getKey() << " " << map(pointer->getColor())
             << ") ";
      _printPreOrder(pointer->getLeft(), output);
      _printPreOrder(pointer->getRight(), output);
    }
  }

  void _printPostOrder(TNode<T> *pointer, ofstream &output) {
    if (pointer != NilNode) {
      _printPostOrder(pointer->getLeft(), output);
      _printPostOrder(pointer->getRight(), output);
      output << "(" << pointer->getKey() << " " << map(pointer->getColor())
             << ") ";
    }
  }

  void leftRotate(TNode<T> *node) {
    TNode<T> *y = node->getRight();
    node->setRight(y->getLeft());
    if (y->getLeft() != NilNode) {
      y->getLeft()->setParent(node);
    }
    if (node->getParent() != NilNode) {
      if (node == node->getParent()->getLeft()) {
        node->getParent()->setLeft(y);
      } else {
        node->getParent()->setRight(y);
      }

    } else {
      Root = y;
    }
    y->setParent(node->getParent());
    y->setLeft(node);
    node->setParent(y);
  }

  void rightRotate(TNode<T> *node) {
    TNode<T> *y = node->getLeft();
    node->setLeft(y->getRight());
    if (y->getRight() != NilNode) {
      y->getRight()->setParent(node);
    }
    if (node->getParent() != NilNode) {
      if (node == node->getParent()->getLeft()) {
        node->getParent()->setLeft(y);
      } else {
        node->getParent()->setRight(y);
      }

    } else {
      Root = y;
    }
    y->setParent(node->getParent());
    y->setRight(node);
    node->setParent(y);
  }

  void insertFixUp(TNode<T> *node) {
    Root->setColor(BLACK);
    TNode<T> *y = node->getParent();
    TNode<T> *z = node->getParent()->getParent();
    if (y->getColor() == RED) {
      if (y == z->getLeft()) // Caso sinistra
      {
        TNode<T> *w = z->getRight();
        if (w->getColor() == RED) {
          w->setColor(BLACK);
          y->setColor(BLACK);
          z->setColor(RED);
          insertFixUp(z);
        } else {
          if (node == y->getLeft()) {
            y->setColor(BLACK);
            z->setColor(RED);
            rightRotate(z);
          } else {
            node = y;
            leftRotate(node);
            insertFixUp(node);
          }
        }
      } else {
        TNode<T> *w = z->getLeft();
        if (w->getColor() == RED) {
          w->setColor(BLACK);
          y->setColor(BLACK);
          z->setColor(RED);
          insertFixUp(z);
        } else {
          if (node == y->getRight()) {
            y->setColor(BLACK);
            z->setColor(RED);
            leftRotate(z);
          } else {
            node = y;
            rightRotate(node);
            insertFixUp(node);
          }
        }
      }
    }
    Root->setColor(BLACK);
  }
  TNode<T> *Root;
  TNode<T> *NilNode;
};

template <class T>
void computa(RBTree<T> *albero, int n, ifstream &input, ofstream &output) {
  string order;
  input >> order;
  T key;
  for (int i = 0; i < n; i++) {
    input >> key;
    albero->insert(key);
  }

  if (order == "preorder")
    albero->printPreOrder(output);
  else if (order == "postorder")
    albero->printPostOrder(output);
  else
    albero->printInOrder(output);
}

int main() {
  ifstream input("input.txt");
  ofstream output("output.txt");
  string type;
  int n, i = 0;
  while (i++ < 100) {
    input >> type >> n;
    if (type == "int") {
      computa(new RBTree<int>, n, input, output);
    } else {
      computa(new RBTree<double>, n, input, output);
    }
  }
}

// altezza-RBTree

#include <fstream>
#include <iostream>
#define RED 0
#define BLACK 1
#define DBLACK 2
using namespace std;

template <class T> class TNode {
public:
  TNode(T Key, TNode<T> *NilNode) {
    left = right = parent = NilNode;
    key = new T(Key);
    color = RED;
  }

  TNode() {
    left = right = parent = NULL;
    key = NULL;
    color = BLACK;
  }

  TNode<T> *getLeft() { return left; }
  TNode<T> *getRight() { return right; }
  TNode<T> *getParent() { return parent; }
  int &getColor() { return color; }
  T &getKey() { return *key; }
  void setLeft(TNode<T> *left) { this->left = left; }
  void setRight(TNode<T> *right) { this->right = right; }
  void setParent(TNode<T> *parent) { this->parent = parent; }
  void setColor(int color) { this->color = color; }
  void setKey(T Key) { *(this->key) = Key; }
  ~TNode() { delete key; }

private:
  TNode<T> *left;
  TNode<T> *right;
  TNode<T> *parent;
  T *key;
  int color;
};

template <class T> class RBTree {
public:
  RBTree() {
    NilNode = new TNode<T>();
    Root = NilNode;
  }

  RBTree &insert(T Key) {
    TNode<T> *node = new TNode<T>(Key, NilNode);
    TNode<T> *pointer = Root;
    TNode<T> *previous = pointer;
    while (pointer != NilNode) {
      previous = pointer;
      if (Key <= pointer->getKey())
        pointer = pointer->getLeft();
      else
        pointer = pointer->getRight();
    }

    if (previous == NilNode) {
      Root = node;
    } else {
      if (Key <= previous->getKey())
        previous->setLeft(node);
      else
        previous->setRight(node);
    }
    node->setParent(previous);
    insertFixUp(node);
    return *this;
  }

  int height() { return _height(Root); }

private:
  int _height(TNode<T> *node) {
    if (node != NilNode)
      return max(_height(node->getLeft()) + 1, _height(node->getRight()) + 1);
    return 0;
  }

  void leftRotate(TNode<T> *node) {
    TNode<T> *y = node->getRight();
    node->setRight(y->getLeft());
    if (y->getLeft() != NilNode) {
      y->getLeft()->setParent(node);
    }
    if (node->getParent() != NilNode) {
      if (node == node->getParent()->getLeft()) {
        node->getParent()->setLeft(y);
      } else {
        node->getParent()->setRight(y);
      }

    } else {
      Root = y;
    }
    y->setParent(node->getParent());
    y->setLeft(node);
    node->setParent(y);
  }

  void rightRotate(TNode<T> *node) {
    TNode<T> *y = node->getLeft();
    node->setLeft(y->getRight());
    if (y->getRight() != NilNode) {
      y->getRight()->setParent(node);
    }
    if (node->getParent() != NilNode) {
      if (node == node->getParent()->getLeft()) {
        node->getParent()->setLeft(y);
      } else {
        node->getParent()->setRight(y);
      }

    } else {
      Root = y;
    }
    y->setParent(node->getParent());
    y->setRight(node);
    node->setParent(y);
  }

  void insertFixUp(TNode<T> *node) {
    Root->setColor(BLACK);
    TNode<T> *y = node->getParent();
    TNode<T> *z = node->getParent()->getParent();
    if (y->getColor() == RED) {
      if (y == z->getLeft()) // Caso sinistra
      {
        TNode<T> *w = z->getRight();
        if (w->getColor() == RED) {
          w->setColor(BLACK);
          y->setColor(BLACK);
          z->setColor(RED);
          insertFixUp(z);
        } else {
          if (node == y->getLeft()) {
            y->setColor(BLACK);
            z->setColor(RED);
            rightRotate(z);
          } else {
            node = y;
            leftRotate(node);
            insertFixUp(node);
          }
        }
      } else {
        TNode<T> *w = z->getLeft();
        if (w->getColor() == RED) {
          w->setColor(BLACK);
          y->setColor(BLACK);
          z->setColor(RED);
          insertFixUp(z);
        } else {
          if (node == y->getRight()) {
            y->setColor(BLACK);
            z->setColor(RED);
            leftRotate(z);
          } else {
            node = y;
            rightRotate(node);
            insertFixUp(node);
          }
        }
      }
    }
    Root->setColor(BLACK);
  }
  TNode<T> *Root;
  TNode<T> *NilNode;
};

template <class T>
void computa(RBTree<T> *albero, int n, ifstream &input, ofstream &output) {
  T key;
  for (int i = 0; i < n; i++) {
    input >> key;
    albero->insert(key);
  }
  output << albero->height() << endl;
}

int main() {
  ifstream input("input.txt");
  ofstream output("output.txt");
  string type;
  int n, i = 0;
  while (i++ < 100) {
    input >> type >> n;
    if (type == "int") {
      computa(new RBTree<int>, n, input, output);
    } else {
      computa(new RBTree<double>, n, input, output);
    }
  }
}

// print-lcs

#include <fstream>
#include <iostream>

using namespace std;

int **create_matrix(int n, int m) {
  int **v = new int *[n];

  for (int i = 0; i < n; i++)
    v[i] = new int[m]{0};

  return v;
}

void delete_matrix(int **v, int n, int m) {
  for (int i = 0; i < n; i++)
    delete[] v[i];

  delete[] v;
}

string lcs(string x, int n, string y, int m) {
  int **v = create_matrix(n + 1, m + 1);

  // LCS
  for (int i = 1; i < n + 1; i++)
    for (int j = 1; j < m + 1; j++)
      x[i - 1] == y[j - 1]
          ? v[i][j] = v[i - 1][j - 1] + 1            // Prev diagonal value + 1
          : v[i][j] = max(v[i - 1][j], v[i][j - 1]); // Max between left or top

  int maxseq = v[n][m];

  // Print LCS
  string slcs;

  int i = n;
  int j = m;

  while (i > 0 && j > 0) {
    if (x[i - 1] == y[j - 1]) { // Equal char: copy and move in diagonal
      slcs = x[i - 1] + slcs;
      i--;
      j--;
    }

    else if (v[i - 1][j] > v[i][j - 1]) // up > right move up
      i--;

    else // right > up move right
      j--;
  }

  // Free
  delete_matrix(v, n, m);
  return slcs;
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  for (int i = 0; i < 100; i++) {
    int m, n;
    string x, y;
    in >> m >> n >> x >> y;
    out << lcs(x, m, y, n) << endl;
  }
}

// activity

#include <fstream>
#include <iostream>
using namespace std;

class Activity {

private:
  int s;
  int e;

public:
  Activity(int start, int end) {
    s = start;
    e = end;
  }

  int start() { return s; }

  int end() { return e; }

  int profit() { return e - s; }

  // Si ordina per i tempi di fine
  static void sort(Activity **v, int n) {
    for (int i = 1; i < n; i++) {
      int index = i;

      // (1) Ordina per tempi di fine
      // (2) se i tempi di fine sono uguali confronta i tempi di inizio
      while ((index > 0 && v[index]->end() < v[index - 1]->end()) ||
             (index > 0 && v[index]->end() == v[index - 1]->end() &&
              v[index]->start() < v[index - 1]->start())) {
        swap(v[index], v[index - 1]);
        index--;
      }
    }
  }

  static int select(Activity **v, int n) {
    int *t = new int[n]{0};

    for (int i = 0; i < n; i++)
      t[i] = v[i]->profit();

    for (int i = 1; i < n; i++) {

      // j = i trova la prima activity compatibile partendo da i fino a j>=0
      for (int j = i; j >= 0; j--) {
        if (v[j]->end() <= v[i]->start()) {
          t[i] = max(t[i], t[j] + v[i]->profit());
        }
      }
    }

    int max = t[0];

    for (int i = 0; i < n; i++)
      if (t[i] > max)
        max = t[i];

    return max;
  }
};

void solve(ifstream &in, ofstream &out, int n) {
  Activity **v = new Activity *[n];

  for (int i = 0; i < n; i++) {
    char tmp;
    int start, end;
    in >> tmp >> start >> end >> tmp;
    v[i] = new Activity(start, end);
  }

  Activity::sort(v, n);
  out << Activity::select(v, n) << endl;
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  for (int i = 0; i < 100; i++) {
    int n;
    in >> n;
    solve(in, out, n);
  }
}

// print-resto

#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

int **create_matrix(int n, int m) {
  int **v = new int *[n];

  for (int i = 0; i < n; i++)
    v[i] = new int[m]{0};

  for (int i = 0; i < n; i++)
    for (int j = 1; j < m; j++)
      v[i][j] = INT_MAX;

  return v;
}

void delete_matrix(int **v, int n, int m) {
  for (int i = 0; i < n; i++)
    delete[] v[i];

  delete[] v;
}

void min_coins(int *v, int n, int r, ofstream &out) {
  std::sort(v, v + n);

  int **table = create_matrix(n + 1, r + 1);

  for (int i = 0; i < n; i++) {
    int index =
        i + 1; // Index righe tabella (Si parte dalla prima riga della matrice)

    for (int j = 1; j < r + 1; j++) {
      table[index][j] = table[index - 1][j];

      if (j >= v[i]) {
        int sub = table[index][j - v[i]];

        if (sub != INT_MAX)
          table[index][j] = min(sub + 1, table[index][j]);
      }
    }
  }

  // SOLUZIONE: numero di monete
  out << table[n][r] << " ";

  // STAMPA DELLE MONETE
  string print;
  int i = n;
  int j = r;

  while (i > 0 && j > 0) {
    int sub = j - v[i - 1]; // Sottosoluzione

    if (table[i][j] == table[i][sub] + 1 && sub >= 0) {
      j = sub;
      stringstream ss;
      ss << v[i - 1];
      string s = ss.str();
      print = s + " " + print;
    } else {
      i--;
    }
  }

  out << print << endl;
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  for (int i = 0; i < 100; i++) {
    int r, n;
    in >> r >> n;

    int *v = new int[n];

    for (int j = 0; j < n; j++)
      in >> v[j];

    min_coins(v, n, r, out);
  }
}

// matrix-chain

#include <fstream>
#include <iostream>
#include <limits.h>

using namespace std;

int **create_matrix(int n, int m) {
  int **v = new int *[n];

  for (int i = 0; i < n; i++)
    v[i] = new int[m]{0};

  return v;
}

void delete_matrix(int **v, int n, int m) {
  for (int i = 0; i < n; i++)
    delete[] v[i];

  delete[] v;
}

int matrix_chain(int *v, int n) {
  int **table = create_matrix(n, n);

  for (int l = 2; l < n; l++) {
    for (int i = 0; i < n - l; i++) {
      int j = i + l;

      table[i][j] = INT_MAX;

      for (int k = i + 1; k < j; k++) {
        int q = table[i][k] + table[k][j] + v[i] * v[k] * v[j];

        if (q < table[i][j])
          table[i][j] = q;
      }
    }
  }

  return table[0][n - 1];
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  for (int i = 0; i < 100; i++) {
    int n;
    in >> n;
    int *vett = new int[n + 1];
    int r, c;

    for (int j = 0; j < n; j++) {
      char tmp;
      in >> tmp;
      in >> r;
      in >> tmp;
      in >> c;
      in >> tmp;
      vett[j] = r;
    }

    vett[n] = c;
    out << matrix_chain(vett, n + 1) << endl;
  }
}

// bellman-ford

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
  H *nodes;
  int totalnode;
  int nsize;

  Edge **edges;
  int totaledge;
  int esize;

  int find_node_index(H x) {
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
    nodes = new H[this->totalnode];

    esize = nsize = 0;
  }

  ~Graph() {}

  void addNode(H x) { nodes[nsize++] = x; }

  void addEdge(H x, H y, int p) {
    int posx = find_node_index(x);
    int posy = find_node_index(y);

    edges[esize++] = new Edge(posx, posy, p);
  }

  void bellmanFord(H s, H f, ofstream &out) {
    int source = find_node_index(s);
    int dest = find_node_index(f);

    int *dist = new int[nsize];

    for (int i = 0; i < nsize; i++)
      dist[i] = INT_MAX;

    dist[source] = 0;

    for (int i = 1; i < nsize; i++) {
      for (int j = 0; j < esize; j++) {
        int s = edges[j]->getS();
        int e = edges[j]->getE();
        int w = edges[j]->getW();

        if (dist[s] != INT_MAX && dist[s] + w < dist[e])
          dist[e] = dist[s] + w;
      }
    }

    for (int i = 0; i < esize; i++) {
      int s = edges[i]->getS();
      int e = edges[i]->getE();
      int w = edges[i]->getW();

      // Individua il ciclo negativo dopo le n - 1 volte del for precedente
      if (dist[s] != INT_MAX && dist[s] + w < dist[e]) {
        out << "undef." << endl;
        return;
      }
    }

    if (dist[dest] == INT_MAX)
      out << "inf." << endl;
    else
      out << dist[dest] << endl;
  }
};

template <class H> void solve(ifstream &in, ofstream &out, int n, int e) {
  Graph<H> graph = Graph<H>(n, e);

  for (int j = 0; j < n; j++) {
    H val;
    in >> val;
    graph.addNode(val);
  }

  for (int j = 0; j < e; j++) {
    char tmp;
    H x, y;
    int p;
    in >> tmp >> x >> y >> p >> tmp;
    graph.addEdge(x, y, p);
  }

  H start, dest;
  in >> start >> dest;

  graph.bellmanFord(start, dest, out);
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  for (int i = 0; i < 100; i++) {
    int n, e;
    in >> n >> e;
    string type;
    in >> type;

    if (type == "int")
      solve<int>(in, out, n, e);

    else if (type == "double")
      solve<double>(in, out, n, e);
  }
}

// bellman-ford-p

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

// dijkstra

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
  H *nodes;
  int totalnode;
  int nsize;

  Edge **edges;
  int totaledge;
  int esize;

  int find_node_index(H x) {
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
    nodes = new H[this->totalnode];

    esize = nsize = 0;
  }

  ~Graph() {}

  void addNode(H x) { nodes[nsize++] = x; }

  void addEdge(H x, H y, int p) {
    int posx = find_node_index(x);
    int posy = find_node_index(y);

    edges[esize++] = new Edge(posx, posy, p);
  }

  void dijkstra(H s, H f, ofstream &out) {
    int source = find_node_index(s);
    int dest = find_node_index(f);

    int *dist = new int[nsize];

    for (int i = 0; i < nsize; i++)
      dist[i] = INT_MAX;

    dist[source] = 0;

    // Array nodi visitati
    bool *visit = new bool[nsize]{0};

    for (int i = 0; i < nsize; i++) {

      // Troviamo l'indice del minimo
      int min = INT_MAX;
      int posmin = 0;

      for (int m = 0; m < nsize; m++) {
        if (visit[m] == 0 && dist[m] < min) {
          min = dist[m];
          posmin = m;
        }
      }

      // "Estrazione" del nodo mettendolo a true
      visit[posmin] = 1;

      for (int j = 0; j < esize; j++) {
        int s = edges[j]->getS();
        int e = edges[j]->getE();
        int w = edges[j]->getW();

        // Se il vertice s ha lo stesso indice del minimo e la nuova distanza e'
        // minore
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

template <class H> void solve(ifstream &in, ofstream &out, int n, int e) {
  Graph<H> graph = Graph<H>(n, e);

  for (int j = 0; j < n; j++) {
    H val;
    in >> val;
    graph.addNode(val);
  }

  for (int j = 0; j < e; j++) {
    char tmp;
    H x, y;
    int p;
    in >> tmp >> x >> y >> p >> tmp;
    graph.addEdge(x, y, p);
  }

  H start, dest;
  in >> start >> dest;

  graph.dijkstra(start, dest, out);
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");

  for (int i = 0; i < 100; i++) {
    int n, e;
    in >> n >> e;
    string type;
    in >> type;

    if (type == "int")
      solve<int>(in, out, n, e);

    else if (type == "double")
      solve<double>(in, out, n, e);
  }
}