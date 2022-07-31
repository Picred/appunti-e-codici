#include <iostream>
#include <fstream>
using namespace std;


int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");

	string str;
	while(getline(in,str)){

		string vocali;
		for(int i=0; i<19; i++){
			if(str[i] != ' ' && str[i] != ':') vocali += str[i];
			
		}

		string ordine;
		for(int i=1; i<vocali.length();i+=2){
			ordine += vocali[i];
		}

		string ciclo;
		for(int i=20; i<str.length(); i++){
			ciclo += str[i];
		}
		
		for(int i=0; i<ciclo.length(); i++){
			switch(ciclo[i]){
				case 'a':
					ciclo[i] = ordine[0];
					break;
				case 'e':
					ciclo[i] = ordine[1];
					break;
				case 'i':
					ciclo[i] = ordine[2];
					break;
				case 'o':
					ciclo[i] = ordine[3];
					break;
				case 'u':
					ciclo[i] = ordine[4];
					break;
				default:
					break;
			}
		}
		out << ciclo << endl;
	}
	in.close();
	out.close();
	return 0;
}
