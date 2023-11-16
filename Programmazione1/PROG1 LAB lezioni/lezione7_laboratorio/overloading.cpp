#include<iostream>
#include<string>
#include<sstream>
using namespace std;

string concat(string s1, string s2) {
    return s1 + s2;
}

string concat(string s1, string s2, string s3) {
    return s1 + s2 + s3;
}

string concat(string s1, char c) {
    return s1 + c;
}

string concat(char c, string s1) {
    return c + s1;
}

string concat(string s1, int x) {
    stringstream ss;
    ss << s1 << x;
    return ss.str();
}

/*int concat(int y, int x) {
    return x + y;
}*/

string concat(int y, int x) {
    stringstream ss;
    ss << y << x;
    return ss.str();
}

int main() {
    string s1 = "Hello ";
    string s2 = "World";

    cout << concat(s1,s2) << endl;
    cout << concat("Hello ", 'w') << endl;
    cout << concat('w', " Hello") << endl;
    cout << concat("Hello ", 2) << endl;
    cout << concat("Hello", " ", "World") << endl;

    cout << concat(2,3);
}