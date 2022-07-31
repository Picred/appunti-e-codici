/*
Si fornisca inoltre un metodo che
-presa in input una chiave K
sia in grado di individuare il nodo X contenente la chiave K 
e di calcolare il numero di chiavi la cui parte intera è pari contenute all'interno del sottoalbero radicato in X.
*/

#include <iostream>
#include <fstream>
using namespace std;

template <class T> class Nodo{
private:
	Nodo<T>* left, *right, *parent;
	T *key;

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

	Nodo<T>* _search(T key, Nodo<T>* r){
        if(!r) return NULL;
        if(r->getKey()==key) return r;
        if(key < r->getKey()) return _search(key, r->getLeft());
        else return _search(key, r->getRight());
    }

	void _inorder(ostream& os, Nodo<T>* r,int &c){
		if(!r) return;
		_inorder(os, r->getLeft(),c);
		if(int(r->getKey())%2 == 0){
			c++;
		}
		_inorder(os, r->getRight(),c);
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
		Nodo<T>* x = _search(key,root);
		if(!x) return *this;
		if(x->getLeft() && x->getRight()){
			Nodo<T>* y = _successore(x);
			x->setKey(y->getKey());
			y->setKey(key);
			x = y;
		}
		Nodo<T>* z = x->getLeft();
		if(!z) z = x->getRight();
		Nodo<T>* p = x->getParent();
		if(!p) root = z;
		else{
			if(x == p->getLeft()) p->setLeft(z);
			else p->setRight(z);
		}
		if(z) z->setParent(p);
		n--;
		return *this;
	}

	int inorder(ostream& os, T key){
		int c = 0;
		Nodo<T>* x = _search(key, root);
		Nodo<T>* r = x;
		_inorder(os,x,c);
		return c;
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
			out << b->inorder(out, num); 
           	
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
			out << b->inorder(out, num); 
        }
        out << endl;
    }
    in.close();
    out.close();

    return 0;
}
