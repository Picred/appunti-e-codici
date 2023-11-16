#include <iostream>
#include <typeinfo>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;


class A{

    private:
        double* w;
        short len;
    public:
        A(short m){
            len=m;
            w=new double[m];
            for(int i=0; i<m;i++){
                w[i]=rand()/RAND_MAX*1.0;
            }
        }
        virtual double foo(short a);
        short getLen() const {return len;}
    
    protected:
        double get(short i)const{
            return w[i%len];
        }
};


class B: public A{

    private:
        int p;
    
    public:
        B(short m, int x) : A(m){ p=x; }

        double foo(short a){
            return sum(a)/p;
        }
    protected:
        double sum(short s) const {
        double somma;
            for(int i=s%getLen(); i<getLen(); i++){
                somma+=get(i);
            }
        return somma;
        }
};

template<typename T>
class C : public A{

    private:
        T x;
    public:
        C(short n):A(n){
            if(typeid(x)==typeid(short)){
                x=n;
            }
            else {
                x=log(1+(sin(n)*sin(n)));
            }
        }
        
        T g(T k) const {
            return 2*x*(k+1);
        }

        double foo(short r){
            return g(r);
        }
};


int main(){
    srand(111222333);
    int DIM=50;
    A *vett[DIM];
    for (int i = 0; i < DIM; i++){
        short n = 1 + rand() % 10;
        switch (rand() % 3){
        case 0:
            vett[i] = new B(n, rand() % 10 + 1);
            break;
        case 1:
            vett[i] = new C<double>(n);
            break;
        case 2:
            vett[i] = new C<short>(n);
        }
    }


}