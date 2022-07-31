#include <iostream>
#include <fstream>
using namespace std;

// soluzione del problema multiBST contenuto all'interno del Coding Contest

template <class T> class Nodo {
private:
    T *key;
    int m;
    Nodo<T> *left, *right, *parent;
public:
    Nodo(T& key) {
        this->key = &key;
        left = right = parent = NULL;
        m = 1;
    }
    
    //metodi get
    T& getKey() { return *key;}
    int getMult() { return m;}
    Nodo<T>* getLeft() {return left;}
    Nodo<T>* getRight() {return right;}
    Nodo<T>* getParent() {return parent;}

    //metodi set
    void setKey(T& key) {
        this->key = &key;
    }
    void setLeft(Nodo<T> *left) {
        this->left = left;
    }
    void setRight(Nodo<T> *right) {
        this->right = right;
    }
    void setParent(Nodo<T> *parent) {
        this->parent = parent;
    }
    void incMult() {
        m = m+1;
    }
    void decMult() {
        m = m-1;
    }
    void setMult(int m) {
        this->m = m;
    }

};


template <class T> class BST {
private:
    int n;
    Nodo<T>* root, *current;
    
    Nodo<T>* _search(Nodo<T>* x, T key) {
        if(!x) return NULL;
        if(x->getKey()==key) return x;
        if(key <= x->getKey())
            return _search(x->getLeft(), key);
        else return _search(x->getRight(), key);
    }
    
    Nodo<T>* _min(Nodo<T>* x) {
        if(!x) return NULL;
        if(!x->getLeft()) return x;
        return _min(x->getLeft());
    }
    
    Nodo<T>* _successore(Nodo<T>* x) {
        if(!x) return NULL;
        if(x->getRight())
            return _min(x->getRight());
        Nodo<T>* p = x->getParent();
        while(p && p->getKey()<x->getKey()) {
            p = p->getParent();
        }
        return p;
    }
    
    void _inorder(Nodo<T>* x) {
        if(!x) return;
        _inorder(x->getLeft());
        cout << "(" << x->getKey() << ", " << x->getMult() << ") ";
        _inorder(x->getRight());
    }

    void _inorder(Nodo<T>* x, ostream& out) {
        if(!x) return;
        _inorder(x->getLeft(), out);
        for(int i=0; i<x->getMult(); i++)
            out << x->getKey() << " ";
        _inorder(x->getRight(), out);
    }

    void _preorder(Nodo<T>* x, ostream& out) {
        if(!x) return;
        for(int i=0; i<x->getMult(); i++)
            out << x->getKey() << " ";
        _preorder(x->getLeft(), out);
        _preorder(x->getRight(), out);
    }

    void _postorder(Nodo<T>* x, ostream& out) {
        if(!x) return;
        _postorder(x->getLeft(), out);
        _postorder(x->getRight(), out);
        for(int i=0; i<x->getMult(); i++)
            out << x->getKey() << " ";
    }

    int _leafCount(Nodo<T>* x) {
        if(!x) return 0;
        if(!x->getLeft() && !x->getRight()) return 1;
        return _leafCount(x->getLeft()) + _leafCount(x->getRight());
    }
    
public:
    BST() {
        n = 0;
        root = current = NULL;
    }
    
    BST<T>& ins(T& key) {
        //prima di tutto controllo se esiste già una chiave che contiene key
        Nodo<T>* x = _search(root, key);
        if(x) {
            x->incMult();
            return *this;
        }
        //altrimenti aggiungo il nuovo nodo
        x = new Nodo<T>(key);
        Nodo<T>* tmp = root;
        Nodo<T>* p = NULL;
        while(tmp) {
            p = tmp;
            if(key <= tmp->getKey()) tmp = tmp->getLeft();
            else tmp = tmp->getRight();
        }
        if(!p) root = x;
        else {
            x->setParent(p);
            if(key <= p->getKey())
                p->setLeft(x);
            else p->setRight(x);
        }
        n++;
        return *this;
    }
    
    void inorder() {
        _inorder(root);
        cout << endl;
    }
    
    T* min() {
        Nodo<T>* x = _min(root);
        if(x) return &x->getKey();
        return NULL;
    }

    T* successore(T key) {
        Nodo<T>* x = _search(root, key);
        if(x) {
            Nodo<T>* y = _successore(x);
            if(y) return &y->getKey();
        }
        return NULL;
    }

    BST<T>& canc(T key) {
        Nodo<T> *x = _search(root, key);
        if(!x) return *this;
        x->decMult();
        if(x->getMult()>=1) return *this;
        //nel caso in cui la molteplicità scende a 0 allora cancello fisicamente il nodo
        if(x->getLeft() && x->getRight()) {
            //caso 3
            Nodo<T> *y = _successore(x);
            T& v = x->getKey();
            x->setKey(y->getKey());
            y->setKey(v);
            x->setMult(y->getMult());
            y->setMult(0);
            x = y;
        }
        //casi 1 e 2
        Nodo<T>* z = x->getLeft();
        if(!z) z = x->getRight();
        Nodo<T> *p = x->getParent();
        if(!p) root = z;
        else {
            if(p->getLeft()==x)
                p->setLeft(z);
            else p->setRight(z);
        }
        if(z) z->setParent(p);
        n--;
        return *this;
    }
    
    int leafCount() {
        return _leafCount(root);
    }
    
    void inorder(ostream& out) {
        _inorder(root, out);
    }

    void preorder(ostream& out) {
        _preorder(root, out);
    }

    void postorder(ostream& out) {
        _postorder(root, out);
    }

};



int main() {
    /*BST<int>* t = new BST<int>();
    int e1 = 8;
    int e2 = 14;
    int e3 = 11;
    int e4 = 17;
    int e5 = 3;
    t->ins(e1).ins(e2).ins(e3).ins(e4).ins(e5);
    t->inorder();
    int e6 = 3;
    t->ins(e6);
    int e7 = 3;
    t->ins(e7);
    int e8 = 11;
    t->ins(e8);
    int e9 = 8;
    t->ins(e9);
    t->inorder();
    t->canc(8);
    t->inorder();
    t->canc(8);
    t->inorder();
*/
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");

    for(int task=0; task<100; task++) {
        string tipo, visita;
        in >> tipo;
        int n;
        in >> n;
        in >> visita;
        if(tipo=="int") {
            BST<int>* t = new BST<int>();
            for(int i=0; i<n; i++) {
                char c,b;
                in >> c;
                in >> b;
                in >> b;
                in >> b;
                if(c=='i') {
                    int *e = new int(0);
                    in >> *e;
                    t->ins(*e);
                }
                else {
                    in >> b;
                    int e;
                    in >> e;
                    t->canc(e);
                }
            }
            if(visita=="preorder") t->preorder(out);
            if(visita=="inorder") t->inorder(out);
            if(visita=="postorder") t->postorder(out);
            out << endl;
        }
        else {
            BST<double>* t = new BST<double>();
            for(int i=0; i<n; i++) {
                char c,b;
                in >> c;
                in >> b;
                in >> b;
                in >> b;
                if(c=='i') {
                    double *e = new double(0);
                    in >> *e;
                    t->ins(*e);
                }
                else {
                    in >> b;
                    double e;
                    in >> e;
                    t->canc(e);
                }
            }
            if(visita=="preorder") t->preorder(out);
            if(visita=="inorder") t->inorder(out);
            if(visita=="postorder") t->postorder(out);
            out << endl;
        }
    }
    
    in.close();
    out.close();

}

