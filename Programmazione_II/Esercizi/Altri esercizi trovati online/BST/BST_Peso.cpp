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
		left  = right = parent = NULL;
	}

	void setKey(T key)			   {this->key = new T(key);}
	void setLeft(Nodo<T>* left)	   {this->left = left;}
	void setRight(Nodo<T>* right)  {this->right = right;}
	void setParent(Nodo<T>* parent){this->parent = parent;}

	T getKey()			{return *key;}
	Nodo<T>* getLeft()	{return left;}
	Nodo<T>* getRight()	{return right;}
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

	Nodo<T>* _search(T key, Nodo<T>* r){
		Nodo<T>* tmp = r;
		while(tmp && tmp->getKey()!=key){
			if(key < tmp->getKey()) tmp = tmp->getLeft();
			else tmp = tmp->getRight();
		}
		return tmp;
	}

	Nodo<T>* _rmin(Nodo<T>* r){
		if(!r) return NULL;
		if(!r->getLeft()) return r;
		return _rmin(r->getLeft());
	}

	Nodo<T>* _min(Nodo<T>* x){
		if(!x) return NULL;
		Nodo<T>* tmp = x;
		while(tmp->getLeft()) tmp = tmp->getLeft();
		return tmp;
	}

	Nodo<T>* _successore(Nodo<T>* x){
		if(!x) return NULL;
		if(x->getRight()) return _min(x->getRight());
		Nodo<T>* tmp = x->getParent();
		while(tmp && tmp->getKey() < x->getKey())
			tmp = tmp->getParent();
		return tmp;
	}

	T _peso(Nodo<T>* x){
		if(!x) return 0;
		return x->getKey()+ _peso(x->getLeft())+ _peso(x->getRight());
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

	BST<T> canc(T key){
		Nodo<T>* x = _search(key, root);
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
		return (_search(key, root)!=NULL);
	}

	T* min(){
		return _min(root);
	}

	T* successore(T key){
		Nodo<T>* x = new Nodo<T>(key);
		if(x){
			Nodo<T>* y = _successore(x);
			if(y) return new T(y->getKey());
		}
		return NULL;
	}

	T peso(T key){
		Nodo<T>* x = _search(key, root);
		if(x){
			T y = _peso(x);
			if(y) return y;
		} 
		return 0;
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
			BST<int> *bl = new BST<int>();
			char c;
			int num;
			for(int j=0; j<dim; j++){
				in >> c;
				if(c=='i'){
					for(int k=0; k<=2; k++) in >> c;
					in >> num;
					bl->ins(num);
				}
				else if(c=='c'){
					for(int k=0; k<=3; k++) in >> c;
					in >> num;
					bl->canc(num);
				}
			}
			in >> num;
			out << bl->peso(num);
		}

		if(type=="double"){
			BST<double> *bl = new BST<double>();
			char c;
			double num;
			for(int j=0; j<dim; j++){
				in >> c;
				if(c=='i'){
					for(int k=0; k<=2; k++) in >> c;
					in >> num;
					bl->ins(num);
				}
				else if(c=='c'){
					for(int k=0; k<=3; k++) in >> c;
					in >> num;
					bl->canc(num);
				}
			}
			in >> num;
			out << bl->peso(num);
		
		}
		out << endl;
	}
	in.close();
	out.close();

	return 0;
}