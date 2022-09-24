#ifndef CONTO_CORRENTE_H
#define CONTO_CORRENTE_H

#include <string>
using namespace std;


//*******************
class ContoCorrente {
//*******************

public:  

   ContoCorrente (string nominativo, 
                  long numero, 
                  double primoDeposito);

   void setNominativo (string nominativo);
   string getNominativo() const;
   long getNumeroDiConto() const;
   double getSaldo() const;
   void deposita (double valore);
   void preleva (double valore);
   double maturaInteressi();
    
   friend ostream &operator<< (ostream &stream, ContoCorrente c);
   

private: 
        
   static constexpr double COSTO_OPERAZIONE = 1.50; // C++11
    // 
   //static const double COSTO_OPERAZIONE = 1.50; // C++98
   string nominativoCliente;
   long numeroDiConto;
   double saldo;

};   // End class ContoCorrente

#endif
