#include <iostream>
#include <fstream>
using namespace std;


int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");

	for(int task=0; task<100; task++){
		string st;
		in >> st;		
		int n = st.length()/2;

		for(int i=0; i<n; i++) out << st[i];
		
		out << endl;
	}
	in.close();
	out.close();

	return 0;
}