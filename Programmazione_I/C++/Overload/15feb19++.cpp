#include <iostream>
#include <typeinfo>
#include <string>
#include <cstdlib>

#define DIM 50
using namespace std;

class A{
    private:
        char* str;
        short len;

    public:
        A(short m){
            str=new char[m];
            this->len=m;
                for(int i=0; i<len; i++){
                    str[i]=rand()%('z'-'a'+1)+'a';
                }
        }

        virtual double elab(short a)=0;

        short getLen(){return len;}

        virtual ostream& put(ostream& os){
            os<< typeid(*this).name() << ", w= ";
                for(int i=0; i<len; i++){
                    os << str[i];
                }
                os<< " ";
            return os;
        }

    protected:
        char get(short i)  {return str[i%len];}

};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B: public A{
    private:
        int p;

    protected:
        short* map()  {
            short* ret=new short[A::getLen()];

            for(int i=0; i<getLen();i++){
                switch (toupper(get(i))){
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    ret[i]=0;
                    break;
                default:
                    ret[i]=1;
                    break;
                }
            }
            return ret;
        }
    public:
        B(short m,int x) : A(m){
            this->p = x;
        }

    double elab(short a) {
        short* array= B::map();
        short sum=0;
            for(int i=0; i<A::getLen(); i++){
                sum+=array[i];
            }
        double rapporto=((double)(sum))/(p);
        return rapporto;
    }

        B operator++(int a){
            B aux = *this;
            p++; //p è privata di p
            return aux;
        }

// 38)1C, w= qgtabp, x=r, elab(3)=0
// 39)1C, w= sfljibe, x=d, elab(3)=0.428571
// 40)1C, w= hwjvkcsn, x=g, elab(3)=0.5
        ostream& put(ostream& os){
            A::put(os);
            os << "p=" << p << " elab(3)= " << elab(3);
            return os;
        }
};


class C: public A{
    private:
        char x;
    public:
        C(short n, char c): A(n){
            this -> x = c;
        }

        double elab(short r)  {
            int counter=0;
                for(int i=r%getLen(); i<getLen(); i++){
                    if(get(i) >= x){
                        counter++;
                    }
                }
                return (double)(counter)/getLen();
        }

        string g(char c)  {
            string ret="";
            // ret=x+c;
            return ret+x+c;
        }

        ostream& put(ostream& os){
            A::put(os);
            os << "x=" << x << " elab(3)= " << elab(3);
            return os;
        }
};

int main(){
    srand(111222333);

    A *vett[DIM];

    for (int i = 0; i < DIM; i++){
        short n = 1 + rand() % 10;
        if (rand() % 2 == 0)
            vett[i] = new B(n, rand() % 10 + 1);
        else
            vett[i] = new C(n, (char)(rand() % ('z' - 'a' + 1) + 'a'));
    }

    cout << "PUNTO 1" << endl;
        for (int i = 0; i < DIM; i++){
            cout << i << ")" << *vett[i] << endl;
        }

    cout << endl << "PUNTO 2" << endl;
        double media=0.0;
        string concat="";
          for (int i = 0; i < DIM; i++){
            media+=vett[i]->elab(3);
            if(typeid(*vett[i])==typeid(C)){
                concat+= ((C*)(vett[i]))->g('h');
            }
        }
        media/=DIM;
        cout << "media= " << media << " concat= " << concat;

        cout << endl << "PUNTO 3" << endl;
         
    B* auxx=nullptr;
    for(int i=0; i<DIM && auxx==nullptr;i++){
        if(typeid(*vett[i]) == typeid(B)){
            cout << i << ")" << *vett[i] << endl;
            auxx= ((B*)vett[i]);
            (*auxx)++;
            cout << i << ")" << *vett[i] << endl;
            // cout << i << ")" <<*auxx;
        }
    }
}

/*PUNTO 1
0)1B, str= rkmplzx, p=3, elab(3)=2.33333
1)1C, str= i, x=q, elab(3)=0
2)1C, str= jovmmietpt, x=e, elab(3)=0.7
3)1B, str= wrnle, p=3, elab(3)=1.33333
4)1B, str= snbwmxealy, p=10, elab(3)=0.8
5)1B, str= efqk, p=6, elab(3)=0.5
6)1C, str= vohm, x=g, elab(3)=0.25
7)1C, str= nsjlw, x=x, elab(3)=0
8)1B, str= stnc, p=5, elab(3)=0.8
9)1B, str= lymvvg, p=4, elab(3)=1.5
10)1B, str= u, p=4, elab(3)=0
11)1C, str= a, x=o, elab(3)=0
12)1C, str= ieid, x=h, elab(3)=0
13)1C, str= agcfbi, x=b, elab(3)=0.5
14)1C, str= xdtr, x=a, elab(3)=0.25
15)1C, str= ignvajias, x=v, elab(3)=0.111111
16)1B, str= bxr, p=1, elab(3)=3
17)1B, str= hxwh, p=1, elab(3)=4
18)1C, str= zxsv, x=r, elab(3)=0.25
19)1B, str= mmuv, p=4, elab(3)=0.75
20)1C, str= jcy, x=x, elab(3)=0.333333
21)1B, str= m, p=9, elab(3)=0.111111
22)1C, str= mmjwambr, x=p, elab(3)=0.25
23)1B, str= imkzp, p=10, elab(3)=0.4
24)1B, str= rkqbybjmz, p=3, elab(3)=3
25)1C, str= nwgsxjoog, x=j, elab(3)=0.555556
26)1B, str= fgwwgglr, p=2, elab(3)=4
27)1B, str= pdj, p=10, elab(3)=0.3
28)1C, str= nkq, x=k, elab(3)=1
29)1B, str= nralnva, p=2, elab(3)=2.5
30)1B, str= ixzmerjtl, p=7, elab(3)=1
31)1B, str= nvbzr, p=6, elab(3)=0.833333
32)1B, str= slhtmgh, p=2, elab(3)=3.5
33)1B, str= hoqsfekfhg, p=9, elab(3)=0.888889
34)1C, str= irwnj, x=b, elab(3)=0.4
35)1C, str= havk, x=g, elab(3)=0.25
36)1B, str= jor, p=5, elab(3)=0.4
37)1B, str= xshiovggxo, p=3, elab(3)=2.33333
38)1C, str= s, x=d, elab(3)=1
39)1C, str= l, x=f, elab(3)=1
40)1C, str= vtdkhwa, x=s, elab(3)=0.142857
41)1C, str= wxrwyhf, x=w, elab(3)=0.285714
42)1B, str= ekhznhnc, p=2, elab(3)=3.5
43)1C, str= bkvsfx, x=j, elab(3)=0.333333
44)1B, str= qfcj, p=4, elab(3)=1
45)1C, str= jojy, x=c, elab(3)=0.25
46)1B, str= fdzxgncg, p=5, elab(3)=1.6
47)1C, str= zorwfprxcb, x=v, elab(3)=0.2
48)1B, str= jddgjf, p=1, elab(3)=6
49)1C, str= ptsnge, x=q, elab(3)=0

 PUNTO 2
Avg= 1.0889, concat=qhehghxhohhhbhahvhrhxhphjhkhbhghdhfhshwhjhchvhqh

 PUNTO 3
0): 1B, str= rkmplzx, p=3
0): 1B, str= rkmplzx, p=4
*/