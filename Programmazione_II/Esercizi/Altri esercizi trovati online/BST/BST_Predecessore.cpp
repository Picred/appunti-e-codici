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

	Nodo<T>* _search(T key, Nodo<T>* r){
		Nodo<T>* tmp = r;
		while(tmp && tmp->getKey()!=key){
			if(key < tmp->getKey()) tmp = tmp->getLeft();
			else tmp = tmp->getRight();
		}
		return tmp;
	}

	Nodo<T>* _min(Nodo<T>* r){
		if(!r) return NULL;
		Nodo<T>* tmp = r;
		while(tmp->getLeft())
			tmp = tmp->getLeft();
		return tmp;
	}

	/*Nodo<T>* _rmin(Nodo<T>* r){
		if(!r) return NULL;
		if(!r->getLeft()) return r;
		return _rmin(r->getLeft());
	}*/

	Nodo<T>* _max(Nodo<T>* r){
		if(!r) return NULL;
		Nodo<T>* tmp = r;
		while(tmp->getRight()) tmp = tmp->getRight();
		return tmp;
	}

	/*Nodo<T>* _rmax(Nodo<T>* r){
		if(!r) return NULL;
		if(!r->getRight()) return r;
		return _rmax(r->getRight());
	}*/

	Nodo<T>* _predecessore(Nodo<T>* r){
		if(!r) return NULL;
		if(r->getLeft())
			return _max(r->getLeft());
		Nodo<T>* tmp = r->getParent();
		while(tmp && tmp->getKey() >= r->getKey())
			tmp = tmp->getParent();
		return tmp;
	}

	Nodo<T>* _successore(Nodo<T>* r){
		if(!r) return NULL;
		if(r->getRight())
			return _min(r->getRight());
		Nodo<T>* tmp = r->getParent();
		while(tmp && tmp->getKey() < r->getKey())
			tmp = tmp->getParent();
		return tmp;
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
		Nodo<T>* p = x->getParent();
		if(!p) root = z;
		else{
			if(p->getLeft()==x) p->setLeft(z);
			else p->setRight(z);
		}
		if(z) z->setParent(p);
		n--;
		return *this;
	}

	/*int search(T key){
		return (_search(key,root)!=NULL);
	}

	T* min(){
		return _min(root);
	}

	T* max(){
		return _max(root);
	}*/

	T predecessore(T key){
		Nodo<T>* tmp = _search(key, root);
		if(tmp){
			Nodo<T>* y = _predecessore(tmp);
			if(y) return T(y->getKey());				//da controllare
		}
		return -1;
	}

	/*T successore(T key){
		Nodo<T>* x = _search(key, root);
		if(x){
			Nodo<T>* y = _successore(x);
			if(y) return T(y->getKey());
		}
		return -1;
	}*/
};

//int 10 2 ins:276 ins:25 ins:131 ins:298 ins:239 ins:3 ins:265 ins:107 ins:221 ins:6 265 239
//              ^
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
				e = b->predecessore(num);
				out << e << " ";
			}
		}

		if(type=="double"){
			BST<double> *b = new BST<double>();
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
				e = b->predecessore(num);
				out << e << " ";
			}
		}
		out << endl;
	}
	in.close();
	out.close();

	return 0;
}