// Coded by Picred (https://github.com/Picred)

#include <iostream>
#include <fstream>

using namespace std;

template<class T>
class MinHeap{
    private:
        T* heap;
        int maxsize, heapsize, fycalls;
    
        int left(int i){
            return i*2;
        }

        int right(int i){
            return (i*2)+1;
        }

        int parent(int i){
            return i/2;
        }

        void build(){
            for(int i=heapsize/2; i>0; i--){
                heapify(i);
            }
        }

        void heapify(int i){
            fycalls++;
            int r = right(i);
            int l = left(i);
            int min = i;

            if(l<=heapsize && heap[l] < heap[min])
                min = l;
            
            if(r<=heapsize && heap[r] < heap[min])
                min = r;
            
            if(min!=i){
                swap(heap[i], heap[min]);
                heapify(min);
            }
        }

        void extract(){
            swap(heap[1], heap[heapsize--]);
            heapify(1);
        }

    public:
        MinHeap(T* arr, int maxsize){
            this->maxsize = maxsize;
            heapsize = maxsize;
            fycalls = 0;
            heap = arr;
        }

        void heapsort(){
            this->build();
            while(heapsize > 1){
                extract();
            }
        }

        void print(ofstream& out){
            out << this->fycalls << " ";
            for(int i=1; i<=maxsize; i++){
                out << heap[i] << " ";
            }
            out << endl;
        }
};

template<class T> void solve(ifstream& in, ofstream& out, int n){
    T* arr= new T[n+1];

    for(int i=1; i<=n; i++){
        in >> arr[i];
    }

    MinHeap<T> heap = MinHeap<T>(arr, n);
    heap.heapsort();
    heap.print(out);

}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    string type;
    int n;

    for(int i=0; i<100; i++){
        in >> type >> n;
        if (type == "int")
            solve<int>(in,out,n);

        if (type == "char")
            solve<char>(in,out,n);

        if (type == "double")
            solve<double>(in,out,n);

        if (type == "bool")
            solve<bool>(in,out,n);
    }
}