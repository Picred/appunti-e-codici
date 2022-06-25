#include "list.h"

int main() {
    List<int> list;

    cout << "----------Inserisco in testa 50 40 30 20 10 0 e stampo----------" << endl;

    list.insertHead(50);
    list.insertHead(40);
    list.insertHead(30);
    list.insertHead(20);
    list.insertHead(10);
    list.insertHead(0);

    cout << list << endl;

    system("pause");

    cout << "----------Inserisco in coda 60 70 e stampo----------" << endl;

    list.insertTail(60);
    list.insertTail(70);

    cout << list << endl;
    system("pause");
    system("cls");
    cout << "----------Inserisco in modo crescente 37 e 8 in modo decrescente e stampo----------" << endl;

    list.insertCrescente(37);
    list.insertDecrescente(8);

        cout << list << endl;
    system("pause");
    cout << "----------Elimino due teste,una coda e il nodo 40 e stampo----------" << endl;

    list.removeHead();
    list.removeHead();
    list.removeTail();
    list.remove(40);

    cout << list;
}