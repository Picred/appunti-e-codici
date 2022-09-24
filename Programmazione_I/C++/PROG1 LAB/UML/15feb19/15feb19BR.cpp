#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <cmath>


using namespace std;

class A{
    private:
        int x;
    
    public:
        A(int m){
            this->x = m;
        }
        virtual double v(int a)=0;

        virtual ostream& put(ostream& os){
            os << typeid(*this).name() << ", x=" << x << ", ";
            return os;
        }

};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B: public A{
    private:
        int* ptr;
        int l;
    
    protected:
        int sum(int t){
            int somma=0;
            for (int i=0; i<l; i++){
                if(ptr[i] <= t){
                    somma++;
                }
            }
            return somma;
        }

    public:
        B(int z,int y) : A(z){
            this->l = y;
            ptr=new int[y];

            for (int i=0; i<l; i++)
                ptr[i]=rand()%101;
        }

        double v(int a){
            return (l*1000)/((double)((sum(a)+1)));
        }

        ostream& put(ostream& os){
            A::put(os);
            os << "ptr=[";
            for(int i=0; i<l; i++){
                os << ptr[i] << " ";
            }
            os << "], v(50)=" << v(50);
            return os;
        }

        int& fun(int& x){
            return ptr[x%l];
        }
};

template<typename T>
class C: public A{
    private:
        T k;

    public:
        C(int n) : A(n){
            if(typeid(k) == typeid(int)){
                this->k = 2*n;
            }
            else {
                k=(double)(log(1+(sin(n)*sin(n))));
            }
        }

        T g(T w){
            return k*(w+1);
        }

        double v(int r){
            return g(r);
        }

        ostream& put(ostream& os){
            A::put(os);
            os << "k=" << k << ", v(50)=" << v(50);
            return os;
        }

        // int& operator[](int& x){
        //     return 0;
        // }

};

int& operator[](B& obj, int& i){
    return obj.fun(i);
}

int main(){
    srand(111222333);

const int DIM = 50;
A *vett[DIM];

    for (int i = 0; i < DIM; i++){
        int n = 1 + rand() % 10;
        switch (rand() % 3){
        case 0:
            vett[i] = new B(n, rand() % 10 + 1);
            break;
        case 1:
            vett[i] = new C<int>(n);
            break;
        case 2:
            vett[i] = new C<double>(n);
        }
    }
    
    //PUNTO 1
    cout << "PUNTO 1" << endl;
        for(int i=0; i<DIM; i++){
            cout << i << ")" << *vett[i] << endl;
        }

    //PUNTO 2
    cout << endl << "PUNTO 2" << endl;
    double max= vett[0]->v(50);
    double min= vett[0]->v(50);
    double media=0.0;
        for(int i=0; i<DIM; i++){
            if( vett[i]->v(50) > max){
                max= vett[i]->v(50);
            }
            if( vett[i]->v(50) < min){
                min= vett[i]->v(50);
            }
            if(typeid(*vett[i]) == typeid(C<double>)){
                media+= ((C<double>*)(vett[i])) -> g(5);
            }
        }
        cout << "max= " << max << " min= " << min << " media= " << media;

    //PUNTO 3 RIVEDERE NON VA ASSEGNAMENTO
    cout << endl << "PUNTO 3" << endl;
        cout << (*vett[43]) << endl;
        (*vett[43])[3] = 1;
        //ERRORE
        cout << (*vett[43]);
}