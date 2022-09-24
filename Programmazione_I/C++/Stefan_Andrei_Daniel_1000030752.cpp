#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <cctype>


#define DIM 10

using namespace std;

class AbstractRandomVec{
    protected:
        int* vec;
        int num;
    
    public:
        AbstractRandomVec(int n, int min, int max){
            vec=new int[n];
            num = n;
            for(int i=0; i<n; i++){
                vec[i]=rand()%((max-min+1)+min);
            }
        }

        virtual int count() = 0;

        int* get(int i){
            //bisognava verificare se i è all'interno del range
            int* ptr = nullptr;
                if( &vec[i] != nullptr){
                    ptr= &vec[i];
                }
            return ptr;
        }

        int numel(){
            return num;
        }

        float mean(){ // media degli elementi del vettore
            float media=0.0;
            for(int i=0; i<numel(); i++){
                media+=vec[i];
            }
            return (float)(media/numel());
        }

        virtual ostream& put(ostream& os){
            os << typeid(*this).name() << ", num=" << num << ", vec=[";
                for(int i=0; i<numel(); i++){
                    os << vec[i] << " ";
                }
            os << "]";
            return os;
        }
};

class TernaryVec: public AbstractRandomVec{
    public:
        TernaryVec(int n) : AbstractRandomVec(n, 0 , 2){}

        int count(){
            int counter=0;
            for(int i=0; i<numel(); i++){
                if( vec[i] != 0 ){
                    counter++;
                }
            }
            return counter;
        }

        ostream& put(ostream& os){
            return AbstractRandomVec::put(os);
        }
};

class MultVec: public AbstractRandomVec{
    private:
        double midpoint;
    
    public:
        MultVec(int n, int min, int max, int mul) : AbstractRandomVec(n,min,max){
            for(int i=0; i<numel(); i++){
                int elemento = rand()%(max-min+1)+min;
                    if( elemento % mul == 0 ){
                        vec[i] = elemento;
                    } // ALTRIMENTI??
            }

            num=n;
            double media=((double)((max+min)))/2;
            midpoint=media;
        }

        int count(){
            int counter=0;
            for(int i=0; i<numel(); i++){
                if( vec[i] > midpoint ) {
                    counter++;
                }
            }
            return counter;
        }

        int countEven(){
            int counter=0;
            for(int i=0; i<numel(); i++){
                if( vec[i] % 2 ==0 ){
                    counter++;
                }
            }
            return counter;
        }

        ostream& put(ostream& os){
            AbstractRandomVec::put(os);
            os << "midpoint=" << midpoint;
            return os;
        }
};

ostream& operator<<(ostream& os, AbstractRandomVec& o){
    return o.put(os);
}

int main(){
    srand(424242);
    
    AbstractRandomVec* vett[DIM];

    for (int i = 0; i < DIM; i++){
        int n = 5 + rand() % 5;
        int m = 5 + rand() % 5;
        int min = rand() % 10 + 5;
        int max = min + rand() % 20;

        switch (rand() % 2){
        case 0:
            vett[i] = new TernaryVec(n);
            break;
        case 1:
            vett[i] = new MultVec(n, min, max, m);
        }
    }

    //PUNTO 1
    cout << "PUNTO 1" << endl;
    for (int i = 0; i < DIM; i++){
        cout << i << ")Class=" << *vett[i] << endl;
    }

    //PUNTO 2
    cout << endl << "\nPUNTO 2" << endl;
    int max=0;
        for (int i = 0; i < DIM; i++){
            if( vett[i]-> count() > max ){
                max= vett[i]-> count();
            }
        }

    cout << "Valore massimo di count()= " << max;

    //PUNTO 3
    cout << endl << "\nPUNTO 3" << endl;
        short counter=0;
        double media=0;
        for (int i = 0; i < DIM; i++){
            if(typeid(*vett[i])==typeid(MultVec)){
                media+= ((MultVec*)(vett[i]))->countEven();
                counter++;
            }
        }

        cout << "Media valori countEven() per oggetti tipo MultVec = " << media/(double)(counter);

    return 0;
}

/*OUTPUT :
0) Class=7MultVec, num=8, vec=[24 18 30 18 27 21 30 30 ], midpoint=22.5
1) Class=7MultVec, num=5, vec=[21 21 18 18 15 ], midpoint=17.5
2) Class=7MultVec, num=6, vec=[9 9 6 6 6 6 ], midpoint=7
3) Class=10TernaryVec, num=5, vec=[1 0 2 0 1 ]
4) Class=7MultVec, num=5, vec=[15 12 18 12 18 ], midpoint=14.5
5) Class=10TernaryVec, num=6, vec=[1 0 2 2 2 0 ]
6) Class=7MultVec, num=9, vec=[12 9 9 9 18 12 6 12 12 ], midpoint=15
7) Class=10TernaryVec, num=8, vec=[2 0 1 1 2 0 0 2 ]
8) Class=10TernaryVec, num=5, vec=[2 1 1 1 2 ]
9) Class=10TernaryVec, num=7, vec=[1 0 1 2 2 1 2 ]
max count(): 6
mean countEven(): 4.4
*/