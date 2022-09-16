#include "queue.h"
#include"static_queue.h"

int main(){
    // Queue<int> q;

    // q.enqueue(10);
    // q.enqueue(12);
    // q.enqueue(14);
    // q.enqueue(16);

    // cout << q << endl << endl;
    // DLNode<int> ptr = q.dequeue();
    // cout << ptr << endl;
    // ptr=q.dequeue();
    // cout << ptr << endl;

    StaticQueue<int> sq(5);

    sq.enqueue(1);
    sq.enqueue(2);
    sq.enqueue(3);
    sq.enqueue(4);
    sq.enqueue(5);

    cout << sq << endl;
    
    sq.dequeue();
cout << "rimozione di un elemento" << endl;
    cout << sq << endl;

    sq.enqueue(6);

    cout << sq << endl;
}