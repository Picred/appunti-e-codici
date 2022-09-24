#ifndef RANDOM_H
#define RANDOM_H

#include <ctime>
#include<cstdlib>

class Random{
    private:
        double valore;

    public:
        Random();// default: imposta un seed dipendente dall'ora attuale
        Random(time_t);
        Random(long long); //imposta un seed deterministico dato in input
        void generateDouble(double,double);
        void generateInt(int,int);
        double getValore();
        void stampaValore();
};

#endif