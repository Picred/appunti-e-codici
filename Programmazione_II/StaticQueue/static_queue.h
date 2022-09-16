#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <iostream>

using namespace std;

#define MAX_SIZE 1000


template<class T>
class StaticQueue{
    private:
        T* array;
        int head = -1;
        int tail = -1;
        int size=0;
        int maxSize;
    public:
        StaticQueue(int _maxSize=MAX_SIZE) : maxSize(_maxSize){
            this->array = new T[maxSize];
        }

        int getSize() const {
            return this->size;
        }


        void enqueue(T val){
            if(size==maxSize){ //coda piena?
                cout << "FULL QUEUE!" << endl << endl;
                return;
            }

            if(head==-1) //coda vuota?
                head=0;
            
            //inserisco in coda
            tail= (++tail%maxSize);
            array[tail]=val;
            size++;
        }   

        T dequeue(){
            if(size==0){ //non ci sono elementi?
                cout << "Empty queue!\n";
                return -1;
            }
            T val = array[head];

            head=(++head%maxSize);
            size--;
            return val;
            
        }

        friend ostream& operator<<(ostream& os, StaticQueue<T>& coda){
            os << "Max Size=" << coda.maxSize << endl;

            os << "Head[" << coda.head <<"]= " <<  coda.array[coda.head] <<  " Tail[" << coda.tail<<"]=" << coda.array[coda.tail] << endl;
            os << "[";
            for (int i=coda.head, count = 0; count<coda.size;count++){
                os  << coda.array[i] << "-";
                i= ((i+1)%coda.maxSize);
            }
            os << "]";
            return os;
        }
};

#endif