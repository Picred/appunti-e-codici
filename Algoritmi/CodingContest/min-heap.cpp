#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

template<class T> class MinHeap{
    private:
        T* heap;
        int heapsize, maxsize, fycalls;

        int left(int i){
            return i*2;
        }

        int right(int i){
            return (i*2)+1;
        }

        int parent(int i){
            return i/2;
        }

        void heapify(int i){
            if(heapsize>0) fycalls++;
            int l = left(i);
            int r = right(i);
            int min = i;

            if(l <= heapsize && heap[l] < heap[min])
                min = l;
            if(r <= heapsize && heap[r] < heap[min])
                min = r;
            if(min!=i){
                swap(heap[i], heap[min]);
                heapify(min);
            }
        }
    public:
        MinHeap(int size) : maxsize(size), heapsize(0){
            this->fycalls = 0;
            this->heap = new T[size];
        }

        void extract(){
            if(heapsize!=0){
                swap(heap[1], heap[heapsize]);
                heapsize--;
                heapify(1);
            }
        }

        void insert(T key){
            heap[++heapsize] = key;
            int i = heapsize;

            while(i > 1 && heap[i] < heap[parent(i)]){
                swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
        }

        void print(ofstream &out){
            out << fycalls << " ";
            for(int i=1; i<=heapsize; i++)
                out << heap[i] << " ";
            out << endl;
        }
};

template<class T> void solve(ifstream &in, ofstream &out, int n){
    MinHeap<T> heap = MinHeap<T>(n+1);    
    string op;

    for(int i=0; i<n; i++){
        in >> op;
        if(op == "extract")
            heap.extract();
        else{ // op is enqueue
            stringstream ss(op.substr(2));
            T key;
            ss >> key;
            heap.insert(key);
        }
    }
    heap.print(out);
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    string type;
    int n;

    for(int i=0; i<100; i++){
        in >> type >> n;
        if(type == "int")
            solve<int>(in,out,n);
        if(type == "char")
            solve<char>(in,out,n);
        if(type == "bool")
            solve<bool>(in,out,n);
        if(type=="double")
            solve<double>(in,out,n);
    }
    return EXIT_SUCCESS;
}