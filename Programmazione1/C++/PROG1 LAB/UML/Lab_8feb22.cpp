#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <climits>

using namespace std;

class AbstractRandomVec {
    protected:
        int* vec;
        int num;
    
    public:
    
        AbstractRandomVec(int n, int min, int max) {
            this->num = n;
            vec = new int[n];
            for(int i = 0; i < n; i++) {
                vec[i] = rand() % (max - min + 1) + min;
            }
        }

        virtual int count() = 0;

        int* get(int i) {
            if(i >= num) return nullptr;
            return (vec + i);
        }

        int numel() {
            return num;
        }

        float mean() {
            float sum = 0;
            for(int i = 0; i < num; i++) {
                sum += vec[i];
            }
            return sum/num;
        }

        virtual ostream& put(ostream& os) {
            os << "Class=" << typeid(*this).name() << ", num=" << num << ", vec=[";
            for(int i = 0; i < num; i++) {
                os << vec[i] << " ";
            }
            os << "]";
            return os;
        }
};

ostream& operator<<(ostream& os, AbstractRandomVec& obj) {
    return obj.put(os);
}

class TernaryVec : public AbstractRandomVec {
    public:
        TernaryVec(int n) : AbstractRandomVec(n, 0, 2) {}

        int count() {
            int c = 0;
            for(int i = 0; i < num; i++) {
                if(vec[i] > 0) c++; 
            }
            return c;
        }
};

class MultVec : public AbstractRandomVec {
    private:
        double midpoint;
    
    public:
        MultVec(int n, int min, int max, int mul) :AbstractRandomVec(n, min, max) {
            int i = 0;
            do {
                int gen = rand() % (max - min + 1) + min;
                if (gen % mul == 0) {
                    vec[i++] = gen;
                }
            } while(i < num);
            midpoint = ((double)(min) + max) / 2; 
        }

        int count() {
            int c = 0;
            for(int i = 0; i < num; i++) {
                if(vec[i] > midpoint) c++;
            }
            return c;
        }

        int countEven() {
            int c = 0;
            for(int i = 0; i < num; i++) {
                if(vec[i] % 2 == 0) c++;
            }
            return c;
        }

        ostream& put(ostream& os) {
            AbstractRandomVec::put(os);
            os << ", midpoint=" << midpoint;
            return os;
        }
};

int main() {
    srand(424242);
    const int DIM = 10;

    AbstractRandomVec* vett[DIM];

    for(int i=0; i<DIM; i++) {
        int n=5+rand()%5;
        int m=5+rand()%5;
        int min = rand()%10 + 5;
        int max = min + rand()%20;

        switch(rand()%2) {
            case 0: {
                vett[i]= new TernaryVec(n);
                break;
            }
            case 1: {
                vett[i]= new MultVec(n, min, max, m);
            }
        }
    }

    //Punto 1
    for(int i = 0; i < DIM; i++) {
        cout << i << ") " << *vett[i] << endl;
    }

    //Punto 2
    int max = INT_MIN;
    for(int i = 0; i < DIM; i++) {
        if(typeid(*vett[i]) == typeid(TernaryVec)) {
            if(max < ((TernaryVec*)vett[i])->count()) {
                max = ((TernaryVec*)vett[i])->count();
            }
        }
        else {
            if(max < ((MultVec*)vett[i])->count()) {
                max = ((MultVec*)vett[i])->count();
            }
        }
    }
    cout << "max count(): " << max << endl;

    //Punto 3
    float mean = 0;
    int count = 0;
    for(int i = 0; i < DIM; i++) {
        if(typeid(*vett[i]) == typeid(MultVec)) {
            mean += ((MultVec*)vett[i])->countEven();
            count++;
        }
    }
    cout << "mean countEven(): " << mean/count << endl;
}