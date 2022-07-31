#include <iostream>
#include <fstream>
using namespace std;

bool stringa_pari(string st){
	if(st.length()%2 == 0) return 1;
	else return 0;
}

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");

	for(int task=0; task<100; task++){
		string st;
		in >> st;
		if(stringa_pari(st)) out << st;
		else for(int i=0; i<st.length()-1; i++) out << st[i];

		out << endl;
	}
	in.close();
	out.close();

	return 0;
}