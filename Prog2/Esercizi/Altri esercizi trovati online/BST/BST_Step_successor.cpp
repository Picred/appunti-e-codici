/*
una funzione che sia in grado di restituire 
il numero di archi che separano il nodo contenente la chiave successore dal nodo contenente una specifica chiave fornita in input.
*/

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

    int step(T key){
        int c = 1;
        Nodo<T>* r = _rsearch(key,root);
        if(!r) return 0;
        if(!_successore(r)) return -1;
        if(r->getRight()){
            Nodo<T>* tmp = r->getRight();
            while(tmp->getLeft()){
                tmp = tmp->getLeft();
                c++;
            }
            return c;
        }
        Nodo<T>* p = r->getParent();
        while(p && p->getKey() < r->getKey()){
            p = p->getParent();
            c++;
        }
        return c;
    }

};

/*
int 10 2 ins:158 ins:272 ins:278 ins:109 ins:65 ins:242 ins:203 ins:229 ins:112 ins:169 272 158
int 10 2 ins:204 ins:131 ins:75 ins:98 ins:199 ins:212 ins:157 ins:208 ins:168 ins:130 208 131
int 10 2 ins:175 ins:180 ins:223 ins:160 ins:45 ins:225 ins:56 ins:297 ins:204 ins:150 297 150                                                                      ^
*/

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    string type;
    while(in >> type){
        int dim;
        in >> dim;
        int op;
        in >> op;

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
        for(int i=0; i<op; i++){
            in >> num;
            if(b->step(num) == -1) out << "INF" << " ";
            else out << b->step(num) << " ";
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
            for(int i=0; i<op; i++){
            in >> num;
            if(b->step(num) == -1) out << "INF" << " ";
            else out << b->step(num) << " ";
        }
        }
        out << endl;
    }
    in.close();
    out.close();

    return 0;
}
