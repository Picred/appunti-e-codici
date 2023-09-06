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