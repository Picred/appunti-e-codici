#include "Huffman.cpp"

int main()
{
	char chars[] = { 'f', 'e', 'c' , 'b', 'd', 'a'};	
	int freq[] = {5, 9, 12, 13, 16, 45};
	string s = "adea";
	HuffmanCode huff  (chars, freq, *(&freq + 1) - freq);
	huff.printCodes();
	string code = huff.encode(s);
	cout << "The encode of " << s << " is " << code << endl;
	string message = "110010000"; //fcaa
	string encode = huff.decode(message);
	cout << "The decode of " << message << " is " << encode << endl;
	return 0;
}





