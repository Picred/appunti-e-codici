#include<iostream>
#include<string>

using namespace std;

int main() {
    int x = 0;

    while(x<10)
        cout << ++x << " ";

    for(int i = 0; i<10; i++) {
        cout << (i+1) << " ";
    }

    cout << endl;

    string s = "Hello World";

    for(int i=0; i<s.length(); i++)
        cout << s[i] << " ";
}