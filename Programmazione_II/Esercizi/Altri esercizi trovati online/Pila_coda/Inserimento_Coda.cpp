#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*
    FIFO = FIRST IN FIRST OUT
    CODA, QUEUE
 
                    h   t
     dequeue <--- [ x y _ _ _ _ _ ] <--- enqueue
 
 */

template<class T> class Queue {
	
	
private:
    int n, len, current, iterations;   
	int head, tail;
    T** q;  

public:
    Queue(){
    	n = 0;
    	len = 200;
    	q = new T*[len]; // array di puntatori
    	head = tail = iterations = 0;
	}
	Queue(int len ){
    	n = 0;
    	this -> len = len;
    	q = new T*[len]; // array di puntatori
    	head,tail, iterations = 0;
	}
	
	Queue<T>& enqueue (T key){ //ritorna l'indirizzo un oggetto generio{
		if(n++ < len){
			q[tail++] = new T(key);
			if (tail==len)	tail = 0;
		}
		return *this;
	}
		
	T* dequeue(){
		if(n-- > 0){
			T* tmp= q[head++];
			if(head == len) head=0;
			return tmp;
		}
		return NULL;
	}
	
	int isEmpty() {return (n==0);}
	void reset()  {current = head, iterations = 0;}
    int hasNext() {return (iterations < n);}
    
    T* next(){
    	if(hasNext()){  // (iterations < n);
    		T* tmp = q[current++];
    		if(current == len)	current=0;
    		iterations ++;
    		return tmp;
		}
		return NULL;
	}
      
};

ostream& operator << (ostream& os, const Queue<int> &q) {
	Queue<int> tmp = q;
	tmp.reset();
	while(tmp.hasNext()){
		int *e = tmp.next();
		os << *e << " ";			// provare &tmp
	}
	return os;
}
ostream& operator << (ostream& os, const Queue<char> &q) {
	Queue<char> tmp = q;
	tmp.reset();
	while(tmp.hasNext()){
		char *e = tmp.next();
		os << *e << " ";			// provare &tmp
	}
	return os;
}
ostream& operator << (ostream& os, const Queue<double> &q) {
	Queue<double> tmp = q;
	tmp.reset();
	while(tmp.hasNext()){
		double *e = tmp.next();
		os << *e << " ";			// provare &tmp
	}
	return os;
}
ostream& operator << (ostream& os, const Queue<bool> &q) {
	Queue<bool> tmp = q;
	tmp.reset();
	while(tmp.hasNext()){
		bool *e = tmp.next();
		os << *e << " ";			// provare &tmp
	}
	return os;
}


int main()
{
    ifstream in ("input.txt");
    ofstream out ("output.txt");
    
	string type;
    while ( in >> type){
        
        int dim;
        in >> dim;  
		        
        if(type=="char"){
            Queue<char>* q = new Queue<char>();
            for(int i = 0; i < dim ; i++){
                char x;     				//creo variabile char
                in >> x;    				//inserisco ad ogni ciclo
                q->enqueue(x);				//aggiungo nell'array
            }
            out << *q <<endl;
        }

        if(type=="int"){
            Queue<int>* q = new Queue<int>();
            for(int i = 0; i < dim ; i++){
                int x;     				//creo variabile char
                in >> x;    				//inserisco ad ogni ciclo
                q->enqueue(x);				//aggiungo nell'array
            }
            out << *q << endl;
        }

        if(type=="double"){
            Queue<double>* q = new Queue<double>();
            for(int i = 0; i < dim ; i++){
                double x;     				//creo variabile char
                in >> x;    				//inserisco ad ogni ciclo
                q->enqueue(x);				//aggiungo nell'array
            }
            out << *q <<endl;
        }
        if(type=="bool"){
            Queue<bool>* q = new Queue<bool>();
            for(int i = 0; i < dim ; i++){
                bool x;     				//creo variabile char
                in >> x;    				//inserisco ad ogni ciclo
                q->enqueue(x);				//aggiungo nell'array
            }
            out << *q <<endl;
        }
    }
    in.close();
    out.close();

    return 0;
}

