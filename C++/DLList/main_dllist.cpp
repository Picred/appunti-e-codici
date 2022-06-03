#include "dllist.h"

int main(){
    DLList<int> list;

    list.insertDecrescente(10);
    list.insertDecrescente(17);
    list.insertDecrescente(13);
    list.insertDecrescente(18);

    cout << list;

    list.insertHead(69);
    cout << "\n\n\n\n";
    cout << list;
    
}