#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <cmath>
#include <climits>
#define DIM 50

using namespace std;


class A{
    private:
        int *ptr;
        short len; // length
    public:
        A(short m, short k){
            this->len=m; 
            this->ptr= new int [m]; //
            for(int i=0; i<m; i++){
                ptr[i]=rand()%k+1; 
            }
        }

        virtual double const f()=0; //

        int get(short i){
            return ptr[i%len]; 
        }

        short getLen(){
            return this->len; 
        }
        
        //operatore << 
        //inizio punto 1 nella classe A
        virtual ostream& put(ostream& os){
            os << typeid(*this).name() << ", ptr=[ ";
            for(int i=0;i<getLen(); i++){
                os << ptr[i] << " ";
            }
            os << "],";
            return os;
        }

        int& operator[](int i){
            return this->ptr[i]; 
        }
};

//continuo punto 1
ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B:public A{
    private:
        double p; 
    public: //
        B(short m, short k, double y):A(m,k){
            this->p=y;
        }

        double const f(){
            double somma=0;
            double rapporto=0; 
            for(int i=0; i<getLen(); i++){
                if(get(i)%2==0){
                    somma+=get(i); 
                }
            }
             rapporto=somma/this->p; 
             return rapporto;
        }

        //punto 1 quando il typeid è B
        ostream& put(ostream& os) {
            A::put(os);
            os << " p=" << p;
            return os; 
        }
};

class C:public A{
    private:
        char x; 
    public: //
        C(short n, short k, char c):A(n,k){
            this->x=c; 
        }

        double const f(){
            double somma=0, contatore=0; 
            for(int i=0; i<getLen(); i++){
                if(get(i)%2!=0){
                    contatore++; 
                    somma+=get(i); 
                }
            }
            if(contatore==0){
                return 0;
            }
            return somma/contatore; 
        }

        string const g(char c){
            string s=""; 
            s=x; 
            string ritorno=s+c; 
            return ritorno; 
        }

        //punto 1 quando il typeid è B
        ostream& put(ostream& os) {
            A::put(os);
            os << " x=" << x;
            return os; 
        }
};

int main(){
    srand(111222333);
      A *vett[DIM];

    for(int i=0; i<DIM; i++){
	    short n=1+rand()%10;
	    short m = 1+rand()%8;
	if(rand()%2==0)
	  vett[i]= new B(n, m, rand()/(double) RAND_MAX+0.05);
	else
	  vett[i]= new C(n, m, (char) (rand()%('z' - 'a' + 1) + 'a'));
    }

    //Punto 1
    cout<<"Punto 1"<<endl; 
    for(int i=0; i<DIM; i++){
        cout<<i<<") "<< (*vett[i]) << ", f()=" << vett[i]->f()<<endl;
    }

    //Punto 2
    cout<<"Punto 2"<<endl;
    double media=0.0;
    string conc="";
    for(int i=0; i<DIM; i++){
        media+=(*vett[i]).f(); 
        if(typeid(*vett[i])==typeid(C)){
            conc+= (dynamic_cast<C*>(vett[i]))->g('h'); 
        }
    }
    cout<<"Avg(f())= "<<(media/DIM)<<", "<<conc<<endl; 

    //punto 3
    (*vett[0])[5]=1;
    cout<<"vett[5]="<<(*vett[0])[5]<<endl; 
    (*vett[0])[5]=-1;
    cout << "vett[5]=" << (*vett[0])[5] << endl;

    

}