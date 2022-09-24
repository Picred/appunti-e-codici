#include <iostream>

using namespace std;

int main (){

    int a, b, c;
    int max=0;

   cin >> a >> b >> c;
    if (a>b){
        max=a;
    }
    else
    {
        max=b;
    }

    if (max<c){
        max=c;
    }
    cout << max;
}