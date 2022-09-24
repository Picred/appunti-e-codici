#include<iostream>

using namespace std;

int main() {
    int eta = 33;

    switch(eta) {
        case 33:
            cout << "Trentatre'";
            break;
        case 22:
            cout << "Ventidue";
            break;
        default:
            cout << "Altri numeri";
            break;
    }

    cout << endl;

    if(eta==33)
        cout << "Trentatre'";
    else if(eta==22)
        cout << "Ventidue";
    else
        cout << "Altri numeri";
}