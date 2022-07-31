#include <iostream>
#include <fstream>
using namespace std;

//	e a 6 alcide 6 alvise 8 salomone
//	           ^ 
int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");

	for(int task=0; task<100; task++){
		char a, b;
		in >> a >> b;
		int n;
		in >> n;
		string primo;
		in >> primo;
		in >> n;
		string secondo;
		in >> secondo;
		in >> n;
		string terzo;
		in >> terzo;

		bool p = false;
		bool s = false;
		if(a == primo[0] || a == primo[primo.length()-1]) p = true;
		if(b == primo[0] || b == primo[primo.length()-1]) s = true;
		if(p && !s) out << primo << " "; 

		p = false;
		s = false;
		if(a == secondo[0] || a == secondo[secondo.length()-1]) p = true;
		if(b == secondo[0] || b == secondo[secondo.length()-1]) s = true;
		if(p && !s) out << secondo << " "; 

		p = false;
		s = false;
		if(a == terzo[0] || a == terzo[terzo.length()-1]) p = true;
		if(b == terzo[0] || b == terzo[terzo.length()-1]) s = true;
		if(p && !s) out << terzo << " "; 
						           
		out << endl;
	}
	in.close();
	out.close();

	return 0;
}