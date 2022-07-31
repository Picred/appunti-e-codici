#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void consonanti(string str, string &vuota, int n){
	if(n == str.length()) return;
	switch(str[n]){
		case 'a':
			break;
		case 'e':
			break;
		case 'i':
			break;
		case 'o':
			break;
		case 'u':
			break;
		default:
			vuota += str[n];
			break;
	}
	return consonanti(str,vuota,n+1);

}

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n;
	while(in >> n){
		
		string uno;
		in >> uno;
		string due;
		in >> due;
		string tre;
		in >> tre;
		string vuota;

		consonanti(uno,vuota,0);

		out << vuota << " ";
		vuota = {};

		consonanti(due,vuota,0);

		out << vuota << " ";
		vuota = {};

		consonanti(tre,vuota,0);

		out << vuota << " ";
		vuota = {};

		out << endl;
	}
	in.close();
	out.close();
	return 0;
}