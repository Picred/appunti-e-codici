#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main(){
	stringstream ss;
    

	//int x;

    //cout << "Inserisci un valore: ";
    //cin >> x;

    //ss << "Il valore inserito e' ";
    //ss << x;

    //ss.str("");
	
	//cout << ss.str();

    string s;

    cout << "Inserisci un valore: ";
    cin >> s;

    double x;

    ss.str(s);

    ss >> x;

    cout << x + 2;
}