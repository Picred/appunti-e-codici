#include <iostream>
#include <fstream>
using namespace std;

#define X -1

template <class T> class ArrayList {

private:
    T *A;
    int *N;
    int n, len, head, current;

public:
    ArrayList(int len);             //costruttore con dimensione
    ArrayList& ins(T x);            //procedura d'inserimento
    T& get(int index);              //procedura di stampa
};

template <class T>                  //costruttore con dimensione
ArrayList<T>::ArrayList(int len){
    this->len = len;
    this->n = 0;
    this->head = current = X;
    this->A = new T[len];
    for(int i=0; i<len ; i++) A[i] = 0;
    this->N = new int[len];
}

template <class T>
ArrayList<T>& ArrayList<T>::ins(T x){//procedura di inserimento
    if(n==len) return *this;

    //ricerca della prima posizione vuota
    int pos = 0;
    while(A[pos]!=0) pos++;

    //inserimento nella rappresentazione fisica
    A[pos] = x;

    //inserimento nella rappresentazione logica
    int i = head;
    int p = X;
    while(i!=X && A[i]<=x) {
        p = i;
        i = N[i];
    }
    N[pos] = i;
    if(p!=X)
        N[p] = pos;
    else
        head = pos;
    n++;

    return *this;
}

template <class T>
T& ArrayList<T>::get(int index){
    if(index<0 && index >len) throw "bad Index!";
    else return N[index];
}


int main() {
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");

    for(int task=0; task<100; task++){
        int n;
        in >> n;
        ArrayList<int> set(n);
        int x;

        for(int i=0; i<n; i++){
            in >> x;
            set.ins(x);
        }

        for(int i=0; i<n; i++) out << set.get(i) << " ";

        out << endl;
    }
    in.close();
    out.close();

    return 0;
}
