#ifndef SERBATOIO_H 
#define SERBATOIO_H

#include<string>
using namespace std;

class Serbatoio {
    private:
        double capienza;
        double carburanteContenuto;
    public:
        Serbatoio(string);
        double getCapienza();
        double getCarburanteContenuto();
        void inserisciCarburante(double);
        void consuma(double);
};

#endif