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
		if(!r) return NULL;
		Nodo<T>* tmp = r;
		while(tmp && tmp->getKey()!=key){
			if(key < tmp->getKey()) tmp = tmp->getLeft();
			else tmp = tmp->getRight();
		}
		if(!tmp) return NULL;
		return tmp;
	}

	Nodo<T>* _rsearch(Nodo<T>* r, T key){
		if(!r) return NULL;
		if(r->getKey()==key) return r;
		if(key < r->getKey()) return _rsearch(r->getLeft(),key);
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

	Nodo<T>* _max(Nodo<T>* r){
		if(!r) return NULL;
		Nodo<T>* tmp = r;
		while(tmp->getRight()) tmp = tmp->getRight();
		return tmp;
	}

	Nodo<T>* _rmax(Nodo<T>* r){
		if(!r) return NULL;
		if(!r->getRight()) return r;
		return _rmax(r->getRight());
	}

	Nodo<T>* _predecessore(Nodo<T>* r){
		if(!r) return NULL;
		if(r->getLeft()) return _rmax(r->getLeft());
		Nodo<T>* tmp = r->getParent();
		while(tmp && tmp->getKey() > r->getKey()) tmp = tmp->getParent();
		return tmp;
	}

	Nodo<T>* _successore(Nodo<T>* r){
		if(!r) return NULL;
		if(r->getRight()) return _rmin(r->getRight());
		Nodo<T>* tmp = r->getParent();
		while(tmp && tmp->getKey() <= r->getKey()) tmp = tmp->getParent();
		return tmp;
	}

	//Cammino radice-nodo
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

	//Cammino nodo-radice
	int _rprof(Nodo<T>*r){
		if(!r->getParent()) return 0;
		return _rprof(r->getParent())+1;
	}

	int _altezza(Nodo<T>* x) { 
        Nodo<T>* tmp = _min(x);
        int p = 0; 
        while(tmp!=NULL)  { 
            int t = _prof(x, tmp->getKey());    
            if(p<t) p = t;
            tmp = _successore(tmp);            
        }
        return p;
  	}

	int _raltezza(Nodo<T>* x){
		if(!x) return -1;
		int i = _raltezza(x->getLeft())+1;
		int j = _raltezza(x->getRight())+1;
		return (i < j ? j : i);
	}

	//Calcolo Foglie dell'albero
	int _leafCount(Nodo<T>* x) {
    	if(!x) return 0;
        if(!x->getLeft() && !x->getRight()) return 1;
        return _leafCount(x->getLeft()) + _leafCount(x->getRight());
    }

    int _nodeCount(Nodo<T>* x) {
        if(!x) return 0;
        return 1+_nodeCount(x->getLeft())+_nodeCount(x->getRight());
    }

    //passandogli la root
    int _rootbilanciamento(Nodo<T>* x) {
        if(!x) return 0;
        int nleft = _nodeCount(x->getLeft());
        int nright = _nodeCount(x->getRight());
        int v = nleft-nright;
        if(v<0) v=v*(-1);
        return v;
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
		else if(x == p->getLeft())
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

	T* max(){
		Nodo<T>* x = _rmax(root);
		if(x) return new T(x->getKey());
		return NULL;
	}

	T* predecessore(T key){
		Nodo<T>* x = _rsearch(root,key);
		if(x){
			Nodo<T>* y = _predecessore(x);
			if(y) return new T(y->getKey());
		}
		return NULL;
	}

	T* successore(T key){
		Nodo<T>* x = _rsearch(root,key);
		if(x){
			Nodo<T>* y = _successore(x);
			if(y) return new T(y->getKey());
		}
		return NULL;
	}

	int search(T key){
		return (_rsearch(root,key)!=NULL);
	}

	int prof(T key){
		return _prof(root,key);
	}

	int rprof(T key){
		Nodo<T>* x = _rsearch(root,key);
		if(x){
			int y = _rprof(x);
			return y;
		}
		return -1;
	}

	int altezza(){
		return _altezza(root);
	}

	int raltezza(){
		return _raltezza(root);
	}

    int leafCount() {
        return _leafCount(root);
    }

    int nodeCount() {
        return _nodeCount(root);
    }

    //Ti dice quanti nodi "possibilmente partendo dalla radice" ci sono in più
    int bilanciamento(T key) {
        Nodo<T>* x = _search(root, key);
        int nleft = _nodeCount(x->getLeft());
        int nright = _nodeCount(x->getRight());
        int v = nleft-nright;
        if(v<0) v=v*(-1);
        return v;
    }

   	int rootbilanciamento(){
   		return _rootbilanciamento(root);
   	}

	void preorder(ostream& os){
		_preorder(os,root);
	}

	void inorder(ostream& os){
		_inorder(os,root);
	}

	void postorder(ostream& os){
		_postorder(os,root);
	}

};

/*
Il livello di nodo in un BST corrisponde al 
numero di nodi presenti nel cammino che separano nodo-radice, escludendo il nodo stesso. 
*/

//int 10 2 ins:158 ins:272 ins:278 ins:109 ins:65 ins:242 ins:203 ins:229 ins:112 ins:169 272 158
//       ^
int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");

	string type;
	while(in >> type){
		int n;
		in >> n;
		int op;
		in >> op;

		if(type == "int"){
			BST<int> tree;
			int num;
			char c;
			for(int i=0; i<n; i++){
				in >> c;
				if(c == 'i'){
					for(int i=0; i<3;i++) in >> c;
					in >> num;
					tree.ins(num);
				}
				else if(c == 'c'){
					for(int i=0; i<4; i++) in >> c;
					in >> num;
					tree.canc(num);
				}
			}
			for(int j=0; j<op; j++){
				in >> num;
				out << tree.rprof(num) << " ";
			}
		}

		if(type == "double"){
			BST<double> tree;
			double num;
			char c;
			for(int i=0; i<n; i++){
				in >> c;
				if(c == 'i'){
					for(int i=0; i<3;i++) in >> c;
					in >> num;
					tree.ins(num);
				}
				else if(c == 'c'){
					for(int i=0; i<4; i++) in >> c;
					in >> num;
					tree.canc(num);
				}
			}
			for(int j=0; j<op; j++){
				double num;
				in >> num;
				out << tree.prof(num) << " ";
			}
		}
		out << endl;
	}
	in.close();
	out.close();

	return 0;
}