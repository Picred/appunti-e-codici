#include<iostream>
#include<string>

using namespace std;

int main() {
    string s("Hello World");

    // 8 -> 11 [9, 10, 11]
    //         [8, 9, 10]
    // 11-3 = 8

    //string subs = s.substr(3, 5);
    //cout << subs;

    //cout << s.substr(3, 5) << endl;

    //cout << s.length() << endl;
    //int n = s.length();

    //string subs2 = s.substr(n-3, 3);

    //cout << subs2 << endl;

    // int p = 5;
    // cout << s.substr(s.length()-p, p) << endl;

    // cout << s.size();

    // string s3 = "";

    cout << s.substr(s.length(),10) << endl;
    //cout << s.substr(s.length()+10, 2);
    cout << s.substr(5, 500);

}