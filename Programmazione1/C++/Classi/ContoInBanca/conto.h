#ifndef CONTO_H
#define CONTO_H

#include <string>

using namespace std;

class Conto {
    private:
        string proprietario;
        int numero_conto;
        double giacenza;
    public:
        Conto(string,int,double);
        Conto(string,int);

        //getter
        string getProprietario();
        double getGiacenza();
        int getNumeroconto();

        void preleva(double);
        void versa(double);
        void paga_imposta();
        void paga_mese();

};


#endif