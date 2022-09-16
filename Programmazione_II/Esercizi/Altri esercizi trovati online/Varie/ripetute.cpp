#include <iostream>
#include <fstream>
using namespace std;

void concatena(string st, ofstream& out){
	string full;
	full = st + st;
	out << full << endl;
}

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");

	for(int task=0; task<100; task++){
		string st;
		in >> st;

		concatena(st,out);
	
	}
	in.close();
	out.close();

	return 0;
}