#ifndef COMPLESSO_H
#define COMPLESSO_H

class Complesso{
    private:
        double r;
        double i;
    public:
        Complesso(double,double); //inizializza lo stato delle istanze
        void stampa(); //stampa il numero complesso

        double somma(Complesso);
        double sottrazione(Complesso);
        double prodotto(Complesso);
        double divisione(Complesso);
        //getter
        double getR();
        double getI();

};

#endif