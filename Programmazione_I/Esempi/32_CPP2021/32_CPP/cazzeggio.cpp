#include <iostream>

using namespace std;

void edit(int& x){
    x=10;
}

int main(){
    int i=0;

    int& ref_i=i;
    edit(ref_i);
    ref_i+=5;
    cout << ref_i << endl;
    cout << i;

}