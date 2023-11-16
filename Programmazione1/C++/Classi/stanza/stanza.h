#ifndef STANZA_H
#define STANZA_H

#include <string>

using namespace std;

class Stanza{
    private:
        string nome;
        double lunghezza;
        double larghezza;
    public:
        Stanza(string,double, double);
        double superficieStanza();
        void sommarioStanze();
};
#endif