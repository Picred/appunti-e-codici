#include<iostream>
#include<cmath>

using namespace std;

int main() {
    //cout << sqrt(2) << endl; //radice quadrata di due
	//cout << cbrt(3) << endl; //radice cubica di tre
	//cout << pow(2,3) << endl; //2 elevato 3
	//cout << sin(M_PI) << endl; //seno di Pi greca
	//cout << cos(2*M_PI); //coseno di 2*Pi greca

    std::cout << round(2.2) << std::endl; //2
    std::cout << round(2.6) << std::endl; //3
    std::cout << round(2.5) << std::endl << std::endl; //2

    std::cout << floor(2.2) << std::endl; //2
    std::cout << floor(2.6) << std::endl; //2
    std::cout << floor(2.0) << std::endl << std::endl; //2

    std::cout << ceil(2.2) << std::endl; //3
    std::cout << ceil(2.6) << std::endl; //3
    std::cout << ceil(2.0) << std::endl; //3
}