#include <iostream>
#include <string>

using namespace std;

bool palindroma(string s){
    
    int low=0;
    int high=s.length()-1;

    while (s[low] == s[high] && low<=high){
        low++;
        high--;
    }

    if (s[low] == s[high]){
        return true;
    } else {
        return false;
    }
}


int main (){
    string p="itopinonavevanonipoti";

    if (palindroma(p)){
        cout << "palindroma";
    } else {
        cout << "non palindroma";
    }
    
    return 0;
}