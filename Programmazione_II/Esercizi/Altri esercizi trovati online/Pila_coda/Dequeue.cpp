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
		n = iterations = 0;
		head = tail = 0;
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
			Queue<bool> bl(dim); 
			char c;
			bool num;
			for(int i=0; i<dim; i++){
				in >> c;
				if(c=='i'){
					in >> num;
					bl.enqueue(num);
				}
				else{
					bl.dequeue();
					for(int j=0; j<6; j++) in >> c;
				}
			}
			out << bl;
		}

		if(type=="char"){
			Queue<char> car(dim); 
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
					for(int j=0; j<6; j++) in >> c;
				}
			}
			out << car;
		}

		if(type=="int"){
			Queue<int> i(dim); 
			char c;
			int num;
			for(int j=0; j<dim; j++){
				in >> c;
				if(c=='i'){
					in >> num;
					i.enqueue(num);
				}
				else{
					i.dequeue();
					for(int j=0; j<6; j++) in >> c;
				}
			}
			out << i;
		}

		if(type=="double"){
			Queue<double> d(dim); 
			char c;
			double num;
			for(int j=0; j<dim; j++){
				in >> c;
				if(c=='i'){
					in >> num;
					d.enqueue(num);
				}
				else{
					d.dequeue();
					for(int j=0; j<6; j++) in >> c;
				}
			}
			out << d;
		}
		out << endl;
	}
	in.close();
	out.close();

	return 0;
}
