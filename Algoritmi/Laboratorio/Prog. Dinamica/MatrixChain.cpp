#include <iostream>
#include <vector>
#include <string>
using namespace std;


void printIterativeParentheses(vector<vector<int>>& input){
	if (input.size() <= 1){
		cout << "Error" << endl;
		return;
	}
	vector<int> stack;
	string acc ("");
	
	stack.push_back(0);
	stack.push_back(input.size() -  1);	
	while (!stack.empty())
	{		
		size_t i = stack.back();
		stack.pop_back();
		switch (i)
		{
		 case -1: acc='('+acc;  break;
		 case -2: acc=')'+acc;  break;
		 case -3: acc='x'+acc; break;
		 default:		
			size_t j = stack.back();
			stack.pop_back();
			if (i == j)
			{				
				acc=to_string(i)+acc;
			}
			else
			{
				stack.push_back(-1);
				stack.push_back(j);
				stack.push_back(input[i][j]);
				stack.push_back(-3);
				stack.push_back(input[i][j] + 1);
				stack.push_back(i);
				stack.push_back(-2);
			}
			break;			
		}
		
	}
	cout << acc<<endl;
	
}


void printRecursiveParentheses(vector<vector<int>>& input, size_t i, size_t j)
{
	if (i == j)
		cout << i;
	else
	{
		cout << "(";
		printRecursiveParentheses(input, input[i][j], j);
		cout << "x";
		printRecursiveParentheses(input, i, ((size_t) input[i][j] + 1));
		cout << ")";
	}
}

void printRecursiveParentheses(vector<vector<int>>& input)
{	
	if(input.size()>1)
	 printRecursiveParentheses(input, input.size() - 1, 0);
}

int matrixChainMultiplyLookUp(vector<int>& chain, vector<vector<int>>& lookUpTable){
	if (chain.size() < 2)
		return -1;
	size_t chain_length = chain.size() - 1; //dimensione della matrice righexcolonn, n posizioni, e per ognuno n vettori con n posizioni (n=size);
	lookUpTable = vector<vector<int>>(chain_length, vector<int>(chain_length));
	for (int i = 0; i < chain_length; i++)
		lookUpTable[i][i] = 0;
	for (size_t lenCount = 1; lenCount < chain_length; lenCount++)
	{
		for (size_t i = 0; i < chain_length - lenCount; i++)
		{
			size_t j = i + lenCount; //size_t indica che l'intero è a 32 bit piuttosto che a 64 (come int). int è troppo grande per indicizzare il "vector" 
			lookUpTable[i][j] = INT_MAX;
			for (size_t k = i; k < j; k++)
			{
				int q = lookUpTable[i][k] + lookUpTable[k + 1][j] + chain[i] * chain[k + 1] * chain[j + 1]; //trovo il minimo  k calcolato. 
				if (q < lookUpTable[i][j]) //minimizzo?
				{
					lookUpTable[i][j] = q; //salvo il valore allora
					lookUpTable[j][i] = k;
				}
			}
		}
	}
	return lookUpTable[0][chain_length - 1]; //valore della soluzione ottima, angolo in alto a sx della matrice 
}


int main()
{	
  vector <int> chain = vector<int>{ 5, 1, 3, 12 , 5,  50, 6 };
  vector<vector<int>> lookUpTable;	
  int operations= matrixChainMultiplyLookUp(chain, lookUpTable);	
  cout << "Number of operations:" << operations << endl;	
  cout << "LookUp Cost Table:" << endl;
  for (int i = 0; i < lookUpTable.size(); i++)
	{
		for (int j = 0; j < lookUpTable.at(i).size(); j++)
			cout << lookUpTable.at(i).at(j) << " ";
		cout << endl;
	}		
	printRecursiveParentheses(lookUpTable);
	cout << endl;
	printIterativeParentheses(lookUpTable);	
}








