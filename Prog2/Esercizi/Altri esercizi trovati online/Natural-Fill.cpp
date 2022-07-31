#include <iostream>
#include <fstream>
using namespace std;

// soluzione del problema natural-fill contenuto all'interno del Coding Contest
template<class T>
void scambia(T *v, int i, int j) {
    T tmp = v[j];
    v[j] = v[i];
    v[i] = tmp;
}

template<class T>
void selectionsort(T* v, int n){
    for(int i=0; i<n-1; i++){
        int m = i;
        for(int j=i+1; j<n; j++)
            if(v[j]<v[m]) m = i;
        scambia(v,m,i);
    }
}

template<class T>
void insertionsort(T *v, int n) {
    for(int i=1; i<n; i++) {
        int j = i;
        while(j>0 && v[j-1] > v[j]) {
            scambia(v,j,j-1);
            j--;
        }
    }
}


template <class T> class Nodo {
private:
    T *key;
    Nodo<T> *left, *right, *parent;
public:
    Nodo(T& key) {
        this->key = &key;
        left = right = parent = NULL;
    }
    
    //metodi get
    T& getKey() { return *key;}
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
    
    
    int _leafCount(Nodo<T>* x) {
        if(!x) return 0;
        if(!x->getLeft() && !x->getRight()) return 1;
        return _leafCount(x->getLeft()) + _leafCount(x->getRight());
    }
    
    
    void _inorder(Nodo<T>* x) {
        if(!x) return;
        _inorder(x->getLeft());
        cout << x->getKey() << " ";
        _inorder(x->getRight());
    }


     void _preorder(Nodo<T>* x){
         if(!x) return;
             cout << x->getKey() << " ";
         _preorder(x->getLeft());
         _preorder(x->getRight());
     }

     void _postorder(Nodo<T>* x){
         if(!x) return;
         _postorder(x->getLeft());
         _postorder(x->getRight());
         cout << x->getKey() << " ";
     }
    
public:
    BST() {
        n = 0;
        root = current = NULL;
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
        if(x->getLeft() && x->getRight()) {
            //caso 3
            Nodo<T> *y = _successore(x);
            //cout << x->getKey() << endl;
            //cout << y->getKey() << endl;
            T& v = x->getKey();
            x->setKey(y->getKey());
            y->setKey(v);
            //cout << x->getKey() << endl;
            //cout << y->getKey() << endl;
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
    
    void naturalFill(T *v, int n) {
        if(n!=this->n) {
            cout << "Natural Fill non eseguibile" << endl;
            return;
        }
        Nodo<T>* tmp = _min(root);
    
        int i=0;
        while(tmp!=NULL) {
            tmp->setKey(v[i]);
            tmp = _successore(tmp);
            i++;
        }
    }
    
  void inorder() {
        _inorder(root);
        cout << endl;
    }

    void preorder(){
        _preorder(root);
        cout << endl;

    }

    void postorder(){
        _postorder(root);
        cout << endl;

    }
    
};

template <class H> ostream& operator<<(ostream& out, const BST<H>& t) {
    BST<H> tmp = t;
    tmp.postorder(out);
    return out;
}



int main() {
    BST<int>* t = new BST<int>();
    int n = 10;
    int A[10] = {71,87,14,125,41,117,248,242,15,274};
    for(int i = 0; i<n; i++){
        int a = A[i];
        int *e = new int(a);
        t->ins(*e);
    }
    //t->inorder();
    int v[10] = {5,9,10,12,17,22,23,28,32,37};
    //insertionsort(v,10);
    t->naturalFill(v,10);
    t->preorder();
    t->inorder();
    t->postorder();
    
    return 0;
}

