#include <iostream>
#include <fstream>

using namespace std;

template<class T>
class MaxHeap{
    private:
        T* heap;
        int heapsize;
        int n_heapify;

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
            this->n_heapify++;
            int max = i;
            int l = left(i);
            int r = right(i);

            if(l <= heapsize && heap[l] > heap[max])
                max = l;
            
            if(r <= heapsize && heap[r] > heap[max])
                max = r;

            if(max != i){
                swap(heap[i], heap[max]);
                heapify(max);
            }
        }


    public:
        MaxHeap(T* arr, int n){ 
            this->heap = arr;
            this->heapsize = n;
            n_heapify = 0;
        }

        void build_max_heap(){
            for(int i=heapsize/2; i>0; i--)
                heapify(i);
        }

        void extractall(){
            while(heapsize > 1){
                swap(heap[1], heap[heapsize--]);
                heapify(1);
            }
        }

        void print(ofstream& out){
            out << this->n_heapify << endl;
        }

};

template<class T> void solve(ifstream& in, ofstream& out, int n){
    T* arr = new T[n+1];

    for(int i=1; i<n+1; i++){
        in >> arr[i];
    }

    MaxHeap<T> heap = MaxHeap<T>(arr, n);
    heap.build_max_heap();
    heap.extractall();
    heap.print(out);

    delete[] arr;
}


int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    string type;
    int n;

    for(int i=0; i<100; i++){
        in >> type >> n;

        if(type == "int"){
            solve<int>(in,out,n);
        }
        if(type == "double"){
            solve<double>(in,out,n);
        }
        if(type == "char"){
            solve<char>(in,out,n);
        }
        if(type == "bool"){
            solve<bool>(in,out,n);
        }
        
    }
}