#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream in("input.txt");
	ofstream out("output.txt");

	string str;
	while (getline(in, str))
       {
       		int n = 26;
   			int a[n] = {0};
   			char car[n] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}; 

   		for(int i=0; i<str.length(); i++){
   			switch(str[i]){
   				case 'a':
   					a[0] += 1;
   					break;
   				case 'b':
   					a[1] += 1;
   					break;
   				case 'c':
   					a[2] += 1;
   					break;
   				case 'd':
   					a[3] += 1;
   					break;
   				case 'e':
   					a[4] += 1;
   					break;
   				case 'f':
   					a[5] += 1;
   					break;
   				case 'g':
   					a[6] += 1;
   					break;
   				case 'h':
   					a[7] += 1;
   					break;
   				case 'i':
   					a[8] += 1;
   					break;
   				case 'j':
   					a[9] += 1;
   					break;
   				case 'k':
   					a[10] += 1;
   					break;
   				case 'l':
   					a[11] += 1;
   					break;
   				case 'm':
   					a[12] += 1;
   					break;
   				case 'n':
   					a[13] += 1;
   					break;
   				case 'o':
   					a[14] += 1;
   					break;
   				case 'p':
   					a[15] += 1;
   					break;
   				case 'q':
   					a[16] += 1;
   					break;
   				case 'r':
   					a[17] += 1;
   					break;
   				case 's':
   					a[18] += 1;
   					break;
   				case 't':
   					a[19] += 1;
   					break;
   				case 'u':
   					a[20] += 1;
   					break;
   				case 'v':
   					a[21] += 1;
   					break;
   				case 'w':
   					a[22] += 1;
   					break;
   				case 'x':
   					a[23] += 1;
   					break;
   				case 'y':
   					a[24] += 1;
   					break;
   				case 'z':
   					a[25] += 1;
   					break;
   				default:
   					break;

   			}
   		}

   		int mas = a[0];
   		int index = 0;
   		for(int i=1; i<n; i++){
   			if(a[i] >= mas){
   				mas = a[i];
   				index = i;
   			}
   		}

   		out << car[index] << " " << mas;

        out << endl;   

       }
    in.close();
    out.close();

    return 0;

}