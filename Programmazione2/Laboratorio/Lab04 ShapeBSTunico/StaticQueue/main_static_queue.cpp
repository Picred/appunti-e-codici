#include "static_queue.h"

int main(){
    StaticQueue<int> coda(10);
// coda.dequeue(); //test empty queue
    coda.enqueue(1);
    coda.enqueue(2);
    coda.enqueue(3);
    coda.enqueue(4);
    coda.enqueue(5);
    coda.enqueue(6);
    coda.enqueue(7);
    coda.enqueue(8);
    coda.enqueue(9);
    coda.enqueue(10);
    // coda.enqueue(2); //test full queue
    
    cout << coda << endl;

    coda.dequeue();coda.dequeue();coda.dequeue();coda.dequeue();coda.dequeue();coda.dequeue();coda.dequeue();
    coda.dequeue();coda.dequeue();

    coda.enqueue(74);coda.enqueue(75);coda.enqueue(76);coda.enqueue(77);coda.enqueue(78);coda.enqueue(79);
    coda.enqueue(80);

    coda.dequeue(); coda.dequeue();
    coda.enqueue(0); coda.enqueue(257);
    //test print
    cout << "\n\n\n" << coda << endl;
}