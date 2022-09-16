#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//ricerca il nodo all'interno del BST e va a contare i nodi del sottoalbero che hanno la chiave pari

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

    void _nodepreorder(Nodo<T>* r, int &c){
        if(!r) return;
        if(r->getKey()%2 == 0) c++;
        _nodepreorder(r->getLeft(), c);
        _nodepreorder(r->getRight(), c);
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

   

    int _nodeCount(Nodo<T>* x){
        if(!x) return 0;
        int c = 0;
        if((int)x->getKey()%2==0) c++;
        return _nodeCount(x->getLeft())+_nodeCount(x->getRight())+ c;
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

    int search(T key){
        return (_rsearch(key,root)!=NULL);
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

    int nodepreorder(T key){
        Nodo<T>* tmp = _rsearch(key,root);
        int c = 0;
        if(key%2 == 0) c = -1;
        _nodepreorder(tmp,c);
        return c;
    }

    int esame (T key){
        Nodo<T>* x = _rsearch(key,root);
        if(!x) return 0;
        return _nodeCount(x);
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
            int x = 0;
            in >> num;
            cout << b->nodepreorder(num);
            //if(num%2==0) x = -1; 
            //cout << b->esame(num) + x << endl;
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
            int x = 0;
            in >> num;
            if((int)num%2==0) x = -1; 
            cout << b->esame(num) + x << endl;
        }
        out << endl;
    }
    in.close();
    out.close();

    return 0;
}
