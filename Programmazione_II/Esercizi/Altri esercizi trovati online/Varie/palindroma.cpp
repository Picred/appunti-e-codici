#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void quasi_pal(string str, string &vuota, int &num){
	int c = 0;
	int m = str.length();
	for(int i=0,j=str.length()-1; i<str.length()/2; i++,j--){
		if(str[i]!=str[j]) c++;
	}
	/*if(c < 2){
		num++;
		vuota += str + " "; 
	}*/
	return C;
}


int main(){

	ifstream in("input.txt");
	ofstream out("output.txt");

	int n;
	while(in >> n){
		string a;
		string vuota;
		int num = 0;

		for(int i=0; i<n; i++){
			in >> a;
			quasi_pal(a,vuota,num);
		}
		
		out << num << " " << vuota << endl;
	}
	in.close();
	out.close();

	return 0;
}