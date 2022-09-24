#include<iostream>
#include<string>

using namespace std;

int main() {
    
    int x = 1;

    loop:

    cout << x << " ";
    x++;

    if(x<=10)
        goto loop;


    
}