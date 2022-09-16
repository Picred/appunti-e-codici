#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

template <class T>
class Pila{



public:
    Pila(int size = 200);
    ~Pila(){delete[] array;}
    void push(const T& obj);
    T& get(int index);
    void pop(vector<string>&myVec, int n);

private:
    T *array;
    int size;
    int elements;
};

template <class T>
void Pila<T>::pop(vector<string> &myVec, int n){
	string x;
	int pos = 0;
	vector<string>myNewVec;

	for(int i = 0; i < n; i++){
		x = myVec[i];
		if(x == "pop"){												            // Inizio Fase di pulizia array
            pos--;
            myNewVec.erase(myNewVec.begin()+(pos),myNewVec.end());				// Elimino le celle "pop" e quelle precedenti a "pop" all'interno dell'array
        }
		else{
            myNewVec.push_back(x); 											    // Faccio un classico push_back degli elementi "buoni"
            pos++;
		}
	}

	reverse(myNewVec.begin(),myNewVec.end());									// Inverto l'array

	for(int i = 0;i < myNewVec.size(); i++){
		myNewVec[i].erase(myNewVec[i].begin()); 								// Pulisco il l'array dinamico (myNewVec) dai dai caratteri 'i'
       		array[i] = myNewVec[i];                                                 // Inserisco myNewVec[i] nell'"array" cosicchè da utilizzarlo nella procedura di stampa get(int index)
    }
}

template <class T>
Pila<T>::Pila(int size){
        this->size = size;
        this->elements = 0;
        this->array = new T[this->size];
}


template <class T>
void Pila<T>::push(const T& obj){
    if(this->elements < this->size)
        array[elements++] = obj;
    else
        cout << "Bra don't piss me off";
}

template <class T>
T& Pila<T>::get(int index){

    if(index < 0 || index >= size)
        throw "bad index!";
    else
        return array[index];
}


int main() {
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");

    for(int task = 0; task < 100; task++){
        string type;
        in >> type;
        int n;
        in >> n;

		vector<string> myVec;
		Pila<string> obj(n);
		string x;

		for(int i=0; i<n; i++){
            in>> x;
            myVec.push_back(x);
		}

		obj.pop(myVec,n);												// eliminato i pop e gli elementi precedenti al pop + reverse + clear char 'i';

        for(int i= 0;i<myVec.size(); i++) out << obj.get(i) << " ";     //procedura di stampa tramite get(index)
        out << endl;
	}
    in.close();
    out.close();

    return 0;
}

