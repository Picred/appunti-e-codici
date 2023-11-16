#include<ctime>

class Dado {
    private:
        short valore; //questo attributo contiene il valore attuale del dado
                      //si tratta del valore della faccia rivolta verso l'alto
    public:
        Dado(); //costruttore di default
        Dado(time_t); //costruttore alternativo che permette di impostare un particolare seed
        void lancia(); //lancia il dado
        short getValore(); //legge il valore del dado
};