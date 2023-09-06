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