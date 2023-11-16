#ifndef DADO_H
#define DADO_H

#include<cstdlib>

class Dado{
    private:
        short valore;
    public:
        Dado();
        short getValore();
        void lanciaDado();
};

#endif