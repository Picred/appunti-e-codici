#include <iostream>

using namespace std; 

class ClasseX{

  int x,y,z; 

  public:

    ClasseX(int x, int y, int z){
      this->x = x;
      this->y = y;
      this->z = z;
    }

    int getX() const{ //metodo const non pu\`o modificare stato oggetto! 
//      setY(10); //errore del compilatore
      return this->x; 
    }

    int getY() const{ //metodo const non pu\`o modificare stato oggetto! 
      //setY(10); //errore del compilatore
      return this->y; 
    }

    int getZ() const{ //metodo const non pu\`o modificare stato oggetto! 
      //setZ(10); //errore del compilatore
      return this->z; 
    }

    void setX(int a){
      this->x = a; 
    }

    void setY(int a) {
      this->y = a; 
    }

    void setZ(int a){
      this->z = a; 
    }

};

int main(){

  ClasseX test(10,20,30); 

  cout << test.getX() << ", " << test.getY() << ", " << test.getZ() << endl; 

}
