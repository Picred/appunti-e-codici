// Coded by Picred (https://github.com/Picred)

#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

template<class T>
class MinHeap{
    private:
        T* heap;
        int maxsize, heapsize;

        int parent(int i){
            return i/2;
        }

        void swap(int i, int j){
            T tmp = heap[i];
            heap[i] = heap[j];
            heap[j] = tmp;
        }

        void increasekey(int i, T key){
            heap[i] = key;

            while (i > 1 && heap[i] < heap[parent(i)]){
                this->swap(i, parent(i));
                i = parent(i);
            }
        }


    public:
        MinHeap(int max) : maxsize(max){
            this->heap = new T[max];
            this->heapsize = 0;
        }

        void insert(T k){
            heapsize++;
            increasekey(heapsize,k);
        }

        void print(ofstream& out){
            for(int i=1; i<=heapsize; i++){
                out << heap[i] << " ";
            }
            out << endl;
        }
};


template<class T> void solve(ifstream& in, ofstream& out, int n){
    MinHeap<T> heap = MinHeap<T>(n+1);

    for(int i=0; i<n; i++){
        T key;
        in >> key;
        heap.insert(key);
    }
    heap.print(out);
}


int main(int argc, char const *argv[]){
    ifstream in("input.txt");
    ofstream out("output.txt");

    string type;
    int n;

    for(int i=0; i<100; i++){
        in >> type >> n;
        
        if(type == "bool"){
            solve<bool>(in,out,n);
        }

        if(type == "double"){
            solve<double>(in,out,n);
        }

        if(type == "int"){
            solve<int>(in,out,n);
        }

        if(type == "char"){
            solve<char>(in,out,n);
        }
    }

}