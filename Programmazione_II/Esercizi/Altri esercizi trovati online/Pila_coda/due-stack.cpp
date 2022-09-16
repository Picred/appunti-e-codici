#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <class T> class Stack{
private:
	int n, len, top, current;
	T** s;

public:
	Stack(){
		len = 200;
		n = top = 0;
		s = new T*[len];
	}

	Stack<T>& push(T key){
		if(n<len){
			s[top] = new T(key);
			top++;
			n++;
		}
		return *this;
	}

	T* pop(){
		if(n>0){
			T* tmp = s[top-1];
			top--;
			n--;
			return tmp;
		}
		return NULL;
	}

	int isEmpty(){
		return (n==0);
	}

	int size(){
		return n;
	}

	void reset(){
		current = top-1;
	}

	int hasNext(){
		return (current>=0);
	}

	T* next(){
		if(!hasNext()) return NULL;
		T* tmp = s[current];
		current--;
		return tmp;
	}
};

template <class T> class Queue{
private:
	Stack<T>* s1, *s2, *s3;
	void _travasa(Stack<T>* a, Stack<T>* b){
		while(!a->isEmpty()){
			T* tmp = a->pop();
			b->push(*tmp);
		}
	}

public:
	Queue(){
		s1 = new Stack<T>();
		s2 = new Stack<T>();
		s3 = new Stack<T>();
	}

	Queue<T>& enqueue(T key){
		s1->push(key);
		return *this;
	}

//  0 1 1 0 1 0 1 

	T* dequeue(){
		if(isEmpty()) return NULL;
		if(s2->isEmpty()) _travasa(s1,s2);
		T* tmp = s2->pop();
		return tmp;
	}

	int isEmpty(){
		return (s2->isEmpty() && s1->isEmpty());
	}

	int size(){
		return (s2->size() + s1->size());
	}

	void reset(){
		while(!s3->isEmpty()) s3->pop();
		Stack<T>* c1 = new Stack<T>(*s1);
		Stack<T>* c2 = new Stack<T>(*s2);
		_travasa(c1,s3);
		_travasa(c2,c1); 
		_travasa(c1,s3);
		s3->reset();
	}

	int hasNext(){
		return s3->hasNext();
	}

	T* next(){
		return s3->next();
	}
};

template <class T>
ostream& operator <<(ostream& os, const Queue<T>& q){
	Queue<T> tmp = q;
	tmp.reset();
	while(tmp.hasNext()){
	 	T *e = tmp.next();
		os << *e << " ";
	}
	return os;
}

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");

	string type;
	while(in >> type){
		int dim;
		in >> dim;

		if(type=="bool"){
			Queue<bool> car;
			char c;
			bool num;
			for(int i=0; i<dim; i++){
				in >> c;
				if(c=='i'){
					in >> num;
					car.enqueue(num);
				}
				else{
					car.dequeue();
					for(int i=0; i<6; i++) in >> c;
				}
			}
			out << car;
		}

		if(type=="char"){
			Queue<char> car;
			char c;
			char num;
			for(int i=0; i<dim; i++){
				in >> c;
				if(c=='i'){
					in >> num;
					car.enqueue(num);
				}
				else{
					car.dequeue();
					for(int i=0; i<6; i++) in >> c;
				}
			}
			out << car;
		}

		if(type=="int"){
			Queue<int> bl;
			char c;
			int num;
			for(int i=0; i<dim; i++){
				in >> c;
				if(c=='i'){
					in >> num;
					bl.enqueue(num);
				}
				else{
					bl.dequeue();
					for(int i=0; i<6; i++) in >> c;
				}
			}
			out << bl;
		}

		if(type=="double"){
			Queue<double> bl;
			char c;
			double num;
			for(int i=0; i<dim; i++){
				in >> c;
				if(c=='i'){
					in >> num;
					bl.enqueue(num);
				}
				else{
					bl.dequeue();
					for(int i=0; i<6; i++) in >> c;
				}
			}
			out << bl;
		}
		out << endl;
	}
	in.close();
	out.close();

	return 0;
}