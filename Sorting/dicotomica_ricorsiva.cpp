#include <iostream>

using namespace std;


bool dicotomica_ricorsiva(int* vett,int start, int end, int key){
    if(start==end && vett[start]==key){
        return true;
    }

    if(start>end){
        return false;
    }

    //start<end, unico caso rimasto
    int midpoint=(start+end)/2;

    if(vett[midpoint]==key){
        return true;
    }
    else if(key<vett[midpoint]){
        return dicotomica_ricorsiva(vett,start,midpoint,key);
    }
    else{
        return dicotomica_ricorsiva(vett,midpoint+1,end,key);
    }

    if(vett[midpoint]!=key)
        return false;
    return false;
}   

int main(){
    int vett[10];

    for(int i=0; i<10;i++){
        vett[i]=i;
    }

    cout << dicotomica_ricorsiva(vett,0,10-1,-47);
}