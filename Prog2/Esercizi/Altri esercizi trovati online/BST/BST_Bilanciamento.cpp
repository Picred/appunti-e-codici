#include <iostream>
#include <fstream>
using namespace std;

template <class T> class Nodo{
private:
	T* key;								//chiave
	Nodo<T>* left, *right, *parent;		//nodi

public:
	Nodo(T key){
		this->key = new T(key);
		left = right = parent = NULL;
	}
	//procedure set
	void setKey(T key)				{this->key = new T(key);}
	void setLeft(Nodo<T>* left)		{this->left = left;}
	void setRight(Nodo<T>* right)	{this->right = right;}
	void setParent(Nodo<T>* parent) {this->parent = parent;}
	//procedure get
	T getKey()			{return *key;}
	Nodo<T>* getLeft()	{return left;}
	Nodo<T>* getRight()	{return right;}
	Nodo<T>* getParent(){return parent;}
};

template <class T> class BST{
private:
	int n;				//numero di elementi
	Nodo<T>* root; 		//nodo radice

	Nodo<T>* _search(T key, Nodo<T>* r){		//search iterativa
		if(!r) return NULL;
		Nodo<T>* tmp = r;
		while(tmp && tmp->getKey() != key){
			if(key < tmp->getKey()) tmp = tmp->getLeft();
			else tmp = tmp->getRight();
		}
		return tmp;
	}

	Nodo<T>* _rsearch(T key, Nodo<T>* r){		//search ausiliaria ricorsiva
		if(!r) return NULL;
		if(r->getKey()==key) return r;
		if(key < r->getKey()) return _rsearch(key, r->getLeft());
		else return _rsearch(key, r->getRight());
	}

	Nodo<T>* _min(Nodo<T>* r){					//minimo iterativo
		if(!r) return NULL;
		Nodo<T>* tmp = r;
		while(tmp && tmp->getLeft()) 
			tmp = tmp->getLeft();
		return tmp;
	}

	Nodo<T>* _rmin(Nodo<T>* r){					//minimo ricorsivo
		if(!r) return NULL;
		if(!r->getLeft()) return r;
		return _rmin(r->getLeft());
	}

	int _NodiLeft(Nodo<T>* r){					//minimo iterativo
		if(!r) return 0;
		int c = 0;
		Nodo<T>* tmp = r;
		while(tmp && tmp->getLeft()){ 
			tmp = tmp->getLeft();
			c++;
		}
		return c;
	}

	int _NodiRight(Nodo<T>* r){					//minimo iterativo
		if(!r) return 0;
		int c = 0;
		Nodo<T>* tmp = r;
		while(tmp && tmp->getRight()){ 
			tmp = tmp->getRight();
			c++;
		}
		return c;
	}

	Nodo<T>* _successore(Nodo<T>* r){
		if(!r) return NULL;
		if(r->getRight()) 
			return _rmin(r->getRight());
		Nodo<T>* parent = r->getParent();
		while(parent && parent->getKey() < r->getKey())
			parent = parent->getParent();
		return parent;
	}

public:
	BST(){
		n = 0;
		root = NULL;
	}

	BST<T>& ins(T key){
		Nodo<T>* tmp = root;			//nodo radice
		Nodo<T>* parent = NULL;			//nodo parent
		Nodo<T>* x = new Nodo<T>(key);	//chiave da inserire
		n++;							//aumento il numero di elementi adesso sennò dopo sballa
		while(tmp){ 
			parent = tmp;				
			if(key <= tmp->getKey()) tmp = tmp->getLeft();
			else tmp = tmp->getRight(); 
		}
		if(!parent){					//setti parent		
			root = x;
			return *this;
		}
		else{
			if(key <= parent->getKey()) parent->setLeft(x);
			else parent->setRight(x);
		}							
		x->setParent(parent);			//setti la chiave
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
		if(parent->getLeft()==x) parent->setLeft(z);
		else parent->setRight(z);
		if(z) z->setParent(parent);
		n--;
		return *this;
	}

	int search(T key){
		return (_rsearch(key,root)!=NULL);
	}

	T* min(){
		return _rmin(root);
	}

	T* successore(T key){
		Nodo<T>* x = _rsearch(key, root);
		if(x){
			Nodo<T>* y = _successore(x);
			if(y) return new T(y);
		}
		return NULL;
	}

	int balance(T key){
		Nodo<T>* tmp = _rsearch(key, root);
		if(!tmp) return 0;
		int left = _NodiLeft(tmp);
		int right = _NodiRight(tmp);
		int risultato = 0;
		if(left > right)
			risultato = left - right;
		else risultato = right - left;
		return risultato;
	}
};

//int 10 ins:191 ins:262 ins:197 ins:188 ins:273 ins:4 ins:0 ins:260 ins:147 ins:130 147
//           ^

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");

	string type;

	while(in >> type){
		int n;
		in >> n;

		if(type=="int"){
			BST<int>* tree = new BST<int>();
			char c;
			int num;
			for(int i=0; i<n; i++){
				in >> c;
				if(c=='i'){
					for(int count=0; count<=2; count++) in >> c;
					in >> num;
					tree->ins(num);
				}else{
					for(int count=0; count<=3; count++) in >> c;
					in >> num;
					tree->canc(num);
				}
			}
			in >> num;
			out << tree->balance(num);
		}
		out << endl;
	}
	in.close();
	out.close();

	return 0;
}