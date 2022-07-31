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

	Nodo<T>* _min(Nodo<T>* r){
		if(!r) return NULL;
		Nodo<T>* tmp = r;
		while(tmp->getLeft()) tmp = tmp->getLeft();
		return tmp;
	}

	Nodo<T>* _rmin(Nodo<T>* r){
		if(!r) return NULL;
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

	Nodo<T>* _predecessore(Nodo<T>* x){
		if(!x) return NULL;
		if(x->getLeft()) return _max(x->getLeft());
		Nodo<T>* p = x->getParent();
		while(p && p->getKey() > x->getKey()) p = p->getParent();
		return p;
	}

	Nodo<T>* _successore(Nodo<T>* x){
		if(!x) return NULL;
		if(x->getRight()) return _min(x->getRight());
		Nodo<T>* p = x->getParent();
		while(p && p->getKey() < x->getKey()) p = p->getParent();
		return p;
	}

	int _prof(T key, Nodo<T>* r){
		if(!r) return -1;
		Nodo<T>* tmp = r;
		int p = 0;
		while(tmp && tmp->getKey()!=key){
			if(key < tmp->getKey()) tmp = tmp->getLeft();
			else tmp = tmp->getRight();
			p++;
		}
		return p;
	}

	int _prof2(Nodo<T>* r){
		if(!r) return -1;
		Nodo<T>* tmp = r;
		int p = 0;
		while(tmp && tmp!=root){
			tmp = tmp->getParent();
			p++;
		}
		return p;
	}

	int _rprof(Nodo<T>* r){
		if(!r->getParent()) return 0;
		return _rprof(r->getParent())+1;
	}

	int _altezza(Nodo<T>* r){
		if(!r) return -1;
		Nodo<T>* tmp = _min(root);
		int p = 0;
		while(tmp){
			int t = _prof(tmp->getKey(),r);
			if(p<t) p = t;
			tmp = _successore(tmp);
		}
		return p;
	}

	int _raltezza(Nodo<T>* r){
		if(!r) return -1;
		int i = _raltezza(r->getLeft())+1;
		int j = _raltezza(r->getRight())+1;
		return i < j ? j : i;
	}

	int _leafCount(Nodo<T>* x){
		if(!x) return 0;
		if(!x->getLeft() && !x->getRight()) return 1;
		return _leafCount(x->getLeft()) + _leafCount(x->getRight());
	}

	int _nodeCount(Nodo<T>* x){
		if(!x) return 0;
		return 1+_nodeCount(x->getLeft())+_nodeCount(x->getRight());
	}

	int _rootBilanciamento(Nodo<T>* x){
		if(!x) return 0;
		int nleft = _nodeCount(x->getLeft());
		int nright = _nodeCount(x->getRight());
		int v = nleft-nright;
		if(v<0) v = v*(-1);
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
		n++;
		while(tmp){
			p = tmp;
			if(key <= tmp->getKey()) tmp = tmp->getLeft();
			else tmp = tmp->getRight();
		}
		if(!p){
			root = x;
			return *this;
		}
		else{
			if(x->getKey() <= p->getKey()) p->setLeft(x);
			else p->setRight(x);
		}
		x->setParent(p);
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
			if(p->getLeft()==x) p->setLeft(z);
			else p->setRight(z);
		}
		if(z) z->setParent(p);
		n--;
		return *this;
	}

	int search(T key){
		return (_search(key,root)!=NULL);
	}

	int rsearch(T key){
		return (_rsearch(key,root)!=NULL);
	}

	int prof(T key){
		return _prof(key,root);
	}

	int prof2(T key){
		Nodo<T>* x = _search(key,root);
		if(x) return _prof2(x);
		return -1;
	}

	int rprof(T key){
		Nodo<T>* x = _search(key, root);
		if(x) return _rprof(x);
		return -1;
	}

	int altezza(){
		return _altezza(root);
	}

	int raltezza(){
		return _raltezza(root);
	}

	int leafCount(){
		return _leafCount(root);
	}

	int nodeCount(){
		return _nodeCount(root);
	}

	int bilanciamento(T key){
		Nodo<T>* x = _search(key,root);
		int nleft = _nodeCount(x->getLeft());
		int nright = _nodeCount(x->getRight());
		int v = nleft-nright;
		if(v<0) v = v*(-1);
		return v;
	}

	int rootbilanciamento(){
		return _rootBilanciamento(root);
	}

	T min(){
		Nodo<T>* x = _min(root);
		if(x) return x->getKey();
		else return -1;
	}

	T rmin(){
		Nodo<T>* x = _rmin(root);
		if(x) return x->getKey();
		else return -1;
	}

	T max(){
		Nodo<T>* x = _max(root);
		if(x) return x->getKey();
		else return -1;
	}

	T rmax(){
		Nodo<T>* x = _rmax(root);
		if(x) return x->getKey();
		else return -1;
	}

	T predecessore(T key){
		Nodo<T>* x = _search(key,root);
		if(x){
			Nodo<T>* y = _predecessore(x);
			if(y) return y->getKey();
		}
		return -1;
	}

	T successore(T key){
		Nodo<T>* x = _search(key,root);
		if(x){
			Nodo<T>* y = _successore(x);
			if(y) return y->getKey();
		}
		return -1;
	}

	void preorder(ostream& os){
		_preorder(os, root);
	}

	void inorder(ostream& os){
		_inorder(os, root);
	}

	void postorder(ostream& os){
		_postorder(os, root);
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
            int d;
            in >> d;
            out << b->prof(d);
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
            double d;
            in >> d;
            out << b->prof(d);
        }
        out << endl;
    }
    in.close();
    out.close();

    return 0;
}

