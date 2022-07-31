#include <iostream>
#include <fstream>
using namespace std;

// soluzione del problema natural-fill contenuto all'interno del Coding Contest

template <class T> class Nodo {
private:
    T *key;
    Nodo<T> *left, *right, *parent;
    
public:
    Nodo(T key) {
        this->key = new T(key);
        left = right = parent = NULL;
    }
    
    void setKey(T key)             {this->key = new T(key);}
    void setLeft(Nodo<T> *left)     {this->left = left;}
    void setRight(Nodo<T> *right)   {this->right = right;}
    void setParent(Nodo<T> *parent) {this->parent = parent;}

    T getKey() { return *key;}
    Nodo<T>* getLeft() {return left;}
    Nodo<T>* getRight() {return right;}
    Nodo<T>* getParent() {return parent;}
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
        while(p && p->getRight()==x) {
            x = p;
            p = p->getParent();
        }
        return p;
    }
    
    void _postorder(ostream& os, Nodo<T>* x) {
        if(!x) return;
        _postorder(os,x->getLeft());
        _postorder(os,x->getRight());
        os << x->getKey() << " ";
    }
    
public:
    BST() {
        n = 0;
        root = NULL;
    }
    
    BST<T>& ins(T& key) {
        Nodo<T>* x = new Nodo<T>(key);
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
        
    T* min() {
        Nodo<T>* x = _min(root);
        if(x) return new T(x->getKey());
        return NULL;
    }

    T* successore(T key) {
        Nodo<T>* x = _search(root, key);
        if(x) {
            Nodo<T>* y = _successore(x);
            if(y) return new T(y->getKey());
        }
        return NULL;
    }

    BST<T>& canc(T key) {
        Nodo<T> *x = _search(root, key);
        if(!x) return *this;
        if(x->getLeft() && x->getRight()) {
            Nodo<T> *y = _successore(x);
            T& v = x->getKey();
            x->setKey(y->getKey());
            y->setKey(v);
            x = y;
        }
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
 
    void naturalFill(T *v, int n) {
        if(n!=this->n) {
            cout << "Natural Fill non eseguibile" << endl;
            return;
        }
        Nodo<T>* tmp = _min(root);
        int i=0;
        while(tmp) {
            tmp->setKey(v[i]);
            tmp = _successore(tmp);
            i++;
        }
    }
    
    void postorder(ostream& os) {
        _postorder(os,root);
    }
    
};

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    string tipo;
    while(in >> tipo){
        int n;
        in >> n;
        if(tipo=="int") {
            BST<int>* t = new BST<int>();
            for(int i=0; i<n; i++) {
                int *e = new int(0);
                in >> *e;
                t->ins(*e);
            }
            int v[n];
            for(int i=0; i<n; i++) {
                in >> v[i];
            }
            t->naturalFill(v,n);
            t->postorder(out);
        }
        else {
            BST<double>* t = new BST<double>();
            for(int i=0; i<n; i++) {
                double *e = new double(0);
                in >> *e;
                t->ins(*e);
            }
            double v[n];
            for(int i=0; i<n; i++) {
                in >> v[i];
            }
            t->naturalFill(v,n);
            t->postorder(out);
        }
        out << endl;
    }
    in.close();
    out.close();

    return 0;
}

