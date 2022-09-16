#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");

	for(int task=0; task<100; task++){
		int n;
		in >> n;

		string primo;
		in >> primo;
	
		string secondo;
		in >> secondo;

		string terzo;
		in >> terzo;

		int c1 = 0;
		int c2 = 0;
		int c3 = 0;
		for(int i=0; i<n; i++){
			if(primo[i]==secondo[i]) c1++;
			if(primo[i]==terzo[i]){
				c2++;
			}
		}
		for(int i=0; i<n; i++){
			if(secondo[i]==terzo[i]) c3++;
		} 

		if(c1==n && c2==n) out << primo << " " << secondo << " " << terzo;
		else if(c1==n){
			out << primo << " " << secondo;
		}
		else if(c2==n){
			out << primo << " " << terzo;
		}
		else if(c3==n){
				out << secondo << " " << terzo << " ";
		}
		out << endl;
	}
	in.close();
	out.close();

	return 0;
}