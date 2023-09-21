// Coded by Picred (https://github.com/Picred)

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

template<class T>
class MaxHeap{
    private:
        T* heap;
        int heapsize;
    
    int left(int i){return 2*i;}

    int right(int i){return (2*i)+1;}

    int parent(int i){return i/2;}

    void heapify(int i){
        int max=i;
        int left=this->left(i);
        int right=this->right(i);

        if(left <= heapsize && heap[left] > heap[max])
            max = left;

        if(right <= heapsize && heap[right] > heap[max])
            max = right;
        
        if (max != i){
            swap(heap[i], heap[max]);
            heapify(max);
        }
    }

    public:
        MaxHeap(T* array, int size){
            heap = array;
            this->heapsize = size;
        }

        void print(ofstream &out){
            for(int i=1; i<heapsize+1; i++)
                out << heap[i] << " ";
            out << endl;
        }

        void build_max_heap(){
            for(int i=heapsize/2; i>0; i--)
                heapify(i);
        }
};

template<typename T> void solve(ifstream &in, ofstream &out, int N){
    T* arr = new T[N+1];

    for(int i=1; i<N+1; i++)
        in >> arr[i];

    MaxHeap<T> heap = MaxHeap<T>(arr, N);
    heap.build_max_heap();

    heap.print(out);
}

int main(int argc, char *argv[]){
    ifstream in("input.txt");
    ofstream out("output.txt");

    string type;
    int N;

    for(int i=0; i<100; i++){
        in >> type >> N;
        
        if(type == "char")
            solve<char>(in, out, N);

        if(type == "bool")
            solve<bool>(in, out, N);

        if(type == "int")
            solve<int>(in, out, N);

        if(type == "double")
            solve<double>(in, out, N);
    }
}