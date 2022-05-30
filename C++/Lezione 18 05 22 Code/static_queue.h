#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H
#include<iostream>

#define MAX_SIZE 1000

template<typename T>
class StaticQueue {

    T* array;
    int size = 0;
    int maxSize = MAX_SIZE;
    int head = -1;
    int tail = -1;

public:
    StaticQueue(int maxSize = MAX_SIZE) : maxSize(maxSize) {
        this->array = new T[maxSize];
    }

    // StaticQueue() : StaticQueue(MAX_SIZE) {}
        // commentato perchè ho messo StaticQueue(int maxSize = MAX_SIZE)

    void enqueue(T val) {
        if (size == maxSize) {
            cout << "queue is full" << endl;
            return;
        }

        if (head == -1) //controllo se la lista è vuota. In tal caso devo aggiornare 
            //l'indice di head che, inizialmente, è fuori array
            head = 0;
        tail = (++tail % maxSize);
        array[tail] = val;
        size++;
    }

    T dequeue() {
        if (size == 0) {
            cout << "queue is empty" << endl;
            return -1;
        }
        T val = array[head];

        head = (++head % maxSize);
        size--;
        return val; //rimuovo un elemento e la nuova head è l'elemento successivo
    }

    friend ostream& operator<<(ostream& out, StaticQueue<T>& queue) {

        if (queue.size == 0) {
            return out << "queue is empty" << endl;
        }

        out << "Static queue - Size " << queue.size << ", maxSize= " << queue.maxSize << endl;

        for (int i = queue.head, count = 0; count < queue.size; count++) {
            cout << "Queue[" << i << "]=" << queue.array[i] << endl;
            i = (i + 1) % queue.maxSize;
        }
        out << endl;
        return out;
    }

};




#endif