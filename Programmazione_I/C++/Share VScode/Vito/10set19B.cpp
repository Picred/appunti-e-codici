
#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <cmath>


using namespace std;

class A{
    private:
        double* arr;
        short len;
    public:
        A(short m){
            this->len = m;
            arr= new double[m];
            for(int i=0; i<len; i++)
                arr[i] = (double)rand()/RAND_MAX;
        }

        virtual double f(short a)=0;
        short getLen(){return len;}

    protected:
        double get(short i){
            return arr[i%len];
        }
};

class B: public A{
    private:
        double p;

    protected:
        double foo(short s,int k){
            double somma=0;
            for (int i=s%A::getLen(); i<A::getLen(); i++){
                somma+=A::get(i);
            }
            return somma*k;
        }

    public:
        B(short m) : A(m){
            double media = 0.0;
            for (int i=0; i<A::getLen(); i++)
                media+=A::get(i);
            p=media/A::getLen();
        }

        double f(short a){
            return log(foo(a,2*a))/p;
        }
    
};