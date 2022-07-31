/* Classe template BST
procedure: inserimento, cancellazione, altezza
*/
#include <iostream>
#include <fstream>
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

	void setKey(T key)				{this->key = new T(key);}
	void setLeft(Nodo<T>* left)		{this->left = left;}
	void setRight(Nodo<T>* right)	{this->right = right;}
	void setParent(Nodo<T>* parent)	{this->parent = parent;}

	T getKey()			{return *key;}
	Nodo<T>* getLeft()	{return left;}
	Nodo<T>* getRight()	{return right;}
	Nodo<T>* getParent(){return parent;}
};

template <class T> class BST{
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

	Nodo<T>* _successore(Nodo<T>* r){
		if(!r) return NULL;
		if(r->getRight())
			return _rmin(r->getRight());
		Nodo<T>* p = r->getParent();
		while(p && p->getKey() < r->getKey())
			p = p->getParent();
		return p;
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

    int _rprof(T key, Nodo<T>* x) {
        if(!x) return -1;
        if(x->getKey() == key) return 0;
        int p;
        if(key<x->getKey()) return p=_rprof(key, x->getLeft());
        else return p=_rprof(key, x->getRight());
        if(p>=0) return p+1;
        return -1;
    }

	int _altezza(Nodo<T>* x) { // O(NlogN) - O(N^2)
        Nodo<T>* tmp = _min(x); // si parte dal minimo del sottoalbero: O(N)
        int p = 0; // massimo temporaneo
        while(tmp!=NULL)  { // da verificare !!  O(N)
            int t = _prof(tmp->getKey(), x);    //O(N)
            if(t>p) p = t;
            tmp = _successore(tmp);             // O(N)
        }
        return p+1;
    }

    int _raltezza(Nodo<T>* r){
        if(!x) return 0;
        int i = _raltezza(x->getLeft()) +1;
        int j = _raltezza(x->getRight()) +1;
        return (i<j ? j : i);
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

	int search(T key){
         return (_rsearch(key, root)!=NULL);
    }

	int prof(T key) {
        return _prof(key, root);
    }

	int altezza(){
		return _altezza(root);
	}

	T* min(){
        return _rmin(root);
    }

	T* successore(T key){
		Nodo<T>* x = _search(key, root);
		if(x){
			Nodo<T>* y = _successore(x);
			if(y) return new T(key);
		}
		return NULL;
	}
};
//ins:25.7 ins:3.3 ins:7.8 ins:23.5 ins:2.6 ins:6.7 ins:7.9 ins:27.9 ins:27.2 ins:3.6
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
            out << b->altezza();
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
            out << b->altezza();
        }
        out << endl;
    }
    in.close();
    out.close();

    return 0;
}

