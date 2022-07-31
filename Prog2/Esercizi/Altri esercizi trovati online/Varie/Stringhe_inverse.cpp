#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void inversa(string str, int cont,int n, ostream& out){
	if(cont==n){
		out << str[cont];
		return;
	}
	inversa(str,cont+1,n,out);
	out << str[cont];
}

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");

	int n;
	while(in >> n){
		//cout << n;
		string b;
		string uno;
		in >> uno;
		string due;
		in >> due;
		string tre;
		in >> tre;
		inversa(uno,0,n-1,out);
		out << " ";
		inversa(due,0,n-1,out);
		out << " ";
		inversa(tre,0,n-1,out);
		out << " ";
		out << endl;	
	}
	in.close();
	out.close();

	return 0;
}


