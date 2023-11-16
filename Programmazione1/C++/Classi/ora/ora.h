#ifndef ORA_H
#define ORA_H

class Ora {
    private:
        int ora;
        int minuti;
        int secondi;
    public:
        Ora(); //costruttore che inizia a 0 di default le variabili
        Ora(int,int,int); //costruttore che inizializza le variabili secondo l input

        void orologio_12h();
        void aumenta_tempo(Ora);
        int getOra();
        int getMin();
        int getSec();
        void orologio();



};


#endif