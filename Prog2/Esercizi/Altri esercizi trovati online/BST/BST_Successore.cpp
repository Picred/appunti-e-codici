#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//cancellazione
template <class T> class Nodo{
private:
	T* key;
	Nodo<T>* left, *right, *parent;

public:
	Nodo(T key){
		this->key = new T(key);
		left = right = parent;
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
	Nodo<T>* root, *current;

	Nodo<T>* _search(T key, Nodo<T>* r){
		Nodo<T>* tmp = r;
		while(tmp && tmp->getKey()!=key){
			if(key < tmp->getKey()) tmp = tmp->getLeft();
			else tmp = tmp->getRight();
		}
		return tmp;
	}

	Nodo<T>* _rsearch(T key, Nodo<T>* r){
		if(!r) return NULL;
		if(r->getKey()==key) return r;
		if(key < r->getKey()) return _rsearch(key, r->getLeft());
		else return _rsearch(key, r->getRight());
	}

	Nodo<T>* _min(Nodo<T>* x){
		if(!x) return NULL;
		Nodo<T>* tmp = x;
		while(tmp->getLeft()) tmp = tmp->getLeft();
		return tmp;
	}

	Nodo<T>* _rmin(Nodo<T>* x){
		if(!x) return NULL;
		if(!x->getLeft()) return x;
		return _rmin(x->getLeft());
	}

	Nodo<T>* _successore(Nodo<T>* x){
		if(!x) return NULL;
		if(x->getRight()) return _min(x->getRight());
		Nodo<T>* tmp = x->getParent();
		while(tmp && tmp->getKey() < x->getKey())
			tmp = tmp->getParent();
		return tmp;
	}

	void _preorder(ostream& os, Nodo<T>* r){
		if(!r) return;
		os << r->getKey() << " ";
		_preorder(os, r->getLeft());
		_preorder(os, r->getRight());
	}

public:
	BST(){
		n = 0;
		root = current = NULL;
	}

	BST<T>& ins(T key){
		Nodo<T>* tmp = root;
		Nodo<T>* parent = NULL;
		Nodo<T>* x = new Nodo<T>(key);
		n++;
		while(tmp!=NULL){
			parent = tmp;
			if(key <= tmp->getKey())
				tmp = tmp->getLeft();
			else
				tmp = tmp->getRight();
		}
		if(parent == NULL){
			root = x;
			return *this;
		}
		if(key <= parent->getKey()) 
			parent->setLeft(x);
		else 
			parent->setRight(x);
		x->setParent(parent);
		return *this;
	}

    BST<T>& canc(T key) {
        Nodo<T> *x = _search(key, root);
        if(!x) return *this;
        if(x->getLeft() && x->getRight()) {
            Nodo<T> *y = _successore(x);
            T v = x->getKey();
            x->setKey(y->getKey());
            y->setKey(v);
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

	int search(T key){
		return (_search(key, root)!=NULL);
	}

	T* min(){
		Nodo<T>* tmp = _min(root);
		if(tmp) return new T(tmp->getKey());
		return NULL;
	}

	T successore(T key){
		Nodo<T>* tmp = _search(key, root);
		if(tmp){
			Nodo<T>* y = _successore(tmp);
			if(y) return T(y->getKey());
		}
		return -1;
	}

	void preorder(ostream& os){
		_preorder(os,root);
	}

	void reset(){
		current = _min(root);
	}

	int hasNext(){
		return (current!=NULL);	
	}

	T* next(){
		if(!hasNext()) return NULL;
		T* tmp = new T(current->getKey());
		current = _successore(current);
		return tmp;
	}
};

template <class T> 
ostream& operator <<(ostream& os, const BST<T> q){
	BST<T> tmp = q;
	tmp.preorder(os);
	return os;
}

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
			BST<int>* b = new BST<int>();
			char c;
			int num;
			int e;

			for(int i=0; i<dim; i++){
				in >> c;
				if(c=='i'){
					for(int k=0; k<3; k++) in >> c;
					in >> num;
					b->ins(num);	
				}
				else if(c=='c'){
					for(int k=0; k<4; k++) in >> c;
					in >> num;
					b->canc(num);
				}
			}
			for(int j=0; j<op; j++){
				in >> num;
				e = b->successore(num);
				out << e << " ";
			}
		}

		if(type=="double"){
			BST<double>* b = new BST<double>();
			char c;
			double num;
			double e;

			for(int i=0; i<dim; i++){
				in >> c;
				if(c=='i'){
					for(int k=0; k<3; k++) in >> c;
					in >> num;
					b->ins(num);	
				}
				else if(c=='c'){
					for(int k=0; k<4; k++) in >> c;
					in >> num;
					b->canc(num);
				}
			}
			for(int j=0; j<op; j++){
				in >> num;
				e = b->successore(num);
				out << e << " ";
			}
		}
		out << endl;
	}
	in.close();
	out.close();

	return 0;
}