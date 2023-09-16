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
        int maxsize;
        int heapifycalls;
    
    int left(int i){
        return 2 * i;
    }

    int right(int i){
        return (2 * i) + 1;
    }

    int parent(int i){
        return i / 2;
    }

    void heapify(int i){
        if(heapsize > 0)
            this->heapifycalls++;
        int max = i;
        int left = this->left(i);
        int right = this->right(i);

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
        MaxHeap(int max){
            this->maxsize = max;
            heap = new T[maxsize];
            this->heapsize = 0;
            this->heapifycalls = 0;
        }


        void insert(T key){
            if(heapsize == 0){
                heapsize++;
                heap[1] = key; // da rivedere l'indice
                return;
            }
            
            if(heapsize < maxsize)
                heapsize++;
            else{
                cout << "Full heap";
                return;
            }
            heap[heapsize] = key;
            int i = heapsize;

            while (i > 1 && heap[i] > heap[parent(i)]){
                swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
        }

        T extract(){
            swap(heap[1], heap[heapsize]);
            heapsize--;
            this->heapify(1);
            return heap[heapsize+1]; 
        }

        void print(ofstream &out){
            out << this->heapifycalls << " ";
            for(int i=1; i<heapsize+1; i++){
                out << heap[i] << " ";
            }
            out << endl;
        }
};

template<typename T> void solve(ifstream &in, ofstream &out, int N){
    MaxHeap<T> heap = MaxHeap<T>(N+1);
    
    for(int i=0; i<N; i++){
        string op;
        in >> op; // e:1

        if(op == "extract"){
            heap.extract();
        }
        else{
            stringstream s(op.substr(2));
            T key;
            s >> key;
            heap.insert(key);
        }
    }

    heap.print(out);
}

int main(int argc, char *argv[]){
    ifstream in("input.txt");
    ofstream out("output.txt");

    string type;
    int N;

    for(int i=0; i<100; i++){
        in >> type >> N;
        
        if(type == "char"){
            solve<char>(in, out, N);
        }

        if(type == "bool"){
            solve<bool>(in, out, N);
        }

        if(type == "int"){
            solve<int>(in, out, N);
        }

        if(type == "double"){
            solve<double>(in, out, N);
        }
    }

    return 0;
}
