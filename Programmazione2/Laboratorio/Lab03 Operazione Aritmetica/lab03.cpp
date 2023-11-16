#include <iostream>
#include <cstdlib>
#include "static_stack.h"
#include "queue.h"
#include <ctime>


using namespace std;

class OperazioneAritmetica{
    protected:
        double opSx;
        double opDx;
        char symbol = ' ';
        
     public:
        OperazioneAritmetica(double sx=0.0,double dx=0.0) : opSx(sx), opDx(dx){}
        
        virtual ostream& put(ostream& os){
            os << this->opSx << this->symbol << this->opDx;
            return os;
        }

        void setSx(double sx){
            this->opSx=sx;
        }

        void setDx(double dx){
            this->opDx=dx;
        }

        virtual double eseguiCalcolo()=0;
};

class Addizione : public OperazioneAritmetica{
    public:
        Addizione() : OperazioneAritmetica(){
            this->symbol='+';
        }

        double eseguiCalcolo(){
            // cout << "Eseguo Addizione" << endl;
            cout << opSx << symbol << opDx << "=";
            return opSx+opDx;
        }

};

class Sottrazione : public OperazioneAritmetica{
    public:
        Sottrazione() : OperazioneAritmetica(){
            this->symbol='-';
        }

        double eseguiCalcolo(){
            // cout << "Eseguo Sottrazione" << endl;
            cout << opSx << symbol << opDx << "=";
            return opSx-opDx;
        }
        
};

class Moltiplicazione : public OperazioneAritmetica{
    public:
        Moltiplicazione() : OperazioneAritmetica(){
            this->symbol='*';
        }

        double eseguiCalcolo(){
            // cout << "Eseguo Moltiplicazione" << endl;
            cout << opSx << symbol << opDx << "=";
            return opSx*opDx;
        }

};

class Divisione : public OperazioneAritmetica{
    public:
        Divisione() : OperazioneAritmetica(){
            this->symbol='/';
        }

        double eseguiCalcolo(){
            // cout << "Eseguo Divisione" << endl;
            cout << opSx << symbol << opDx << "=";
            return opSx/opDx;
        }
};

ostream& operator<<(ostream& os, OperazioneAritmetica& op){
    return op.put(os);
}


int main(){

    srand(time(0));
    int N;
    
    cout << "inserisci il numero di operazioni da svolgere: ";
    cin >> N;

    StaticStack<OperazioneAritmetica*> operazioni(N);

    //generazione di operazioni random
    while (!operazioni.isFull()){
        int r=rand()%4;
        OperazioneAritmetica* operazione=nullptr;
        switch (r){
        case 0:
            operazione=new Addizione();
            break;
        case 1:
            operazione=new Sottrazione();
            break;
        case 2: 
            operazione=new Moltiplicazione();
            break;
        case 3: 
            operazione=new Divisione();
            break;
        }
        operazioni.push(operazione);
    }

    cout << "Ecco le operazioni:" << endl;
    cout << operazioni<< endl;

    //generazione di double random
    Queue<double> codaValori;
        
        for (int i=0; i<2*N; i++){
            double r1= (double) ((rand()) /( (double)((RAND_MAX/(1000)))));

            codaValori.enqueue(r1);
        } 

    cout << "Ecco gli operandi:" << endl;
    cout << codaValori << endl;

    //eseguo le operazioni
        int i=0;
        while(!codaValori.isEmpty() && !operazioni.isEmpty()){
            OperazioneAritmetica* op=operazioni.pop();
            //ho estratto un'operazione, adesso estraggo i 2 double
            double op1=codaValori.dequeue();
            double op2=codaValori.dequeue();
            i++;

            op->setDx(op1);
            op->setSx(op2);
            cout << "operazione " << i << "---> " << op->eseguiCalcolo() << endl << endl;
        }
}