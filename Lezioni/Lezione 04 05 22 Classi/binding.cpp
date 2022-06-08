#include <iostream>

using namespace std;

class A{
    private:
        virtual void private_fun(){
            cout << "Private function di A" << endl;
        }

    public:
        A(){ cout << "costruttore di A" << endl;}
     virtual void stampa(){
            cout << "sono la classe A" << endl;
        }
        void foo (){
            cout << "sono foo di A" << endl;
        }

        void call_private_virtual(){
            private_fun();
        }
};

class B : public A{
    public: 
        B(){cout << "costruttore di B" << endl;}
        void stampa(){
            cout << "sono la classe B" << endl;
        }
        void foo(){
            cout << "sono foo di B" << endl;
        }

        void call_private_virtual(){cout << "call_private_virtual di B " << endl;}
        
};

int main(){
    A a;
    B b;
    cout << "chiamata ai metodi delle istanze di A e B" << endl;
    
    a.stampa();
    b.stampa();
    b.foo();
    cout << endl;
    // B c;
    // c.stampa();
    
    //uso i puntatori ora
    cout << "Creo dei riferimenti di a e b e dichiaro entrambi di classe A&" << endl;
    A& ra=a;
    A& rb=b;
    
    ra.stampa();
    rb.stampa(); //out: la stampa di classe A //con virtual la stampa di classe B
    rb.foo(); //funzione no virtual
    //puntatori ora?
    cout << endl;
    cout << "creo dei puntatori ad A ed assegno ciascuno l'indirizzo di a e b" << endl;
    A *pa=&a;
    A *pb=&b;

    pa-> stampa();
    pb -> stampa(); //viene chiamata sempre stampa di A perchè non è detto da nessuna parte che deve essere riscritta con "virtual"
                    //con virtual stampa la classe B
    pb->foo(); //funzione no virtual

    b.call_private_virtual();
}
