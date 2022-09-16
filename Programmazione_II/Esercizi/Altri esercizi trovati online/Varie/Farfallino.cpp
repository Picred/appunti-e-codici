#include <iostream>
#include <fstream>
#include <string>
using namespace std;



int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");

	string str;
	while(getline(in,str)){
		string f;
		
		for(int i=0; i<str.length(); i++){
			switch(str[i]){
				case 'a':
					f += "afa";
					break;
				case 'e':
					f += "efe";
					break;
				case 'i':
					f += "ifi";
					break;
				case 'o':
					f += "ofo";
					break;
				case 'u':
					f += "ufu";
					break;
				
				default:
					f += str[i];
					break;
			}
		}

		out << f << endl;

	}
	in.close();
	out.close();

	return 0;
}
