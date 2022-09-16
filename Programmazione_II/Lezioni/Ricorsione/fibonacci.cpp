#include<iostream>

using namespace std;


int fib(int n){
    if (n==0 || n==1){ //caso base
        return 1;
    }
    return fib(n-1)+fib(n-2); //passo induttivo
}

//sequenza di fibonacci 1 1 2 3 5 8 13 21 ...
int fibonacci_iterativa(int n){ //senza ricorsione
    if (n==0 || n==1){ 
        return 1;
    }

    //sum1 rappresenta il valore della sequenza di fibonacci fino a alla i-1esima iteazione
    //sum2 rappresenta il valore della sequenza di fibonacci fino a alla i-2esima iteazione
    int sum1 = 1,sum2 = 1,x;

    for(int i=2; i<=n; i++){ //si parte da 2 perchè già i casi base 0 e 1 sono già stati controllati con l'if a riga 14
        x=sum2;
        sum2=sum1;
        sum1=x+sum1;
    }
    return sum1;

}


int main(){
    int fib2=fibonacci_iterativa(2);
	int fib3=fibonacci_iterativa(3);
	int fib10=fibonacci_iterativa(10);
	
	cout << "il secondo fibonacci e':" << fib2 << endl;
	cout << "il terzo fibonacci e':" << fib3 << endl;
	cout << "il decimo fibonacci e':" << fib10 << endl;

	return 0;
}