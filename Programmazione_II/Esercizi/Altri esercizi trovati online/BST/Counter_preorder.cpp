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

	T getKey()				{return *key;}
	Nodo<T>* getLeft()		{return left;}
	Nodo<T>* getRight()		{return right;}
	Nodo<T>* getParent()	{return parent;}
};

template <class T> class BST{
private:
	int n;
	Nodo<T>* root;

	Nodo<T>* _search(Nodo<T>* r, T key){
		Nodo<T>* tmp = r;
		while(tmp && tmp->getKey()!=key){
			if(key <= tmp->getKey()) tmp = tmp->getLeft();
			else tmp = tmp->getRight();
		}
		return tmp;
	}

	Nodo<T>* _rsearch(Nodo<T>* r, T key){
		if(!r) return NULL;
		if(r->getKey()==key) return r;
		if(key <= r->getKey()) return _rsearch(r->getLeft(),key);
		else return _rsearch(r->getRight(),key);
	}

	Nodo<T>* _min(Nodo<T>* r){
		if(!r) return NULL;
		Nodo<T>* tmp = r;
		while(tmp->getLeft()) tmp = tmp->getLeft();
		return tmp;
	}

	Nodo<T>* _rmin(Nodo<T>* r){
		if(!r) return r;
		if(!r->getLeft()) return r;
		return _rmin(r->getLeft());
	}

	Nodo<T>* _successore(Nodo<T>* r){
		if(!r) return NULL;
		if(r->getRight()) return _rmin(r->getRight());
		Nodo<T>* tmp = r->getParent();
		while(tmp && tmp->getKey() < r->getKey()) tmp = tmp->getParent();
		return tmp;
	}

	void _preorder(ostream& os, Nodo<T>* r,T key, int *counter){
		if(!r) return;
		if(r->getKey()==key){ 
			os << *counter << endl;
			return;
		}
		(*counter)++;
		_preorder(os, r->getLeft(), key,counter);
		_preorder(os, r->getRight(), key,counter);
	}

public:
	BST(){
		n = 0;
		root = NULL;
	}

	BST<T>& ins(T key){
		Nodo<T>* tmp = root;
		Nodo<T>* p = NULL;
		Nodo<T>* x = new Nodo<T>(key);
		while(tmp){
			p = tmp;
			if(key <= tmp->getKey()) tmp = tmp->getLeft();
			else tmp = tmp->getRight();
		}
		if(!p){
			root = x;
			return *this;}
		else if(key <= p->getKey()) p->setLeft(x);
		else p->setRight(x);
		x->setParent(p);
		return *this;
	}

	BST<T>& canc(T key){
		Nodo<T>* x = _rsearch(root,key);
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
		else if(p->getLeft()==x)
			p->setLeft(z);
			else p->setRight(z);
		if(z) z->setParent(p);
		n--;
		return *this;
	}

	T* min(){
		Nodo<T>* x = _rmin(root);
		if(x) return new T(x->getKey());
		return NULL;
	}

	T successore(T key){
		Nodo<T>* x = _rsearch(root,key);
		if(x){
			Nodo<T>* y = _successore(x);
			if(y) return(y->getKey());
		}
		return 0;
	}

	int search(T key){
		return (_rsearch(root,key)!=NULL);
	}

	void preorder(ostream& os, T key){
		Nodo<T>* x = _search(root, key);
        if (x == NULL) return;
        int* counter = new int(0);
        _preorder(os, root, key, counter);
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
            int j;
            in >> j;
         	b->preorder(out,j);
        }
        out << endl;
    }
    in.close();
    out.close();

    return 0;
}