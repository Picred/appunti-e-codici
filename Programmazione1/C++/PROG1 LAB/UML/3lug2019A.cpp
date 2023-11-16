#include <iostream>
#include <cstdlib>
#include <typeinfo>

#define DIM 50

using namespace std;

class A{
    private:    
        int* arr;
        short len;
    public:
        A(short m, int a, int b){
            arr=new int[m];
            this->len=m;
            //inizializzo array con rand
            for(int i=0;i<m;i++){
                arr[i]=rand()%(b-a+1)+a;
            }
        }
        virtual double func(short i)=0;

        short getLen() const {
            return len;
        }

        virtual ostream& put(ostream& os){
            os << typeid(*this).name() << ", arr=[ ";
            for(int i=0;i<getLen(); i++){
                os << arr[i] << " ";
            }
            os << "], ";
            return os;
        }

        int& operator[](short i){ //
            return arr[i%len];
        }

    protected:
        double get(short i){
            return arr[i%len];
        }
};


ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}


class B : public A{
    private:
        double p;
    public:
        B(short m,int y,int z, double x) : A(m,y,z){
            this-> p = x;
        }

        double func(short i){
            double max=get(0);// (double)min/max +p
            double min=get(0);
                for(int j=0;j<getLen();j++){
                    if(get(j) > max){
                        max=get(j);
                    }
                    if(get(j) < min){
                        min=get(j);
                    }
                }
            return (min/max)+p;
        }

        ostream& put(ostream& os){
            A::put(os);
            os << " p=" << p << ", func(3)=" << func(3);
            return os;
        }
};

class C: public A{
    private:
        char t;
    public:
        C(short n, char c,int a, int b) : A(n,a,b){
            this-> t=c;
        }
        double func(short i){
            double media=0.0;
                for(int j=0;j<getLen();j++){
                    media+=get(j);
                }
            return media/(double)getLen();
        }

        string g(char c,short k){
            string s="";
            for(int i=0;i<k;i++){
                s+=this->t;
                s+=c;
            }
            return s;
        }

        ostream& put(ostream& os){
            A::put(os);
            os << " t=" << t << ", func(3)=" << func(3);
            return os;
        }
};


int main(){


    srand(111222333);     
    A* vett[DIM];
        for(int i=0; i<DIM; i++){
	        short n=1+rand()%10;
            if(rand()%2==0)
                vett[i]= new B(n, rand()%5+1, rand()%11+10, (double) rand()/(RAND_MAX));
            else
                vett[i]= new C(n, (char) (rand()%('z' - 'a' + 1) + 'a'), rand()%5+1, rand()%11+10);
        }

    //PUNTO 1
    cout << "PUNTO 1" << endl;
        for(int i=0; i<DIM; i++){
            cout << i << ") " << (*vett[i]) << endl;
        }
    //PUNTO 2
    cout << "PUNTO 2" << endl;
        double media=0.0;
        for(int i=0; i<DIM; i++){
            media+=vett[i]->func(3) ;
        }
        media/=DIM;
        short counter=0;
        for(int i=0; i<DIM && counter<3;i++){
            if(typeid(*vett[i]) == typeid(C)){
                cout << "i=" << i << " g('h',2)= " << ((C*)vett[i])->g('h',2) << endl;
                counter++;
            }
        }
        cout << media << endl;

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    cout << "vett[5]=" << (*vett[0])[5] << endl; //il prof intendeva (*vett[0])[5]=7 vett[5]=1
    (*vett[0])[5]= 1;
    cout << "vett[5]=" << (*vett[0])[5] << endl;
    
    return 0;
}

/*
PUNTO 1
0)1B, arr=[ 17 16 14 14 16 7 14 ], p=0.521622, func(3)=0.933387
1)1B, arr=[ 14 6 13 17 17 13 9 ], p=0.307199, func(3)=0.66014
2)1C, arr=[ 7 10 ], t=t, func(3)=8.5
3)1C, arr=[ 16 17 8 13 5 4 ], t=l, func(3)=10.5
4)1C, arr=[ 15 16 15 16 5 12 5 11 8 ], t=e, func(3)=11.4444
5)1B, arr=[ 10 16 11 7 7 12 15 11 10 5 ], p=0.724662, func(3)=1.03716
6)1B, arr=[ 7 6 9 10 8 ], p=0.0464187, func(3)=0.646419
7)1B, arr=[ 4 12 7 6 4 11 4 8 7 ], p=0.709555, func(3)=1.04289
8)1C, arr=[ 3 12 10 7 2 15 ], t=i, func(3)=8.16667
9)1C, arr=[ 11 ], t=b, func(3)=11
10)1C, arr=[ 7 ], t=d, func(3)=7
11)1C, arr=[ 12 12 11 9 5 9 ], t=i, func(3)=9.66667
12)1B, arr=[ 8 14 3 ], p=0.0578326, func(3)=0.272118
13)1C, arr=[ 2 ], t=x, func(3)=2
14)1C, arr=[ 7 17 4 11 14 2 ], t=z, func(3)=9.16667
15)1C, arr=[ 11 ], t=e, func(3)=11
16)1B, arr=[ 11 4 2 16 9 9 18 ], p=0.741234, func(3)=0.852345
17)1B, arr=[ 7 3 12 5 11 5 12 10 11 ], p=0.515488, func(3)=0.765488
18)1B, arr=[ 10 ], p=0.375805, func(3)=1.3758
19)1C, arr=[ 10 9 12 ], t=j, func(3)=10.3333
20)1B, arr=[ 14 15 11 13 6 15 10 4 ], p=0.272866, func(3)=0.539533
21)1B, arr=[ 18 6 7 13 12 12 10 14 17 ], p=0.0723899, func(3)=0.405723
22)1B, arr=[ 3 7 6 2 ], p=0.679708, func(3)=0.965423
23)1B, arr=[ 3 14 7 2 ], p=0.986938, func(3)=1.1298
24)1C, arr=[ 5 10 7 12 3 ], t=z, func(3)=7.4
25)1C, arr=[ 18 4 9 7 8 ], t=n, func(3)=9.2
26)1C, arr=[ 16 13 14 ], t=h, func(3)=14.3333
27)1B, arr=[ 5 4 5 ], p=0.108402, func(3)=0.908402
28)1C, arr=[ 17 6 13 9 14 ], t=h, func(3)=11.8
29)1C, arr=[ 4 3 9 5 9 7 ], t=h, func(3)=6.16667
30)1C, arr=[ 13 16 6 14 16 ], t=o, func(3)=13
31)1B, arr=[ 8 7 5 ], p=0.0192267, func(3)=0.644227
32)1C, arr=[ 14 10 15 6 15 10 4 8 1 8 ], t=s, func(3)=9.1
33)1B, arr=[ 4 2 6 ], p=0.0824, func(3)=0.415733
34)1B, arr=[ 4 7 8 ], p=0.121372, func(3)=0.621372
35)1C, arr=[ 8 3 3 8 11 8 2 1 10 ], t=z, func(3)=6
36)1C, arr=[ 17 6 9 10 20 16 15 10 5 14 ], t=t, func(3)=12.2
37)1C, arr=[ 9 8 5 ], t=o, func(3)=7.33333
38)1C, arr=[ 6 10 18 11 18 ], t=c, func(3)=12.6
39)1C, arr=[ 3 8 6 3 1 ], t=p, func(3)=4.2
40)1C, arr=[ 9 7 9 10 9 7 ], t=d, func(3)=8.5
41)1C, arr=[ 6 10 2 13 14 11 9 ], t=g, func(3)=9.28571
42)1B, arr=[ 2 5 3 3 9 4 2 9 ], p=0.787378, func(3)=1.0096
43)1C, arr=[ 4 14 14 9 2 ], t=z, func(3)=8.6
44)1B, arr=[ 14 18 11 6 7 16 10 5 ], p=0.494461, func(3)=0.772239
45)1B, arr=[ 7 15 8 6 12 ], p=0.741905, func(3)=1.1419
46)1B, arr=[ 15 8 10 10 7 13 14 9 5 6 ], p=0.294687, func(3)=0.62802
47)1C, arr=[ 4 10 6 10 5 4 8 8 3 ], t=d, func(3)=6.44444
48)1C, arr=[ 8 10 10 6 3 ], t=p, func(3)=7.4
49)1C, arr=[ 3 ], t=t, func(3)=3

 PUNTO 2
i=2, g(h,2)=thth
i=3, g(h,2)=lhlh
i=4, g(h,2)=eheh
Avg(f(3))= 5.44218

 PUNTO 3
vett[5]=7
vett[5]=1
*/