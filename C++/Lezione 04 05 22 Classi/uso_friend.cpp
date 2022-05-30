#include<iostream>

using namespace std;

class A{
    int n=10;

        friend void set_member(A& a, int val){
            a.n=val;
        }
    public:
        void set_n(int val){
            n=val;
        }

        void print_n(){cout << "n=" << n << endl;}

        friend ostream& operator <<(ostream& out, A& a){
            // out << this->n << endl; //errore
            out << a.n << endl;
            return out;
        }
};

int main(){
    A a;

    // a.set_n(20);
    set_member(a,15);
    a.print_n();
}