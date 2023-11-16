#include <cstdlib>
#include "random.h"
#include<iostream>
#include<ctime>

using namespace std;

Random::Random() {srand(time(0));}
Random::Random(time_t x) {srand(x);}
Random::Random(long long x){srand(x);}

void Random::generateDouble(double a, double b){
    valore= a + (double)(rand()) / ((double)(RAND_MAX/(b - a))); //fonte web
}

void Random::generateInt(int a, int b){
    valore=rand()%(b-a+1)+a;
}

double Random::getValore(){return valore;}

void Random::stampaValore(){
    cout << valore << endl;
}
