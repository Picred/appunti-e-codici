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

    T getKey()          {return *key;}           //dubbio
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

    T* _prova(Nodo<T>* x, T *v){
    if(!x) return NULL;
    Nodo<T>* tmp = _rmin(x);
    int i = 0;
    while(tmp){
        v[i] = _prof(root, tmp->getKey());
        tmp = _successore(tmp);
        i++;
    }
    return v;
}


    int _altezza(Nodo<T>* x) { // O(NlogN) - O(N^2)
        Nodo<T>* tmp = _rmin(x); // si parte dal minimo del sottoalbero: O(N)
        int p = 0; // massimo temporaneo
        while(tmp!=NULL)  { // da verificare !!  O(N)
            int t = _prof(x,tmp->getKey());    //O(N)
            if(t>p) p = t;
            tmp = _successore(tmp);             // O(N)
        }
        return p;
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

    int altezza(){
        return _altezza(root);
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

    T* prova(T *v){
        return _prova(root,v);
    }
};

template <class T> 
void merge(T *v, int n, int m){
    T b[n];
    int i,j,k;
    i = k = 0;
    j = m;
    while(i<m && j<n){
        if(v[i]<v[j]) b[k++] = v[i++];
        else b[k++] = v[j++];
    }
    while(i<m) b[k++] = v[i++];
    while(j<n) b[k++] = v[j++];

    for(int i=0; i<n; i++) v[i] = b[i];
}

template <class T> 
void mergesort(T* v, int n){
    if(n<=1) return;
    int m = n/2;
    mergesort(v,m);
    mergesort(v+m,n-m);
    merge(v,n,m);
}

template <class T>
T eliminaDuplicati (T *a, int n) /* Vettore ordinato */
{
    int i;
    int k = 1;
    for (i = 1; i < n; i++) /* per tutti gli elementi a partire dal secondo */
    {
        if (a[i] != a[i-1]) /* se nuovo elemento (non copia del precedente) */
        {
            a[k] = a[i];
            k++;
        }
    }
    return k;
} 

//int 60 ins:83 ins:124 ins:285 ins:290 ins:243 canc:124 canc:290 canc:83 ins:150 ins:100 canc:243 ins:123 canc:100 canc:123 ins:284 ins:159 canc:285 ins:276 ins:136 ins:0 ins:188 ins:139 ins:245 ins:111 canc:136 ins:279 ins:235 canc:276 ins:75 ins:24 ins:28 ins:66 ins:202 ins:217 ins:234 canc:235 canc:245 canc:234 canc:217 canc:279 ins:239 ins:121 ins:241 ins:212 ins:92 ins:112 canc:202 ins:97 ins:37 ins:133 ins:114 ins:93 canc:212 canc:75 ins:30 canc:92 canc:66 ins:277 ins:268 ins:230
// ^

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
            out << b->altezza() << " ";
            int v[dim];
            b->prova(v);
            mergesort(v,dim);

            int *h = new int[dim];
            for(int i=0; i<dim; i++) h[i] = v[i];

            int nuova_dim;
            nuova_dim = eliminaDuplicati(h,dim);

            for(int i=0; i<nuova_dim; i++){
                int counter=0;
                int m = i;
                for(int j = 0; j<dim; j++){
                    if(h[m]==v[j]) counter++;
                }
                out << counter << " ";
            }
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
            out << b->altezza() << " ";
            double v[dim];
            b->prova(v);
            mergesort(v,dim);

            double *h = new double[dim];
            for(int i=0; i<dim; i++) h[i] = v[i];

            int nuova_dim;
            nuova_dim = eliminaDuplicati(h,dim);

            for(int i=0; i<nuova_dim; i++){
                int counter=0;
                int m = i;
                for(int j = 0; j<dim; j++){
                    if(h[m]==v[j]) counter++;
                }
                out << counter << " ";
            }
        }
        out << endl;
    }
    in.close();
    out.close();

    return 0;
}
