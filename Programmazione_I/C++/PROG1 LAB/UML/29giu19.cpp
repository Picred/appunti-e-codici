#include <iostream>
#include <typeinfo>
#include <cctype>
#include <cstdlib>
#include <cmath>


using namespace std;

class A{
    private:
        int* p;
        short l;
        float y;
    
    public:
        A(short i1, short i2){
            p=new int[i1+i2];
            this -> l = i1+i2;
            short max = (i1>i2 ? i1 : i2);
            short min = (i1<i2 ? i1 : i2);
                for(int i=0; i<l; i++){
                    p[i]= rand()%(max-min+1)+min;
                }
            this -> y = log( (l)/2 );
        }

        virtual float f(short i, float x)=0;
        
        virtual ostream& put(ostream& os){
            os << typeid(*this).name()<< ", p=[";
                for(int i=0; i<l; i++){
                    os << p[i] << " ";
                }
            os << "]: l=" << l << ", y=" << y << "{ ";
            return os;
        }
        protected:
            int val(short j){
                if(j<l){
                    return p[j];
                }
                return p[rand()%l];
            }
};


class B: public A{
    private:
        string str;

    public:
        B(string w, short a, short b) : A(a,b){
            for(int i=0; i< w.length(); i++){
                if( islower(w[i]) ){
                    switch(w[i]){
                        case 'a':
                        case 'e':
                        case 'i':
                        case 'o':
                        case 'u':
                            str+=w[i];
                            break; // o continue?
                    }
                }
            }
        }

        ostream& put(ostream& os){
            A::put(os);
            os << "str=" << str << "}";
            return os;
        }

        float f(short i, float x){
            return sin( ((float)(val(i)))  )*x;
        }
};

class C: public A{
    private:
        float m;
    
    public:
        C(float z) : A( round(z), (round(z)*5)){
            this-> m= val((2*round(z))/2);
        }

        float f(short i, float x){
            if(i%2==0 && x!=0){
                return sin(val(i)*x);
            }
            if(i%2!=0 && x!=0){
                return val(i)/x;
            }
            if(x==0){
                return 0.0;
            }
            return (x==0) ? : 0.0;
        }

        float g(){
            return log(m);
        }

        ostream& put(ostream& os){
            A::put(os);
            os << " m=" << m << "}";
            return os;
        }
};

ostream& operator<<(ostream& os, A& o){
    return o.put(os);
}

int main(){
    srand(111222333);
    const int DIM=30;
    A *vett[DIM];

    string w;
    short s1, s2;

        for (int i = 0; i < DIM; i++){
            if (rand() % 2 == 0)
            { // B
                w = "";
                s1 = rand() % 20 + 5;
                s2 = rand() % 20 + 5;
                short len = rand() % 50 + 10;
                for (int j = 0; j < len; j++)
                    w += ((rand() % 2) ? (char)(rand() % 26 + 'a') : (char)(rand() % 10 + '0'));
                vett[i] = new B(w, s1, s2);
            }
            else
            { // C
                int max = 10;
                float z = ((float)rand()) / INT_MAX * (rand() % max) + 1.0;
                vett[i] = new C(z);
            }
        }

    cout << "PUNTO 1" << endl;
        for(int i=0; i<DIM; i++){
            cout << i << ")Class " << *vett[i] << endl; 
        }

    cout << endl <<  "PUNTO 2" << endl;
    cout << "Indici: ";
        for (int i=0; i<DIM; i++){
            if(vett[i]->f(5,0.5) < 0.5){
                cout << i << " ";
            }
        }

    cout << endl <<  "PUNTO 3" << endl;      
        float media=0.0;
        short counter=0;
            for (int i=0; i<DIM; i++){
                if(typeid(*vett[i]) == typeid(C) ){
                    media+= ((C*)(vett[i])) -> g();
                    counter++;
                }
        }
        cout << "Media valori classe C per cui g()=" << (media/counter);

    // probabilemnte output del punto 3 errato dal prof e forse giusto da me

    
}

/*Punto I:
0)Class 1B, p=[15 11 14 14 13 14 14 13 15 14 10 13 10 7 15 14 7 12 11 15 12 14 ]: l=22, y=2.3979{ str=eou}
1)Class 1B, p=[9 12 9 10 12 10 15 19 12 20 19 17 20 21 18 14 13 20 9 22 9 8 16 20 8 16 22 10 21 14 ]: l=30, y=2.70805{ str=oou}
2)Class 1B, p=[14 18 13 13 14 16 11 10 11 14 18 12 16 11 10 9 10 13 11 9 13 12 17 10 18 9 11 ]: l=27, y=2.56495{ str=}
3)Class 1C, p=[3 5 3 5 1 1 ]: l=6, y=1.09861{ m = 1.5}
 g()=0.405465
4)Class 1B, p=[23 16 17 23 24 16 20 20 18 17 20 24 20 20 15 22 21 24 18 18 19 18 19 20 15 16 18 16 23 16 19 16 17 22 19 19 16 20 24 ]: l=39, y=2.94444{ str=}
5)Class 1C, p=[5 5 5 2 4 1 ]: l=6, y=1.09861{ m = 2.5}
 g()=0.916291
6)Class 1B, p=[19 19 19 19 19 18 19 19 19 19 19 18 18 19 18 18 18 18 18 18 19 18 19 18 19 19 18 18 19 19 18 19 19 18 19 18 18 ]: l=37, y=2.89037{ str=eeieo}
7)Class 1C, p=[5 4 1 5 2 5 ]: l=6, y=1.09861{ m = 0.5}
 g()=-0.693147
8)Class 1B, p=[18 17 18 18 17 17 18 18 17 16 16 16 17 17 17 18 17 18 16 17 18 18 18 16 17 16 17 16 17 17 16 17 17 17 ]: l=34, y=2.83321{ str=aaia}
9)Class 1C, p=[4 2 2 2 2 1 ]: l=6, y=1.09861{ m = 1}
 g()=0
10)Class 1B, p=[9 10 8 11 10 10 11 7 9 9 8 10 11 11 11 10 10 9 ]: l=18, y=2.19722{ str=ieeueuo}
11)Class 1C, p=[3 3 4 5 4 5 ]: l=6, y=1.09861{ m = 2}
 g()=0.693147
12)Class 1B, p=[9 9 15 17 18 13 13 12 14 10 14 9 8 9 13 16 17 16 18 8 11 12 8 18 11 ]: l=25, y=2.48491{ str=aaiu}
13)Class 1B, p=[12 18 13 13 13 14 12 12 24 14 22 23 23 16 22 20 14 23 13 20 23 12 21 19 16 17 23 17 13 16 23 22 17 17 13 19 ]: l=36, y=2.89037{ str=}
14)Class 1C, p=[5 1 1 1 2 4 ]: l=6, y=1.09861{ m = 0.5}
 g()=-0.693147
15)Class 1C, p=[1 2 5 2 4 1 ]: l=6, y=1.09861{ m = 2.5}
 g()=0.916291
16)Class 1B, p=[19 18 19 20 14 13 15 18 20 15 18 20 19 16 14 20 15 20 14 18 13 16 16 18 18 17 20 15 13 18 20 15 19 ]: l=33, y=2.77259{ str=aa}
17)Class 1B, p=[6 15 19 13 16 18 15 9 14 17 10 17 16 9 16 6 14 12 5 17 12 18 16 11 ]: l=24, y=2.48491{ str=eua}
18)Class 1C, p=[5 4 5 2 2 1 ]: l=6, y=1.09861{ m = 2.5}
 g()=0.916291
19)Class 1B, p=[13 21 21 18 15 18 17 17 22 16 12 14 14 12 19 21 12 21 18 18 14 22 14 19 19 19 15 19 20 12 19 12 13 19 ]: l=34, y=2.83321{ str=ooaeu}
20)Class 1B, p=[16 19 17 19 17 17 16 17 16 20 16 16 16 18 19 17 18 19 16 17 18 19 18 18 19 19 17 18 16 19 16 16 17 18 19 20 ]: l=36, y=2.89037{ str=aaeae}
21)Class 1B, p=[22 22 22 21 22 21 22 21 22 22 21 21 21 21 21 21 22 22 22 22 21 21 21 22 22 21 22 22 22 22 21 21 22 21 21 21 22 22 22 21 22 21 22 ]: l=43, y=3.04452{ str=aieaooeu}
22)Class 1B, p=[11 8 19 12 16 22 7 20 19 18 11 15 20 12 22 17 17 11 19 10 17 23 21 9 23 21 15 8 22 11 ]: l=30, y=2.70805{ str=ua}
23)Class 1C, p=[1 2 2 3 5 1 ]: l=6, y=1.09861{ m = 1}
 g()=0
24)Class 1B, p=[8 7 10 8 8 10 10 8 8 9 9 7 7 9 7 7 7 ]: l=17, y=2.07944{ str=iiaou}
25)Class 1B, p=[11 14 16 12 16 11 16 13 11 11 16 15 16 13 16 12 16 11 15 12 14 16 13 11 12 11 14 ]: l=27, y=2.56495{ str=oi}
26)Class 1C, p=[4 2 4 5 3 4 ]: l=6, y=1.09861{ m = 2}
 g()=0.693147
27)Class 1C, p=[5 4 5 1 4 3 ]: l=6, y=1.09861{ m = 2.5}
 g()=0.916291
28)Class 1C, p=[3 1 4 4 1 4 ]: l=6, y=1.09861{ m = 2}
 g()=0.693147
29)Class 1B, p=[10 10 8 10 9 8 9 8 8 10 10 8 9 9 8 8 9 10 ]: l=18, y=2.19722{ str=eauaieoa}


Punto II: Indici per cui f( 5, 0.5 )<0.5:0 1 2 4 6 8 10 12 13 16 17 19 20 21 22 24 25 29

Punto III (media dei valori del metodo g()): 0.158793
*/