#include <iostream>
#include <fstream>

using namespace std;

template<class T>
class HashTable{
    private:
        int maxsize;
        int* bucket;
    public:
        HashTable(int m){
            maxsize = m;
            bucket = new int[m]{0};
        }

        void insert(T k){
            this->bucket[(int)(k)%maxsize]++;     
        }

        void printBucket(ofstream& out){
            for(int i=0; i<maxsize; i++){
                out << bucket[i] << " ";
            }
            out << endl;
        }
};

template<class T> void solve(ifstream& in, ofstream& out, int n, int m){
    HashTable<T> table = HashTable<T>(m);

    for(int i=0; i<n; i++){
        T key;
        in >> key;
        table.insert(key);
    }
    table.printBucket(out);
}

int main(int argc, char *argv[]){
    ifstream in("input.txt");
    ofstream out("output.txt");

    string type;
    int n, m;

    for(int i=0; i<100; i++){
        in >> type >> m >> n;

        if(type =="int")
            solve<int>(in,out,n,m);
        
        if(type =="double")
            solve<double>(in,out,n,m);
        
        if(type =="bool")
            solve<bool>(in,out,n,m);
        
        if(type =="char")
            solve<char>(in,out,n,m);
    }
}