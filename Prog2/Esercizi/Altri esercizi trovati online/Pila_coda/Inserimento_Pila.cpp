#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <class T> class Stack {
	
private:
	int n, len, current;
	int top;
	T** s;
		
public:	
	Stack()	{ 
		n = 0; 
		len = 200; 
		s = new T*[len]; 
		top = 0; 
	}
		
	Stack<T>& push(T key) { 
        if(n++ < len) 
			s[top++] = new T(key); 
				
        return *this;
    }
    	
	T* pop() { 
        if(n-- >0) {
	        T* tmp = s[top-1];
	        top--;
	        return tmp;
	    }
	    return NULL;
    }
		
	void reset() {current = top-1;}
    
    int hasNext() {return (current >= 0);}
    
    T* next() {
        if(hasNext()) {
	        T* tmp = s[current--];
	        return tmp;
       	}
        return NULL;
    }
};
    
ostream& operator<<(ostream& os, const Stack<bool>& s) {
	Stack<bool> tmp = s;
	tmp.reset();
	while(tmp.hasNext()) {
	    bool* e = tmp.next();
	    os << *e << " ";
	}
	return  os;
}
    
ostream& operator<<(ostream& os, const Stack<char>& s) {
	Stack<char> tmp = s;
    tmp.reset();
    while(tmp.hasNext()) {
	    char* e = tmp.next();
	    os << *e << " ";
	}
	return  os;
}
	
ostream& operator<<(ostream& os, const Stack<int>& s) {
	Stack<int> tmp = s;
	tmp.reset();
	while(tmp.hasNext()) {
	    int* e = tmp.next();
	    os << *e << " ";
	}
	return  os;
}
	
ostream& operator<<(ostream& os, const Stack<double>& s) {
	Stack<double> tmp = s;
	tmp.reset();
	while(tmp.hasNext()) {
	    double* e = tmp.next();
	    os << *e << " ";
	}
	return  os;
}


int main (){
	ifstream in  ("input.txt");
	ofstream out ("output.txt");

	string type;
	while ( in >> type){		
		
		int dim;
		in>>dim;
		
		if(type == "bool"){
			Stack<bool>* s = new Stack<bool>();
			for(int i = 0; i < dim; i++){
				bool x;
				in >> x;
				s->push(x);
			}
			out << *s << endl;
		}
		
		if(type == "char"){
			Stack<char>* s = new Stack<char>();
			for(int i = 0; i < dim; i++){
				char x;
				in >> x;
				s->push(x);
			}
			out << *s << endl;
		}
		
		if(type == "int"){
			Stack<int>* s = new Stack<int>();
			for(int i = 0; i < dim; i++){
				int x;
				in >> x;
				s->push(x);
			}
			out << *s << endl;
		}
		
		if(type == "double"){
			Stack<double>* s = new Stack<double>();
			for(int i = 0; i < dim; i++){
				double x;
				in >> x;
				s->push(x);
			}
			out << *s << endl;
		}

	}
	in.close();
	out.close();
}
