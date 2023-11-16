#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
#define DIM 50

using namespace std;

class A {
    private:
        char* str;
        short len;

    public:
        A(short m, string source) {
            this->len = m;
            this->str = new char[len];
            for(int i = 0; i < this->len; i++) {
                str[i] = source[rand() % source.length()];
            }
        }

        virtual char func(short i) = 0;

        short getLen() {
            return this->len;
        }

        virtual ostream& put(ostream& os) {
            string s = "";
            for(int i = 0; i < this->len; i++) {
                s += str[i];
            }
            return os << typeid(*this).name() << ", str = " << s;  
        }

        string operator()(int i1, int i2);

        friend short operator+(A& a1, A& a2);
    
        char& operator[](int i);

    protected:
        char get(short i) {
            return str[i % this->len];
        }
};

ostream& operator << (ostream& s, A& obj) {
    return obj.put(s);
}

string A::operator () (int i1, int i2) {
    string s = "";
    for(int i = i1; i < i2; i++) {
        s += A::get(i);
    }
    return s;
}

short operator+(A& a1, A& a2) {
    return a1.getLen() + a2.getLen();
}

char& A::operator[](int i) {
    return str[i % A::getLen()];
}

class B : public A {
    private:
        short p;
    
    public:
        B(short m, string source) : A(m, source) {
            this->p = 1;
            for(int i = 0; i < m; i++) {
                switch(toupper(A::get(i))) {
                    case 'A':
                    case 'E':
                    case 'I':
                    case 'O':
                    case 'U': {
                        this->p += 1;
                        break;
                    }
                }
            }
        }

        char func(short i) {
            char r = 'X';
            for(int j = i; j < A::getLen() && r == 'X'; j++) {
                switch(toupper(A::get(j))) {
                    case 'A':
                    case 'E':
                    case 'I':
                    case 'O':
                    case 'U': {
                        break;
                    }
                    default: {
                        r = A::get(j);
                    }
                }
            }
            return r;
        }

        void operator++(int) {
            this->p++;
        }

        void operator++() {
            this->p++;
        }

        ostream& put(ostream& os) {
            return A::put(os) << ", p=" << this->p << ", func(3)=" << this->func(3) << endl;
        }

};

class C : public A {
    private:
        char x;

    public:
        C(short n, string source, char y) : A(n, source) {
            this->x = y;
        }

        char func(short i) {
            for(int j = i; j < A::getLen(); j++) {
                if(A::get(j) > this->x) return A::get(j);
            }
            return this->x;
        }

        string g(char c) {
            string s = "";
            for(int i = 0; i < A::getLen(); i++) {
                s += A::get(i);
            }
            return this->x + s + c;
        }

        ostream& put(ostream& os) {
            return A::put(os) << ", x=" << this->x << ", func(3)=" << this->func(3) << endl;
        }
};

int main() {
    srand(111222333);
    A* vett[DIM];

    string S = "supercalifragilistichespiralidoso";

    for (int i = 0; i < DIM; i++) {
        short n = 3 + rand() % 10;
        if (rand() % 2 == 0)
            vett[i] = new B(n, S);
        else
            vett[i] = new C(n, S, (char)(rand() % ('z' - 'a' + 1) + 'a'));
    }

    //Punto (1)
    cout << "PUNTO 1" << endl;
    for(int i = 0; i < DIM; i++) {
        cout << i << ")" << *vett[i];
    }

    //Punto (2)
    cout << "PUNTO 2" << endl;
    string s = "";
    for(int i = 0; i < DIM; i++) {
        if(typeid(*vett[i]) == typeid(C)) {
            //s += (dynamic_cast<C*>(vett[i]))->g('h');
            s += ((C*)(vett[i]))->g('h');
        }
    }
    cout << "concat=" << s << endl;

    //Punto (3)
    cout << endl << "PUNTO 3" << endl;
    cout << "*vett[5]=" << *vett[5];
    cout << "vett[5](1, 3)=" << (*vett[5])(1, 3) << endl << endl;

    //Extra
    (*((B*)vett[5]))++;
    (*vett[5])[1] = 'b';
    cout << *vett[5] << endl;
    
    cout << *vett[6] << endl;

    cout << (*vett[5]) + (*vett[6]) << endl;
}