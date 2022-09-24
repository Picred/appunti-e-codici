#include<iostream>
#include<string>
using namespace std;

int main() {
    string s = "abzczba";

    // 0 1 2
    // 5 4 3

    int low=0;
    int high=s.length()-1;

    int hlen=0;

    while((s[low]==s[high]) && (low<=high)) {
        low++;
        high--;
        hlen++;
    }

    if(s[low]==s[high]) {
        cout << "stringa palindroma"<<endl;
    } else {
        cout << "stringa non palindroma"<<endl;
    }
}
// abcba
// 0 1 2 3
// 4 3 2 1