#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
#include <cmath>
using namespace std;


class A
{
    private:
        double *w;
        short len;
    protected:
        double get(short i) const
        {
            return w[i%len];
        }
    public:
        A(short m)
        {
            len=m;
            for(int i=0; i<len; i++)
            {
                w[i]=(double)rand()/RAND_MAX;
            }
        }
        short getLen() const
        {
            return len;
        }
        virtual double const foo(short a);
        virtual ostream& out(ostream& stampa)
        {
            stampa<<"w= ";
            for(int i=0; i<len; i++)
            {
                stampa<<w[i]<<" ";
            }
            stampa<<endl;
            stampa<<"len= "<<len<<endl;
            return stampa;
        }
        double& operator[](int i)
        {
            return w[i];
        }
};

class B: public A
{
    private:
        int p;
    protected:
        double sum(short s) const
        {

            double sum=0;
            for(int i=s%getLen(); i<getLen(); i++)
            {
                sum+=get(i);
            }
            return sum;
        }
    public:
        B(short m, int x): A(m)
        {
            p=x;
        }
        double foo(short a) const
        {
            return (sum(a)/p);
        }
    ostream& out(ostream& stampa)
    {
        A::out(stampa)<<"p= "<<p<<endl;
        return stampa;
    }
};

template <typename T>
class C: public A
{
    private:
        T x;
    public:
        C(short n): A(n)
        {
            if(typeid(x)==typeid(short))
            {
                x=n;
            }
            else
            {
                x=log(1+sin(n)*sin(n));
            }
        }
        double foo(short r) const
        {
            return g(r);
        }
        T g(T k) const
        {
            return 2*x*(k+1);
        }
    ostream& out(ostream& stampa)
    {
        A::out(stampa)<<"x= "<<x<<endl;
        return stampa;
    }
};

ostream& operator <<(ostream& stampa, A& obj)
{
    return obj.out(stampa);
}


int main()
{
    srand (111222333);
    const int DIM= 50;
    A *vett[DIM];
    for(int i=0; i<DIM; i++)
    {
        short n=1+rand()%10;
        switch(rand()%3)
        {
            case 0:
                vett[i]= new B(n, rand()%10+1);
                break;
            case 1:
                vett[i]= new C<double>(n);
                break;
            case 2:
                vett[i]= new C<short>(n);
        }
    }

    //punto1
    for(int i=0; i<DIM; i++)
    {
        cout<<i<<") "<<*vett[i]<<" "<<endl;
    }
    //punto2
    double max=vett[0]->foo(3);
    for(int i=1; i<DIM; i++)
    {
        if(max<vett[i]->foo(3))
        {
            max=vett[i]->foo(3);
        }
    }
    cout<<"Max= "<<max<<endl;
    int sum=0;
    for(int i=0; i<DIM; i++)
    {
        if(typeid(*vett[i])==typeid(C<double>))
        {
            sum+=((C<double>*)vett[i])->g(5);
        }
    }
    cout<<"Media= "<<sum/DIM<<endl;
    //punto3
    (*vett[0])[1]=rand();
    cout<<"(*vett[0])[1]= "<<(vett[0])[1]<<endl;


}
