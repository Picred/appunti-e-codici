#include<iostream>
#include<string>

using namespace std;
int main() {
    //int x = 3; //011 -> 1+2+0 = 3
    //int y = 4; //100 -> 0+0+4 = 4

    // OR
    // 011 |
    // 100 |
    // 111 -> 1 + 2 + 4 = 7

    // XOR
    // 011 ^
    // 100
    // 111

    //int i = 3; //011 -> 1+2+0 = 3
    //int j = 5; //101

    // XOR
    // 011 ^
    // 101
    // 110 -> 0 + 2 + 4 = 6

    //unsigned int h = 3; //011 ->

    //~011 = 100
    //~00000000...11 -> 1111111111..00

    //unsigned int l = -4;

    //cout << ~h << endl;
    //cout << l;

    // << >>

    // 3 -> 011 -> 110 -> 6
    //cout << (3<<1) << endl;
    // 3 -> 011 -> 1100 -> 12
    //cout << (3<<2) << endl;
    // 3 -> 011 -> 001 -> 1
    //cout << (3>>1) << endl;


    //float x = 2.49;
    //int y = (int) x;
    //int z = int(x);
    //int w = static_cast<int>(x);

    //cout << y << endl;
    //cout << z << endl;
    //cout << w << endl;

    //cout << float(3)/2;
    // cout << 3.0/2;

    //float x = 2.3;
    //cout << sizeof(x);

    //int x = (2+3)*3; //2+3*3
    // 2+(3*3) -> 2+3*3
    // 2+(3*3)+(5*5)+(7*7)

    string space = " ";
    string x= "acc";
    string y = "acc";

    cout << (y==x);
}