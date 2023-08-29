#include<iostream> 
#include <list> 
using namespace std;

template <class T> 
class HashTable{  		 
	public:	     	
	     virtual HashTable<T>* insertKey(T x) = 0;
	     virtual HashTable<T>* deleteKey(T key) = 0;		
		 virtual int searchKey(T key) = 0;	
};


template <class T> 
class ChainedHashTable : public HashTable<T>{
	private:
		int slots;    // Number of slots 	
		list<T>* table;
		int size;

	protected:
		list<T>* getTable(){
			return this->table;
		}
	public:
		ChainedHashTable<T>(int x){
			this->slots = x;
			table = new list<T>[slots];
			size = 0;		
		}

		virtual int computeHashFunction(T x) = 0;
		
		int getSlotNumber(){
			return slots;
		}

		int getSize(){
			return size;
		}

		void printHashTable(){
			for (int i = 0; i < this->getSlotNumber(); i++){
				cout << i;
				for (auto x : table[i])
					cout << " --> [" << x << "]";
				cout << endl;
			}
		}

		
		//versione canonica
		int searchKey(T key){ //in quale slot si trova
			int index = computeHashFunction(key);
			typename list<T>::iterator i; //typename serve per cioè g++,vscode,devc++. Iterator è il puntatore a oggetti dinamici della lista che viene fatto scorrere.
			for (i = table[index].begin(); i != table[index].end(); i++){ //table[index].begin() puntatore alla lista
				if (*i == key)
					return index;
			}
			return -1;	
		}


		void searchKey(T key, int* pos1, int* pos2){ //in quale posizione all'interno di quello slot trovo la chiave. pos1 = posizione sottolista in array, pos2 = posizione nella lista
			*pos1 = computeHashFunction(key);
			typename list<T>::iterator i;
			for (i = table[*pos1].begin(); i != table[*pos1].end(); i++){
				if (*i == key){				
					*pos2 = (int) distance(table[*pos1].begin(), i); //distanza da begin al puntatore i. il cast serve perchè il metodo distance restituisce un tipo T
					return;
				}
			}		 
			*pos2 = -1;
			return;
		}

		ChainedHashTable<T>* insertKey(T key){
			int pos1, pos2;		
			searchKey(key, &pos1, &pos2);		
			if (pos2 == -1){
				table[pos1].push_front(key); //inserisce in testa, push_back() inserisce in coda
				size++;
			}
			return this;
		}

		ChainedHashTable<T>* deleteKey(T key){		
			int pos1 = -1;
			int pos2 = -1;
			searchKey(key, &pos1, &pos2);
			if (pos2 != -1){
				typename list<T>::iterator i = table[pos1].begin();
				advance(i, pos2); //avanzo il puntatore di pos2 posizioni a partire i 
				table[pos1].erase(i);
				size--;
			}
			return this;
		}

};


template <class T> 
class DivisionChainedHashTable : public ChainedHashTable<T>{
	private:
		int computeHashFunction(T x){
			int h = ((int)x % this->getSlotNumber());
			return h;
		}
	public:
		DivisionChainedHashTable<T>(int edge_number) : ChainedHashTable<T>(edge_number) {}
	};


	template <class T> 
	class MultiplicationChainedHashTable : public ChainedHashTable<T>{
	private:
		double c;
		int computeHashFunction(T x){
			double y = x * c;
			double a = y - (int)y;
			int h = (int)(a * this->getSlotNumber());
			return h;
		}
	public:
		MultiplicationChainedHashTable(int edge_number) : ChainedHashTable<T>(edge_number){
			c = 0.7;
		}
};