namespace alpha{
  
  class ClasseX{
    int k; 

    public:
      ClasseX(int a); 
      int getK();
  } ;
}

//eventualmente in un file .cpp
int alpha::ClasseX::getK(){
  return k; 
}

alpha::ClasseX::ClasseX(int a){
  this->k = a; 
}
