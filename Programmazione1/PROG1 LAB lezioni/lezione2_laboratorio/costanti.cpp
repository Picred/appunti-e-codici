#include<iostream>
#include<string>
using namespace std;

#define PI 3.14

int main() {
    int x = (short)5;
    double y = (float)5.0;

    int z = 0L;

    float f = 1/3;

    char c = 'c';
    string s = "Stringa\
multiriga\
fine";

    char d = L'c';

    //string s2 = u"stringa";

    //cout << d;

    

    //cout << 1.0f/3;

    //auto var = 1.0f/3;

    std::string s3 = R"(String with \backslash and no \n escape)";
    std::string s4 = "String with \backslash and no \n escape";
    //std::cout << s4;

    const int h = 5;

    const float pi = 3.14;

    float r = 12.2;

    float area2 = pi * r * r; 

    float area = PI * r * r; // -> float area = 3.14 * r * r;

    cout << area << endl;
    
    cout << PI;

}