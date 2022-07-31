#include <iostream>
#include <fstream>
using namespace std;

template<class T> class Nodo {
private:
    T* key;
    Nodo<T>* left, *right, * parent;
  
public:
    Nodo(T key) {
        this->key = new T(key);
        left = right = parent = NULL;
    }

    void setKey(T key)              {this->key = new T(key);}
    void setLeft(Nodo<T>* left)     {this->left = left;}
    void setRight(Nodo<T>* right)   {this->right = right;}
    void setParent(Nodo<T>* parent) {this->parent = parent;}
    
    T getKey() {return *key;}
    Nodo<T>* getLeft()  {return left;}
    Nodo<T>* getRight() {return right;}
    Nodo<T>* getParent(){return parent;}
};

template<class T> class BST {
private:
    int n; 
    Nodo<T>* root;

    Nodo<T>* _search(T key, Nodo<T>* x) {
        Nodo<T> *tmp = x;
        while(tmp!=NULL && tmp->getKey()!=key) {
            if(key <= tmp->getKey()) tmp = tmp->getLeft();
            else tmp = tmp->getRight();
        }
        return tmp;
    }

    Nodo<T>* _rsearch(T key, Nodo<T>* x) {
        if(!x) return NULL;
        if(x->getKey()==key) return x;
        if(key <= x->getKey()) return _rsearch(key, x->getLeft());
        else return _rsearch(key, x->getRight());
    }

    Nodo<T>* _min(Nodo<T>* x) {
        if(!x) return NULL;
        Nodo<T>* tmp = x;
        while(tmp->getLeft()) tmp = tmp->getLeft();
        return tmp;
    }

    Nodo<T>* _rmin(Nodo<T>* x) {
        if(!x) return NULL;
        if(!x->getLeft()) return x;
        return _rmin(x->getLeft());
    }

    Nodo<T>* _successore(Nodo<T> *x) {
        if(!x) return NULL;
        if(x->getRight())
            return _min(x->getRight());
        Nodo<T>* tmp = x->getParent();
        while(tmp && tmp->getKey() < x->getKey())
            tmp = tmp->getParent();
        return tmp;
    }

    int _rprof(T key, Nodo<T>* x) {
        if(!x) return -1;
        if(x->getKey() == key) return 0;
        int p;
        if(key<x->getKey()) return p=_rprof(key, x->getLeft());
        else return p=_rprof(key, x->getRight());
        if(p>=0) return p+1;
        return -1;
    }

    int _prof(T key, Nodo<T>* x) {
        if(!x) return -1;
        int p = 0;
        Nodo<T> *tmp = x;
        while(tmp && tmp->getKey()!=key) {
            if(key < tmp->getKey()) tmp = tmp->getLeft();
            else tmp = tmp->getRight();
            p++;
        }
        if(!tmp) return -1;
        return p;
    }
    
public:
    BST() {
        n = 0;
        root = NULL;
    }
    
    BST<T>& ins(T key) {
        Nodo<T>* tmp = root;
        Nodo<T>* parent = NULL;
        Nodo<T>* x = new Nodo<T>(key);
        n++;
        while(tmp!=NULL) {
            parent = tmp;
            if(key <= tmp->getKey())
                tmp = tmp->getLeft();
            else
                tmp = tmp->getRight();
        }
        if(parent == NULL) { 
            root = x;
            return *this;
        }
        if(key <= parent->getKey())
            parent->setLeft(x);
        else parent->setRight(x);
        x->setParent(parent);
        return *this;
    }

     BST<T>& canc(T key){
       Nodo<T>* x = _rsearch(key, root);
       if(!x) return *this;
       if(x->getLeft() && x->getRight()){
            Nodo<T>* y = _successore(x);
            T val = x->getKey();
            x->setKey(y->getKey());
            y->setKey(val);
            x = y;
       }
       Nodo<T>* z = x->getLeft();
       if(!z) z = x->getRight();
       Nodo<T>* parent = x->getParent();
       if(!parent) root = z;
       else{
           if(parent->getLeft()==x) parent->setLeft(z); 
           else parent->setRight(z);
       }
       if(z) z->setParent(parent);
       n--;
       return *this;
    }

    int search(T key) {
        return _rsearch(key, root)!=NULL;
    }
   
    int prof(T key) {
        return _prof(key, root);
    }

    T* min() {
        Nodo<T>* x = _rmin(root);
        if(x) return new T(x->getKey());
        return NULL;
    }

    T* successore(T key) {
        Nodo<T> *x = _search(key, root);
        if(x) {
            Nodo<T> *y = _successore(x);
            if(y) return new T(y->getKey());
        }
        return NULL;
    }
    
};

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    string type;
    while(in >> type){
        int dim;
        in >> dim;

        if(type=="int"){
            BST<int> *b = new BST<int>();
            char c;
            int num;
            for(int i=0; i<dim; i++){
                in >> c;
                if(c == 'i'){
                    for(int count=0; count<=2; count++) in >> c;
                    in >> num;
                    b->ins(num);
                }
                else if(c == 'c'){
                    for(int count=0; count<=3; count++) in >> c;
                    in >> num;
                    b->canc(num);
                }
            }
            in >> num;
            out << b->prof(num);
        }

        if(type=="double"){
            BST<double> *b = new BST<double>();
            char c;
            double num;
            for(int i=0; i<dim; i++){
                in >> c;
                if(c == 'i'){
                    for(int count=0; count<=2; count++) in >> c;
                    in >> num;
                    b->ins(num);
                }
                else if(c == 'c'){
                    for(int count=0; count<=3; count++) in >> c;
                    in >> num;
                    b->canc(num);
                }
            }
            in >> num;
            out << b->prof(num);
        }
        out << endl;
    }
    in.close();
    out.close();

    return 0;
}

