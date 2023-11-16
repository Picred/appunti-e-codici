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
                    }
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