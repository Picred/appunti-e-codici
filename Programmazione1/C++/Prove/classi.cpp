#include <iostream>

using namespace std;

class gmf{

    public:
    void foo(){
        cout << "Ao!" << endl;
    }
    int foo2(int x){
        int y;
        y+=x*2;
        return y;
    }

};

int main(){

    gmf var;
    int var2;

    var2=var.foo2(2);
    cout << endl << var2;
}