#ifndef BAGNO_H
#define BAGNO_H

#include "stanza.h"

class Bagno{
    private:
        double base;
        double altezza;
        string s1="Bagno";
    public:
        Bagno(double,double);
        double superficieBagno();
        void sommarioBagno();
};  

#endif