#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

void printResult(int vett[],int n,ofstream &out){
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(vett[i]>vett[j])
                    swap(vett[i],vett[j]);
        for(int i=0;i<n;i++)
            out<<vett[i]<<" ";
            out<<endl;
}

void Resto(int r,int* vett,int n, ofstream &out){
    int table[r+1];
    int s[r+1];
    table[0]=0;
    s[0]=0;
    for(int i=1;i<r+1;i++){
        table[i]=INT_MAX;
        s[i]=0;
    }
    for(int i=1;i<r+1;i++)
        for(int j=0;j<n;j++)
            if(vett[j]<=i){
                int sub_res=table[i-vett[j]];
                if(sub_res!=INT_MAX&&sub_res+1<table[i]){
                        table[i]=sub_res+1;s[i]=j;
                }
            }
    int k=r;
    int i=0;
    int result[table[r]];
    while(k>0){
            result[i]=vett[s[k]];
                i++;k=k-vett[s[k]];
    }
    out<<table[r]<<" ";
    printResult(result,table[r],out);
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    for(int i =0; i<100; i++){
        int r; in>>r;
        int n; in>>n;
        int*vett=new int[n];
        for(int j=0; j<n; j++)
            in>>vett[j];
            Resto(r,vett,n,out);
    }
}