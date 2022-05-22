#include "list.h"

int main(){
    List<int> list;

    cout << list;

    list.insertHead(1);
    list.insertHead(2);
    list.insertHead(3);
    list.insertHead(4);

    cout << list;

    list.removeHead();

    cout << endl;
    cout << list;
}