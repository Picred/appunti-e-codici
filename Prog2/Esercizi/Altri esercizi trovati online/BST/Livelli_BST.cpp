#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <class T> class Nodo{
private:
    T* key;
    Nodo<T>* left, *right, *parent;

public:
    Nodo(T key){
        this->key = new T(key);
        left = right = parent = NULL;
    }

    void setKey(T key)              {this->key = new T(key);}
    void setLeft(Nodo<T>* left)     {this->left = left;}
    void setRight(Nodo<T>* right)   {this->right = right;}
    void setParent(Nodo<T>* parent) {this->parent = parent;}

    T getKey()          {return *key;}          
    Nodo<T>* getLeft()  {return left;}
    Nodo<T>* getRight() {return right;}
    Nodo<T>* getParent(){return parent;}
};

template <class T> class BST{
private:
    int n;
    Nodo<T>* root;

    Nodo<T>* _rsearch(T key, Nodo<T>* r){
        if(!r) return NULL;
        if(r->getKey()==key) return r;
        if(key < r->getKey()) return _rsearch(key, r->getLeft());
        else return _rsearch(key, r->getRight());
    }

    Nodo<T>* _rmin(Nodo<T>* r){
        if(!r) return NULL;
        if(!r->getLeft()) return r;
        return _rmin(r->getLeft());
    }

    Nodo<T>* _successore(Nodo<T>* r){
        if(!r) return NULL;
        if(r->getRight())
            return _rmin(r->getRight());
        Nodo<T>* p = r->getParent();
        while(p && p->getKey() < r->getKey())
            p = p->getParent();
        return p;
    }

    int _altezza(Nodo<T>* x) { 
        Nodo<T>* tmp = _rmin(x);
        int p = 0; 
        while(tmp!=NULL)  { 
            int t = _prof(x, tmp->getKey());    
            if(p<t) p = t;
            tmp = _successore(tmp);            
        }
        return p;
    }

    int _prof(Nodo<T>* r, T key){
        if(!r) return -1;
        Nodo<T>* tmp = r;
        int p = 0;
        while(tmp && tmp->getKey()!=key){
            if(key < tmp->getKey()) tmp = tmp->getLeft();
            else tmp = tmp->getRight();
            p++;
        }
        if(!tmp) return -1;
        return p;   
    }

    int _rprof(Nodo<T>*r){
        if(!r->getParent()) return 0;
        return _rprof(r->getParent())+1;
    }

    void _preorder(ostream& os, Nodo<T>* r){
        if(!r) return;
        os << r->getKey() << " ";
        _preorder(os, r->getLeft());
        _preorder(os, r->getRight());
    }

    void _inorder(ostream& os, Nodo<T>* r){
        if(!r) return;
        _inorder(os, r->getLeft());
        os << r->getKey() << " ";
        _inorder(os, r->getRight());
    }

    void _postorder(ostream& os, Nodo<T>* r){
        if(!r) return;
        _postorder(os, r->getLeft());
        _postorder(os, r->getRight());
        os << r->getKey() << " ";
    }

public:
    BST(){
        n = 0;
        root = NULL;
    }

    BST<T>& ins(T key){
        Nodo<T>* tmp = root;
        Nodo<T>* parent = NULL;
        Nodo<T>* x = new Nodo<T>(key);
        n++;
        while(tmp){
            parent = tmp;
            if(key <= tmp->getKey()) tmp = tmp->getLeft();
            else tmp = tmp->getRight();
        }
        if(!parent){
            root = x;
            return *this;
        }
        if(key <= parent->getKey()) parent->setLeft(x);
        else parent->setRight(x);
        x->setParent(parent);
        return *this;
    }

    BST<T>& canc(T key){
       Nodo<T>* x = _rsearch(key, root);
       if(!x) return *this;
       if(x->getLeft() && x->getRight()){
            Nodo<T>* y = _successore(x);
            x->setKey(y->getKey());
            y->setKey(key);
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

    int search(T key){
         return (_rsearch(key, root)!=NULL);
    }

    void altezza(ostream& os) { 
        Nodo<T>* x = root;
        if(!x) return;
        int p = 0; 
        Nodo<T>* tmp = _rmin(root);
        while(tmp!=NULL)  { 
            int t = _prof(x, tmp->getKey());    
            if(p<t) p = t;
            tmp = _successore(tmp);            
        }
        os << p << " ";
    }

    T* successore(T key){
        Nodo<T>* tmp = _search(key, root);
        while(tmp){
            Nodo<T>* y = _successore(tmp);
            if(y) return new T(tmp->getKey());
        }
        return NULL;
    }

    T* min(){
        return _rmin(root);
    }

    void preorder(ostream& os){
        return _preorder(os, root);
    }

    void inorder(ostream& os){
        return _inorder(os, root);
    }

    void postorder(ostream& os){
        return _postorder(os, root);
    }

    void count(ostream& os){
    int c = _altezza(root)+1;
    int A[c] = {0};
    Nodo<T>* x = _rmin(root);
    if(!x) return;
    while(x){
        int t = _rprof(x);
        A[t] += 1;
        x = _successore(x);
    }

    for(int i=0; i<c; i++) os << A[i] << " ";
    }

};

/*
int 10 ins:281 ins:72 ins:9 ins:70 ins:218 ins:128 ins:168 ins:130 ins:173 ins:184 
    ^                                                                         ^
*/

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
            b->altezza(out);

            b->count(out);
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
            b->altezza(out);

            b->count(out);
        }
        out << endl;
    }
    in.close();
    out.close();

    return 0;
}



