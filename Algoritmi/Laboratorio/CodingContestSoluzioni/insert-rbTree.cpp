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