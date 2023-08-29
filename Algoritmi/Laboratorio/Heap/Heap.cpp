#include <iostream>

using namespace std;

//Template of the Priority Queue
template <class T> 
class PriorityQueue{
	public:
		virtual T* extract() = 0;
		virtual PriorityQueue<T>* enqueue(T x) = 0;
		virtual double compare(T* a, T* b) = 0;
		virtual void printKey(int i) const = 0;
};


//BinaryHeap template
template <class T> 
class BinaryHeap: public PriorityQueue<T>{
	private:
		T** queue;
		int heapsize;
		int queueLength;

		int left(int i){
			return i << 1; // 2*i
		}

		int right(int i){
			return (i << 1) | 1;  //2*i+1
		}

		int parent(int i){
			return i >> 1; // i/2
		}

		void swap(int i, int j){
			T* tmp = queue[i];
			queue[i] = queue[j];
			queue[j] = tmp;
		}

		
		void heapify(int index){ //prende un nodo, scambia questo nodo con il massimo fra i possibili figli, heapify viene di nuovo chiamata sul nodo scambiato
			while (index <= heapsize/2){ //l'ultimo nodo con figli è heapsize/2
				int m = index; // m è il massimo, il nodo con la chiave più alta
				int l = left(index);
				int r = right(index);
				if (l <= heapsize && compare(queue[m], queue[l]) < 0) //compare fa la differenza m.key - l.key
					m = l;
				if (r <= heapsize && compare(queue[m], queue[r]) < 0)
					m = r;
				if (m == index) // non ho fatto switch e quindi non ho un nuovo massimo
					break;
				swap(index, m);
				index = m;
			}
		}

		void recursiveHeapify(int i){
			if (i > heapsize) //Optimization: if (i > heapsize / 2)
				return;
			int l = left(i);
			int r = right(i);
			int v = i;
			if (l <= heapsize && compare(queue[v], queue[l]) < 0)
				v = l;
			if (r <= heapsize && compare(queue[v], queue[r]) < 0)
				v = r;
			if (v == i)
				return;
			swap(i, v);
			recursiveHeapify(v);
		}

		void moveUpKey(int i){
			while (i > 1 && compare(queue[i], queue[parent(i)]) > 0)
			{
				swap(i, parent(i));
				i = parent(i);
			}
		}

	public:
		virtual double compare(T* a, T* b) = 0;
		virtual void printKey(int i) const = 0;


		void print() const{
			for (int i = 1; i <= this->size(); i++)
				printKey(i);
			cout << endl;
		}

		BinaryHeap(int size){
			queue = new T * [size + 1];
			queueLength = size + 1;
			heapsize = 0;
		}

		BinaryHeap(T** V, int size){
			queue = V;
			queueLength = size;
			heapsize = size - 1;
		}

		void buildHeap(){
			for (int i = heapsize / 2; i > 0; i--)
				heapify(i);
		}

		T* extract(){
			if (heapsize == 0)
				return NULL;
			swap(1, heapsize);
			heapsize--;
			heapify(1);
			return queue[heapsize + 1];
		}

		T** getPriorityQueue() const{
			return queue;
		}

		void modify(int i, T k){
			if (compare(queue[i], &k) >= 0)
				return;

			if (i<1 || i>heapsize)
				return;
			delete queue[i];
			queue[i] = new T(k);

			while(i > 1 && compare(queue[i], queue[parent(i)]) > 0){
				swap(i,parent(i));
				i=parent(i);
			}
		}

		BinaryHeap<T>* enqueue(T x){
			if (heapsize == queueLength + 1)
				return this;
			heapsize++;
			queue[heapsize] = new T(x);
			int i = heapsize;
			while(i > 1 && compare(queue[i], queue[parent(i)]) > 0){
				swap(i,parent(i));
				i=parent(i);
			}
			return this;
		}

		void sort(){
			int count = heapsize;
			for (int i = 0; i < count; i++)
				extract();
			heapsize = count;
		}

		int size() const{
			return heapsize;
		}
};



/*Se devo far risalire un nodo uso:
			while(i > 1 && compare(queue[i], queue[parent(i)]) > 0){
				swap(i,parent(i));
				i=parent(i);
			}
altrimenti uso heapify();
*/

template <class T> 
class MaxBinaryHeap: public BinaryHeap<T>{
	public:
		MaxBinaryHeap(int size): BinaryHeap<T>(size) {}
		MaxBinaryHeap(T** A, int size): BinaryHeap<T>(A, size) {}

		virtual double compare(T* a, T* b) = 0;
		virtual void printKey(int i) const = 0;

		T* extractMax(){
			return BinaryHeap<T>::extract();
		}
		void increaseKey(int i, T k){
			return BinaryHeap<T>::modify(i, k);
		}
};



template <class T> 
class MaxHeap: public MaxBinaryHeap<T>{
	public:
		double compare(T* a, T* b){
			return (*a) - (*b);
		}

		void printKey(int i) const{
			cout << *(this->getPriorityQueue())[i] << " ";
		}
		MaxHeap(int size): MaxBinaryHeap<T>(size) {}
		MaxHeap(T** A, int size): MaxBinaryHeap<T>(A, size) {}
};



template <class T> 
class MinBinaryHeap: public BinaryHeap<T>{
	public:
		MinBinaryHeap(int size): BinaryHeap<T>(size) {}
		MinBinaryHeap(T** A, int size): BinaryHeap<T>(A, size) {}
		virtual double compare(T* a, T* b) = 0;
		virtual void printKey(int i) const = 0;
		T* extractMin(){
			return BinaryHeap<T>::extract();
		}
		void decreaseKey(int i, T k){
			return BinaryHeap<T>::modify(i, k);
		}
};


template <class T> 
class MinHeap: public MinBinaryHeap<T>{
	public:
		MinHeap(int size): MinBinaryHeap<T>(size) {}
		MinHeap(T** A, int size): MinBinaryHeap<T>(A, size) {}
		double compare(T* a, T* b){
			return  (*b) - (*a);
		}
		void printKey(int i) const{
			cout << *(this->getPriorityQueue())[i] << " ";
		}
};