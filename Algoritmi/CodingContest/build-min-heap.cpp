#include <iostream>
#include <fstream>

using namespace std;

template<class T> class MinHeap{
    private:
        T* heap;
        int heapsize;

        int left(int i){
            return 2*i;
        }

        int right(int i){
            return (2*i)+1;
        }

        int parent(int i){
            return i/2;
        }

        void heapify(int i){
            int r = right(i);
            int l = left(i);
            int min = i;

            if(l <= heapsize && heap[l] < heap[min])
                min = l;
            
            if(r <= heapsize && heap[r] < heap[min])
                min = r;
            
            if(min!=i){
                swap(heap[min], heap[i]);
                heapify(min);
            }
        }
        
    public:
        MinHeap(int hsize, T* array) : heapsize(hsize), heap(array){}

        void build(){
            int i = heapsize;

            for(int i=heapsize/2; i>=1; i--){
                heapify(i);
            }
        }

        void print(ofstream &out){
            for(int i=1; i<=heapsize; i++)
                out << heap[i] << " ";
            out << endl;
        }

};

template<class T> void solve(ifstream &in, ofstream &out, int n){
    T* array = new T[n+1];

    for(int i=1; i<=n; i++)
        in >> array[i];

    MinHeap<T> heap = MinHeap<T>(n, array);
    heap.build();
    heap.print(out);
}


int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    string type;
    int n;

    for(int i=0; i<100; i++){
        in >> type >> n;
        if(type == "char"){
            solve<char>(in, out, n);
        }
        if(type == "int"){
            solve<int>(in, out, n);
        }
        if(type == "double"){
            solve<double>(in, out, n);
        }
        if(type == "bool"){
            solve<bool>(in, out, n);
        }
    }
}