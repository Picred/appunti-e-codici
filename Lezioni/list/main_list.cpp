#include "list.h"

int main(){
    List<int> list;

    cout << list << endl << "inserisco in ordine il 10" << endl;

    list.insertCrescente(10);
    list.insertCrescente(17);
    list.insertCrescente(48);

    // cout << list;

    list.removeHead();

    // cout << endl << endl<< list << endl;

    list.insertTail(77);
    list.insertHead(47);

    cout << "\n\n" << list << endl;

    list.removeTail();
    cout << list;
}