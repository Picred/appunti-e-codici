#include<iostream>
#include<typeinfo>
#include<cstdlib>
#include<cctype>

using namespace std;

class A {
    private:
        int* ptr;
        short len;
    
    public:
        A(short m, short k){
            this -> len = m;
            ptr=new int [m];
                for(int i=0; i<m; i++){
                    ptr[i] = rand()%(k-1+1)+1;
                }
        }

        virtual double const f() =0;

        int get(short i){
            return ptr[i%len];
        }

        short getLen() const {return len; }

        virtual ostream& put(ostream& os){
            os<< typeid(*this).name() << ", ptr=[ ";
                for(int i=0; i<getLen(); i++){
                    os << get(i) << " ";
                }
            os << "] ";
            return os;
        }

        int& operator[](short i){
            return ptr[i%len];
        }
};



class B: public A{
    private:
        double p;
    
    public:
        B(short m, short k, double y): A(m,k){
            this-> p = y;
        }

        double const f(){
            int pari=0;
        
            for(int i=0; i<A::getLen(); i++){
                if((get(i))%2 == 0){
                    pari+=A::get(i);
                }
            }
            return (double)pari/p;
        }

        ostream& put(ostream& os){
            A::put(os);
            os<< "p=" << p << ", f()=" << f();
            return os;
        }
};


class C: public A{
    private:
        char x;
    
    public:
        C(short n, short k, char c): A(n, k){
            this -> x = c;
        }

        double const f(){
            double media=0.0;
            int n_dispari=0;
                for(int i=0; i<A::getLen(); i++){
                    if((A::get(i))%2!=0){
                        media+= A::get(i);
                        n_dispari++;
                    }
                }
                if(n_dispari == 0){
                    return 0;
                }
                return media/n_dispari; //il risultato sarà 0 se ci sono solo pari
        }

        string const g(char c){
            string back="";
            return back+x+c;
        }

        ostream& put(ostream& os){
            A::put(os);
            os<< "x=" << x << ", f()=" << f();
            return os;
        }
};

ostream& operator<<(ostream& os, A& o){
    return o.put(os);
}


int main(){
    
srand(111222333);
const int DIM=50;
A *vett[DIM];

    for (int i = 0; i < DIM; i++){
        short n = 1 + rand() % 10;
        short m = 1 + rand() % 8;
        if (rand() % 2 == 0)
            vett[i] = new B(n, m, rand() / (double)RAND_MAX + 0.05);
        else
            vett[i] = new C(n, m, (char)(rand() % ('z' - 'a' + 1) + 'a'));
    }

    cout << "PUNTO 1" << endl;
        for (int i = 0; i < DIM; i++){
            cout << i << ")" << *vett[i] << endl;
        }

    cout << endl << "PUNTO 2" << endl;
    
    double media=0.0;
    cout << media << endl;
    string concat="";
        for (int i = 0; i < DIM; i++){
            media+=(*vett[i]).f();
            if(typeid(*vett[i])==typeid(C)){
                concat+= ((C*)(vett[i]))->g('h');
            }
        }

        cout << "Avg(f())= " << media/DIM << ", concat= " << concat;

    cout << endl << "PUNTO 3" << endl;
    cout << "vett[5]=" << (*vett[5])[0] << endl;
    (*vett[5])[0]=-1;
    cout << "vett[5]=" << (*vett[5])[0] << endl;

    return 0;
} 


/*PUNTO 1
0)1B, ptr=[ 6 1 6 5 6 4 7 ], p=0.578977, f()=37.998
1)1B, ptr=[ 1 1 1 1 ], p=0.563901, f()=0
2)1B, ptr=[ 1 5 2 4 ], p=0.534268, f()=11.2303
3)1B, ptr=[ 6 6 6 1 3 ], p=0.22127, f()=81.3486
4)1B, ptr=[ 2 1 5 2 1 5 6 3 2 ], p=0.363028, f()=33.0553
5)1B, ptr=[ 1 3 4 2 3 4 1 2 1 ], p=0.174729, f()=68.6777
6)1C, ptr=[ 1 2 2 1 2 ], x=n, f()=1
7)1B, ptr=[ 3 6 3 4 2 ], p=0.895637, f()=13.3983
8)1B, ptr=[ 1 1 1 1 1 1 1 1 ], p=1.00837, f()=0
9)1C, ptr=[ 1 ], x=p, f()=1
10)1B, ptr=[ 1 1 1 3 2 1 3 2 3 ], p=0.342886, f()=11.6657
11)1B, ptr=[ 6 4 2 5 ], p=0.439508, f()=27.3033
12)1B, ptr=[ 8 2 5 8 7 1 ], p=0.0874767, f()=205.769
13)1B, ptr=[ 4 1 2 4 2 ], p=0.456507, f()=26.2866
14)1C, ptr=[ 4 ], x=w, f()=0
15)1C, ptr=[ 2 5 6 4 ], x=z, f()=5
16)1B, ptr=[ 5 ], p=0.923989, f()=0
17)1C, ptr=[ 1 2 ], x=x, f()=1
18)1B, ptr=[ 2 1 2 ], p=0.791234, f()=5.0554
19)1B, ptr=[ 4 1 3 1 2 5 1 5 3 4 ], p=0.693788, f()=14.4136
20)1C, ptr=[ 1 1 2 ], x=o, f()=1
21)1C, ptr=[ 1 1 3 ], x=y, f()=1.66667
22)1C, ptr=[ 2 3 1 3 2 1 2 2 3 1 ], x=j, f()=2
23)1C, ptr=[ 7 5 1 5 8 4 3 ], x=g, f()=4.2
24)1C, ptr=[ 8 1 8 5 8 3 1 ], x=d, f()=2.5
25)1C, ptr=[ 3 1 1 3 3 3 2 ], x=n, f()=2.33333
26)1B, ptr=[ 1 1 1 1 1 1 1 ], p=0.173692, f()=0
27)1C, ptr=[ 1 1 1 1 1 ], x=n, f()=1
28)1B, ptr=[ 6 2 5 3 2 2 5 1 2 ], p=0.986644, f()=14.1895
29)1B, ptr=[ 1 1 1 1 1 ], p=0.758731, f()=0
30)1C, ptr=[ 4 3 4 2 2 ], x=i, f()=3
31)1C, ptr=[ 4 2 5 3 7 3 2 6 ], x=a, f()=4.5
32)1B, ptr=[ 3 3 3 5 3 5 1 1 3 1 ], p=0.276844, f()=0
33)1B, ptr=[ 2 2 2 3 2 3 2 4 4 1 ], p=0.460779, f()=39.0643
34)1B, ptr=[ 1 1 1 1 1 1 1 1 1 1 ], p=0.711824, f()=0
35)1B, ptr=[ 4 4 4 2 4 3 4 4 4 ], p=1.02867, f()=29.1639
36)1C, ptr=[ 3 3 2 2 1 1 ], x=s, f()=2
37)1C, ptr=[ 2 4 2 5 2 3 ], x=v, f()=4
38)1B, ptr=[ 1 3 2 2 2 1 3 1 ], p=0.983287, f()=6.10199
39)1C, ptr=[ 6 5 ], x=o, f()=5
40)1C, ptr=[ 1 2 2 1 1 2 2 2 1 2 ], x=x, f()=1
41)1C, ptr=[ 8 8 7 8 1 7 7 8 ], x=q, f()=5.5
42)1B, ptr=[ 3 3 4 3 1 3 1 1 ], p=0.111068, f()=36.0141
43)1B, ptr=[ 1 1 2 1 2 ], p=0.914986, f()=4.37165
44)1B, ptr=[ 1 1 1 1 1 1 ], p=0.779118, f()=0
45)1B, ptr=[ 4 4 4 5 ], p=0.237078, f()=50.6162
46)1C, ptr=[ 1 1 3 3 3 3 4 2 ], x=e, f()=2.33333
47)1B, ptr=[ 2 1 3 2 ], p=0.0983413, f()=40.6747
48)1C, ptr=[ 7 5 7 7 2 5 5 ], x=i, f()=6
49)1B, ptr=[ 7 3 2 ], p=0.445734, f()=4.48699

 PUNTO 2
Avg(f())= 16.3384, concat=nhphwhzhxhohyhjhghdhnhnhihahshvhohxhqhehih

 PUNTO 3
vett[5]=1
vett[5]=-1
*/