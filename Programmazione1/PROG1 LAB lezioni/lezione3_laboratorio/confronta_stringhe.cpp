#include<iostream>
#include<string>

using namespace std;

int main() {
    string s1 = "Hello World"; //Hello World
    string s2 = "pippoow"; //hl rld

    // string s1 = "Hello World";
    // string s2 = "hl rld";

    for(char c1: s1) {
        for (char c2: s2) {
            if(c1==c2) {
                cout << c1;
                break;
            }
        }
    }

    cout << endl;

    // Stampare i caratteri della stringa s1 che siano contenuti anche in s2 nell'ordine in cui appaiono in s1
    // oo

    for (int i =0; i<s1.length(); i++) {
        bool found = false;
        //inizia la ricerca
        for (int j=0; j<s2.length() && !found; j++) {
            if(s1[i]==s2[j]) {
                cout << s1[i];
                found = true;
            }
        }
    }
}