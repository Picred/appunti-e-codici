#include<iostream>
#include<limits>

using namespace std;

int main() {
    int x;

    bool failure = false;
    do {
        cout << "Inserisci un numero: ";
        cin >> x;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Errore, il numero non e' valido!"<< endl;
            failure = true;
        } else {
            failure = false;

            if(x%2==0)
                cout << "Il numero e' pari";
            else
                cout << "Il numero e' dispari";
            
        }
    } while(failure);
}