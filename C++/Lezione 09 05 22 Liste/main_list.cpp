//creo una lista e inserisco 3 elementi al suo intenrno
#include "list.h"
#include "lnode.h"
#include "dllist.h"
#include "dlnode.h"

int main(){
    List<int> lista;
    List<int> listaNonOrdinata;

    lista.insertInOrder(10);
    listaNonOrdinata.insertHead(10);
    // cout << *lista.getHead() << endl;

    lista.insertInOrder(4);
    listaNonOrdinata.insertHead(4);
    // cout << *lista.getHead() << endl;

    lista.insertInOrder(-19);
    listaNonOrdinata.insertHead(-19);
    // cout << *lista.getHead() << endl;

    lista.insertInOrder(22);
    listaNonOrdinata.insertHead(22);
    
    cout << lista << endl;
    cout << listaNonOrdinata << endl;

cout << "RIMOZIONI" << endl;
    lista.removeHead();
    listaNonOrdinata.removeTail();
    cout << lista << endl;
    cout << listaNonOrdinata << endl;

    listaNonOrdinata.remove(-19);
    cout << listaNonOrdinata << endl;

DLList<int> lista;
    lista.insertHead(4);
    lista.insertHead(3);
    lista.insertHead(2);
    lista.insertHead(1);

    cout << lista;

    cout << "asodicjv" << endl;

    lista.remove(2);

    lista.insertInOrder(5);
    lista.insertInOrder(10);
    lista.insertInOrder(7);

    cout << lista;


}