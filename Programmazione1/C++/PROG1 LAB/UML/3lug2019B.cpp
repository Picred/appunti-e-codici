#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <string>


#define DIM 50

using namespace std;

class A{
    private:
        char* s;
        short len;
    public:
        A(short m){ //costruttore di A
            this->len=m;
            s=new char[m];
            for(int i=0; i<len; i++){
                s[i]= rand()%('z' - 'a' + 1) +'a';
            }
        }

        virtual double elab(short a)=0;

        short getLen(){return len;}

        //metodo put
        virtual ostream& put(ostream& os){
            os << typeid(*this).name() << ", s= ";
            
            //stampo stringa, for
            for(int i=0; i<len; i++){
                os << s[i];
            }
            os << ", ";
        return os;
        }

        protected:
            char get(short i){
                return s[i%len];
            }
};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B: public A{
    private:
        int p;
    public:
        B(short m, int x) : A(m){
            this->p=x;
        }

        double elab(short a){
            short V=0; //vocali 
            short C=0; //consonanti
                //scorro la stringa
                for(int i=0;i<getLen();i++){
                    switch(toupper(get(i))){
                        case 'A':
                        case 'E':
                        case 'I':
                        case 'O':
                        case 'U':
                            V++;
                            break;
                        default:
                            C++;
                    }
                }
                return (double)V/(C+1);
        }

        ostream& put(ostream& os){
            A::put(os);
            os << "p=" << p << ", elab(3)=" << elab(3);
            return os;
        }


        B operator++(int a){
            B aux = *this;
            p++;
            return aux;
        }


        protected:
            bool test(){
                for(int i=0;i<4;i++){
                    switch(toupper(A::get(i) )){
                        case 'A':
                        case 'E':
                        case 'I':
                        case 'O':
                        case 'U':
                            return true;
                            break;
                    }
                }
                return false;
            }
};

class C: public A{
    private:
        char x;
    public:
        C(short n, char c) : A(n){
            this-> x = c;
        }

        double elab(short r){
            short counter=0;
                for(int i=r%getLen();i<A::getLen();i++){
                    if(get(i) >= x){
                        counter++;
                    }
                }
            return (counter/(double)(getLen()));
        }

        string g(char c){
            char* ret=new char[1];
            ret[0]=x;
            ret[1]=c;
            return ret;
        }

    ostream& put(ostream& os){
        A::put(os);
        os << "x=" << x << ", elab(3)= " << elab(3);
        return os;
    }

};

int main(){
    srand(111222333);

    A* vett[DIM];

    for(int i=0; i<DIM; i++) {
	    short n=1+rand()%10;
	        if(rand()%2==0)
	            vett[i]= new B(n, rand()%10 + 1);
	        else
	            vett[i]= new C (n, (char) (rand()%((int) 'z' - (int) 'a' + 1) + (int) 'a'));
	}

    //PUNTO 1
    cout << "PUNTO 1" << endl;
    for(int i=0; i<DIM;i++){
        cout << i << ")" << *vett[i] << endl;
    }

    //PUNTO 2
    cout << endl << "PUNTO 2" << endl;
    double media=0.0;
    string s="";
        for(int i=0; i<DIM;i++){
            media+= vett[i]->elab(3);
            if(typeid(*vett[i]) == typeid(C) )
                s+=((C*)vett[i])->g('h');
        }
        cout << "Avg=" << media/DIM << ", concat=" << s << endl;

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    cout << *vett[0] << endl << endl;
    // B* auxx= ((B*)vett[0]);
    // (*auxx)++;
    // cout << *auxx;


    B* auxx=nullptr;
    for(int i=0; i<DIM && auxx==nullptr;i++){
        if(typeid(*vett[i]) == typeid(B)){
            auxx= ((B*)vett[i]);
            (*auxx)++;
        }
    cout << *auxx;

    }

    return 0;
    // (*((B*)vett[0]))++;
    //  cout << *vett[0];
}

/*
PUNTO 1
0)1B, s= rkmplzx, p=3, elab(3)=0
1)1C, s= i, x=q, elab(3)=0
2)1C, s= jovmmietpt, x=e, elab(3)=0.7
3)1B, s= wrnle, p=3, elab(3)=0.2
4)1B, s= snbwmxealy, p=10, elab(3)=0.222222
5)1B, s= efqk, p=6, elab(3)=0.25
6)1C, s= vohm, x=g, elab(3)=0.25
7)1C, s= nsjlw, x=x, elab(3)=0
8)1B, s= stnc, p=5, elab(3)=0
9)1B, s= lymvvg, p=4, elab(3)=0
10)1B, s= u, p=4, elab(3)=1
11)1C, s= a, x=o, elab(3)=0
12)1C, s= ieid, x=h, elab(3)=0
13)1C, s= agcfbi, x=b, elab(3)=0.5
14)1C, s= xdtr, x=a, elab(3)=0.25
15)1C, s= ignvajias, x=v, elab(3)=0.111111
16)1B, s= bxr, p=1, elab(3)=0
17)1B, s= hxwh, p=1, elab(3)=0
18)1C, s= zxsv, x=r, elab(3)=0.25
19)1B, s= mmuv, p=4, elab(3)=0.25
20)1C, s= jcy, x=x, elab(3)=0.333333
21)1B, s= m, p=9, elab(3)=0
22)1C, s= mmjwambr, x=p, elab(3)=0.25
23)1B, s= imkzp, p=10, elab(3)=0.2
24)1B, s= rkqbybjmz, p=3, elab(3)=0
25)1C, s= nwgsxjoog, x=j, elab(3)=0.555556
26)1B, s= fgwwgglr, p=2, elab(3)=0
27)1B, s= pdj, p=10, elab(3)=0
28)1C, s= nkq, x=k, elab(3)=1
29)1B, s= nralnva, p=2, elab(3)=0.333333
30)1B, s= ixzmerjtl, p=7, elab(3)=0.25
31)1B, s= nvbzr, p=6, elab(3)=0
32)1B, s= slhtmgh, p=2, elab(3)=0
33)1B, s= hoqsfekfhg, p=9, elab(3)=0.222222
34)1C, s= irwnj, x=b, elab(3)=0.4
35)1C, s= havk, x=g, elab(3)=0.25
36)1B, s= jor, p=5, elab(3)=0.333333
37)1B, s= xshiovggxo, p=3, elab(3)=0.375
38)1C, s= s, x=d, elab(3)=1
39)1C, s= l, x=f, elab(3)=1
40)1C, s= vtdkhwa, x=s, elab(3)=0.142857
41)1C, s= wxrwyhf, x=w, elab(3)=0.285714
42)1B, s= ekhznhnc, p=2, elab(3)=0.125
43)1C, s= bkvsfx, x=j, elab(3)=0.333333
44)1B, s= qfcj, p=4, elab(3)=0
45)1C, s= jojy, x=c, elab(3)=0.25
46)1B, s= fdzxgncg, p=5, elab(3)=0
47)1C, s= zorwfprxcb, x=v, elab(3)=0.2
48)1B, s= jddgjf, p=1, elab(3)=0
49)1C, s= ptsnge, x=q, elab(3)=0

 PUNTO 2
Avg= 0.23646, concat=qhehghxhohhhbhahvhrhxhphjhkhbhghdhfhshwhjhchvhqh

 PUNTO 3
0): 1B, s= rkmplzx, p=3
0): 1B, s= rkmplzx, p=4
*/