#include <string>

namespace beta{
  
  class ClasseY{
    std::string s; 

    public:
      ClasseY(std::string s); 
      std::string getS();
  };
}

//eventualmente in un file 
// cpp separato 
std::string beta::ClasseY::getS(){
  return s; 
}

beta::ClasseY::ClasseY(std::string s){
  this->s = s; 
}
