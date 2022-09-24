#include <iostream>

using namespace std; 

class RuotaFortunata{

  private:
    int valoreCorrente;
    int *possibiliVal;
    short numPossVal; 

  public:
    RuotaFortunata(); // costruttore 
    RuotaFortunata(int num, int min, int max); //costruttore 
    RuotaFortunata(int num, int *v); // costruttore 
    ~RuotaFortunata(); // distruttore 

    void gira(); 
    int getValoreCorrente(); 
    int getNumPossibiliVal(); 
    int *possibiliValori(); //restituisce la lista dei possibili valori 

    //C++11
    //static constexpr int DEFAULT_NUM_VALUES = 10;
    //static constexpr int DEFAULT_MIN_VALUES = 1;
    //static constexpr int DEFAULT_MAX_VALUES = 10;

    //C++98
    const static int DEFAULT_NUM_VALUES = 10;
    const static int DEFAULT_MIN_VALUES = 1;
    const static int DEFAULT_MAX_VALUES = 10;
};
