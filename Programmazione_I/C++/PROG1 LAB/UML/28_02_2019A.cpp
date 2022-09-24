#include <iostream>
#include <typeinfo>
#include <cmath>
#include <cstdlib>

using namespace std;

class A {
    private:
        short * arr;
        short len;
    protected:
        short get(short i) {
            return arr[i%len];
        }
    public:
        A(short m) {
            len=m;
            arr=new short[len];
            for(int i=0;i<len;i++)
                arr[i]=(rand()%11)+1;
        }
        short getLen() {
            return len;
        }

        virtual double f(short a)=0;

        virtual ostream& print(ostream& ss) {
            ss<<"arr=[";
            for(int i=0;i<len;i++)
                ss<<arr[i]<<" ";
            ss<<"]";
            return ss;
        }
};

template <class T>
class B:public A {
    private:
        T x;
    public:
        B(short m, char c): A(m) {
            if(typeid(x)==typeid(char)) {
                x=c;
            }
            else {
                string s="";
                for(int i=0;i<m;i++)
                    s+=c;
                x=s;
            }
        }
        double f(short a) {
            double sum=0.0;
            int c=0;
            for(int i=a%getLen();i<getLen();i++) {
                sum+=get(i);
                c++;
            }
            sum=sum/c;
            return sum;
        }
        double foo(short s) {
            return ((double)log(s)+sin(f(s)));
        }

        ostream& print(ostream& ss) {
            A::print(ss);
            ss<<", x="<<x<<", f(3)="<<f(3);
            return ss;
        }
};

class C:public A {
    private:
        int y;
    public:
        C(short n, int k): A(n) {
            y=k;
        }
        double f(short a) {
            short r=get(rand()%getLen());
            return (a+y)/r*1.0;
        }
        short g(short w) {
            return sin(w+y);
        }

        ostream& print(ostream& ss) {
            A::print(ss);
            ss<<", y="<<y<<", f(3)="<<f(3);
            return ss;
        }

        C operator++() {
            ++y;
            return *this;
        }
};

ostream& operator<<(ostream& ss, A& o) {
    return o.print(ss);
}

int main() {
    const int DIM=50;
    srand(111222333);
    A *vett[DIM];

    for(int i=0; i<DIM; i++) {
        short n=1+rand()%10;
        switch(rand()%3) {
            case 0:
                vett[i]= new C(n, rand()%10 + 1);
                break;
            case 1:
                vett[i]= new B<string>(n, rand()%('z' - 'a' + 1) + 'a');
                break;
            case 2:
                vett[i]= new B<char>(n, rand()%('z' - 'a' + 1) + 'a');
        }
    }

    //punto 1
    for(int i=0;i<DIM;i++) {
        cout<<i<<")"<<typeid(*vett[i]).name()<<" "<<*vett[i]<<endl;
    }

    //punto 2
    double max=-1;
    double sum=0.0;
    int c=0;
    for(int i=0;i<DIM;i++) {
        if((*vett[i]).f(3)>max)
            max=(*vett[i]).f(3);
        if(typeid(*vett[i])==typeid(C)){
            sum+=((C*)vett[i])->g(5);
            c++;
        }
    }
    sum=sum/c;
    cout<<endl<<"max f(3)="<<max<<", media g(5) C="<<sum<<endl;

    //punto 3
    cout<<endl<<"PRIMA: "<<(*vett[0])<<endl;
    ++(*vett[0]);
    cout<<"DOPO: "<<(*vett[0])<<endl;
}
