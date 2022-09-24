#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main() {
    stringstream ss;
    string s("def");
    s += "abc";
    s += 'z';
    ss << s;
    int x= 2;
    ss << x;
    s = ss.str();
    cout << s << endl;
}