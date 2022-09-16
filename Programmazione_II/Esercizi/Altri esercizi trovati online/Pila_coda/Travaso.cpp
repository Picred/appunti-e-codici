#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <class T> class Queue{
private:
	int n, len, iterations, current;
	int head, tail;
	T** q;

public:
	Queue(int len){
		this->len = len;
		n = head = tail = 0;
		q = new T*[len];
	}

	Queue<T>& enqueue(T key){
		if(n<len){
			q[tail] = new T(key);
			tail++;
			if(tail==len) tail = 0;
			n++;
		}
		return *this;
	}

	T* dequeue(){
		if(n>0){
			T* tmp = q[head];
			head++;
			if(head==len) head = 0;
			n--;
			return tmp;
		}
		return NULL;
	}

	int isEmpty(){
		return (n==0);
	}

	void reset(){
		current = head;
		iterations = 0;
	}

	int hasNext(){
		return (iterations<n);
	}

	T* next(){
		if(!hasNext()) return NULL;
		T* tmp = q[current];
		current++;
		if(current==len) current = 0;
		iterations++;
		return tmp;
	}
};

template <class T> class Stack{
private:
	int n, len, top, current;
	T** s;

public:
	Stack(int len){
		this->len = len;
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

	//procedura travasa

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

	void travasa(Stack<T> *a, Queue<T> *b){
		while(!a->isEmpty()){
			T* tmp = a->pop();
			b->enqueue(*tmp);
		}
	}
};

template <class T>
ostream& operator <<(ostream& os, const Stack<T>& s){
	Stack<T> tmp = s;
	tmp.reset();

	while(tmp.hasNext())
		os << *(tmp.next()) << " ";
	return os;
}

template <class T>
ostream& operator <<(ostream& os, const Queue<T>& q){
	Queue<T> tmp = q;
	tmp.reset();
	while(tmp.hasNext())
		os << *(tmp.next()) << " ";
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
			Stack<bool> s(dim);
			Queue<bool> q(dim);
			char c;
			bool num;

			for(int j=0; j<dim; j++){
				in >> c;
				if(c=='e'){
					in >> c;
					in >> num;
					q.enqueue(num);
				}

				if(c=='p'){
					in >> c;
					if(c=='o'){
						in >> c;
						s.pop();
					}
					else{
						in >> num;
						s.push(num);
					}
				}
				if(c=='d'){
					for(int i=0; i<=5;i++) in >> c;
					q.dequeue();
				}

				if(c=='t'){
					for(int i=0; i<=5;i++) in >> c;
					s.travasa(&s, &q);
				}

			}
			out << q << " ";
		}

		if(type=="char"){
			Stack<char> s(dim);
			Queue<char> q(dim);
			char c;
			char num;

			for(int j=0; j<dim; j++){
				in >> c;
				if(c=='e'){
					in >> c;
					in >> num;
					q.enqueue(num);
				}

				if(c=='p'){
					in >> c;
					if(c=='o'){
						in >> c;
						s.pop();
					}
					else{
						in >> num;
						s.push(num);
					}
				}
				if(c=='d'){
					for(int i=0; i<=5;i++) in >> c;
					q.dequeue();
				}

				if(c=='t'){
					for(int i=0; i<=5;i++) in >> c;
					s.travasa(&s, &q);
				}
			}
			out << q << " ";
		}

		if(type=="int"){
			Stack<int> s(dim);
			Queue<int> q(dim);
			char c;
			int num;

			for(int j=0; j<dim; j++){
				in >> c;
				if(c=='e'){
					in >> c;
					in >> num;
					q.enqueue(num);
				}

				if(c=='p'){
					in >> c;
					if(c=='o'){
						in >> c;
						s.pop();
					}
					else{
						in >> num;
						s.push(num);
					}
				}
				if(c=='d'){
					for(int i=0; i<=5;i++) in >> c;
					q.dequeue();
				}

				if(c=='t'){
					for(int i=0; i<=5;i++) in >> c;
					s.travasa(&s, &q);
				}
			}
			out << q << " ";
		}

		if(type=="double"){
			Stack<double> s(dim);
			Queue<double> q(dim);
			char c;
			double num;

			for(int j=0; j<dim; j++){
				in >> c;
				if(c=='e'){
					in >> c;
					in >> num;
					q.enqueue(num);
				}

				if(c=='p'){
					in >> c;
					if(c=='o'){
						in >> c;
						s.pop();
					}
					else{
						in >> num;
						s.push(num);
					}
				}
				if(c=='d'){
					for(int i=0; i<=5;i++) in >> c;
					q.dequeue();
				}

				if(c=='t'){
					for(int i=0; i<=5;i++) in >> c;
					s.travasa(&s, &q);
				}
			}
			out << q << " ";
		}
		out << endl;
	}

	in.close();
	out.close();

	return 0;

}
