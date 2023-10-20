#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

template <class T> class MaxHeap{
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

        void heapify(int i){
            if(heapsize > 0)
                this->fycalls++;
            
            int l = left(i);
            int r = right(i);
            int max = i;
            if(l <= heapsize && heap[l] > heap[max])
                max = l;

            if(r <= heapsize && heap[r] > heap[max])
                max = r;
            
            if (max != i){
                swap(heap[i], heap[max]);
                heapify(max);
            }
        }

    public:
        MaxHeap(int _maxsize) {
            this->heap = new T[_maxsize];
            maxsize = _maxsize;
            heapsize = 0;
            fycalls = 0;
        }

        void insert(T key){
            heap[++heapsize] = key;
            int i = heapsize;
            while (i>1 && heap[i] > heap[parent(i)]){
                swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
        }

        void extract(){
            swap(heap[1], heap[heapsize]);
            heapsize--;
            heapify(1);
        }

        void print(ofstream &out){
            out << fycalls << " ";

            for(int i=1; i<=heapsize; i++)
                out << heap[i] << " ";
            
            out << endl;
        }
};

template <class T> void solve(ifstream &in, ofstream &out, int n){
    MaxHeap<T> heap = MaxHeap<T>(n+1);

    for(int i = 0; i<n; i++){
        string tmp;
        in >> tmp;

        //analizzo tmp e:1 -> enqueue 1 / extract -> extract()
        if(tmp == "extract") 
            heap.extract();
        else{
            stringstream ss(tmp.substr(2));
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

        if(type == "bool")
            solve<bool>(in,out,n);

        if(type == "char")  
            solve<char>(in,out,n);
        
        if(type == "double")  
            solve<double>(in,out,n);
    }
}