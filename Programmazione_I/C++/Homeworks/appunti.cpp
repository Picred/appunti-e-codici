#include<iostream>

using namespace std;

int main(){
int x[3];

for (int i=0; i<3; i++)
    x[i]=i;

for (int xx : x)
    std::cout << " " << xx;

}