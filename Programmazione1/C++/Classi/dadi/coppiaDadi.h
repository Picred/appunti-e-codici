#ifndef COPPIADADI_H
#define COPPIADADI_H

#include "dado.h"
#include<cstdlib>
#include<ctime>
#include<iostream>

using namespace std;

class CoppiaDadi{
    private:
        Dado d1;
        Dado d2;
    public:
        CoppiaDadi();
        void lanciali();
        void vediDadi();
        
};

#endif