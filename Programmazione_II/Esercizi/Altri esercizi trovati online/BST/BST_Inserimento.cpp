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
		left = right = parent = NULL;
	}

	void setKey(T key){this->key = new T(key);}
	void setLeft(Nodo<T>* left){this->left = left;}
	void setRight(Nodo<T>* right){this->right = right;}
	void setParent(Nodo<T>* parent){this->parent = parent;}

	T getKey(){return *key;}
	Nodo<T>* getLeft(){return left;}
	Nodo<T>* getRight(){return right;}
	Nodo<T>* getParent(){return parent;}
};

template <class T> class BST{
private:
	int n;
	Nodo<T>* root;

	void _preorder(ostream& os, Nodo<T>* x){
		if(!x) return;
		os << x->getKey() << " ";
		_preorder(os, x->getLeft());
		_preorder(os, x->getRight());
	}

	void _inorder(ostream& os, Nodo<T>* x){
		if(!x) return;
		_inorder(os, x->getLeft());
		os << x->getKey() << " ";
		_inorder(os, x->getRight());
	}

	void _postorder(ostream& os, Nodo<T>* x){
		if(!x) return;
		_postorder(os, x->getLeft());
		_postorder(os, x->getRight());
		os << x->getKey() << " ";
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
		if(key <= parent->getKey()) 
			parent->setLeft(x);
		else parent->setRight(x);
		x->setParent(parent);
		return *this;
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

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");

	string type;
	while(in >> type){
		int dim;
		in >> dim;
		string visit;
		in >> visit;

		if(type=="char"){
			BST<char> b;
			char num;
			for(int i=0; i<dim;i++){
				in >> num;
				b.ins(num);
			}
			if(visit=="preorder"){
				b.preorder(out);
			}
			if(visit=="inorder"){
				b.inorder(out);
			}
			if(visit=="postorder"){
				b.postorder(out);
			}
		}

		if(type=="bool"){
			BST<bool> b;
			bool num;
			for(int i=0; i<dim;i++){
				in >> num;
				b.ins(num);
			}
			if(visit=="preorder"){
				b.preorder(out);
			}
			if(visit=="inorder"){
				b.inorder(out);
			}
			if(visit=="postorder"){
				b.postorder(out);
			}
		}

		if(type=="int"){
			BST<int> b;
			int num;
			for(int i=0; i<dim;i++){
				in >> num;
				b.ins(num);
			}
			if(visit=="preorder"){
				b.preorder(out);
			}
			if(visit=="inorder"){
				b.inorder(out);
			}
			if(visit=="postorder"){
				b.postorder(out);
			}
		}

		if(type=="double"){
			BST<double> b;
			double num;
			for(int i=0; i<dim;i++){
				in >> num;
				b.ins(num);
			}
			if(visit=="preorder"){
				b.preorder(out);
			}
			if(visit=="inorder"){
				b.inorder(out);
			}
			if(visit=="postorder"){
				b.postorder(out);
			}
		}
		out << endl;
	}
	in.close();
	out.close();

	return 0;
}
