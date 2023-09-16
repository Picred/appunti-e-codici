// Coded by Picred (https://github.com/Picred)

#include <iostream>
#include <fstream>

using namespace std;

template<class T>
class MinHeap{
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
            int l = left(i);
            int r = right(i);
            int min = i;
            if(l <= heapsize && heap[l] < heap[min])
                min = l;
            
            if(r <= heapsize && heap[r] < heap[min])
                min = r;
            
            if(min != i){
                swap(heap[i], heap[min]);
                heapify(min);
            }
        }

    public:
        MinHeap(int size, T* arr){
            heapsize = size; 
            heap = arr;
        }

        void build_min_heap(){
            for(int i = heapsize/2; i>0; i--)
                heapify(i);
        }

        void print(ofstream& out){
            for(int i=1; i<heapsize+1; i++)
                out << heap[i] << " ";
            
            out << endl;
        }
            
};

template<class T> void solve(ifstream& in, ofstream& out, int n){
    T* arr = new T[n+1];

    for(int i=1; i<n+1; i++){
        in >> arr[i];
    }
    MinHeap<T> heap = MinHeap<T>(n, arr);
    heap.build_min_heap();

    heap.print(out);
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    string type;
    int n;

    for (int i = 0; i < 100; i++){
        in >> type >> n;

        if(type == "int")
            solve<int>(in,out,n);
        
        if(type == "double")
            solve<double>(in,out,n);
        
        if(type == "bool")
        solve<bool>(in,out,n);
        
        if(type == "char")
            solve<char>(in,out,n);
    }
    
}