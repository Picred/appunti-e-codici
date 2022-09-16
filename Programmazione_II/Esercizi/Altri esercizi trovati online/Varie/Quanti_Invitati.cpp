#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void conta(string str, int n, int &c){
	if(n==str.length()) return;
	if(str[n]==' ') c+=1;
	return conta(str,n+1,c);
}

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");

	string str;
	while (getline(in, str)){
	/*	//cout << str << endl;
		int c = 0;
		for(int i=0; i<str.length(); i++)
			if(str[i] == ' ') c+=1;
		out << c+1 << endl;
	*/
		int c = 1;
		conta(str,0,c);
		out << c << endl;
	}
	in.close();
	out.close();

	return 0;

}
