#include <cstdlib>
#include <cstring>
#include <climits>

#include <iostream>

using namespace std;

template <typename T>
class Queue{ 
  
  private: 
    T *arr;
    int max;
    int tail;
    int	front;
    int n_elem; 

  public:
    Queue(int size): max(size), tail(0), front(0), n_elem(0) {arr = new T[size];}; 
    int enqueue(T elem);
    int dequeue(T &elem);
}; 

template <typename T>
int Queue<T>::enqueue(T elem){
  if(n_elem == max){ //queue is full
    cout << "\tWARN: Queue is full! n_elem= " << n_elem << endl;
    return -1; //error 
  }
  else{
    arr[tail] = elem;
    tail=(tail+1)%max;
    n_elem++;
    return 0;
  } 
}


template <typename T>
int Queue<T>::dequeue(T & elem){
  if(n_elem == 0){ //queue is empty
    cout << "\tWARN: Queue is empty! n_elem= " << n_elem << endl;
    return -1; //empty
  }
  else{
    elem = arr[front]; //dequeue
    front = (front+1)%max;
    n_elem--;
    return 0;
  }
}

//test queue implemented as circular array
int main(int argc, char *argv[]){

  int n = 100;
  if(argc>=2)
    n=atoi(argv[1]);

  srand(time(0));
  double d;

  Queue<double> my_queue(10); //10 is maximum capacity

  for(int i=0; i<n; i++) { 
    d = (double) rand()/INT_MAX; 
    if(my_queue.enqueue(d)<0)
      cout << "enqueue() failed!" << endl;
    else
      cout << "enqueue(): " << d << endl; 
  }

   for(int i=0; i<n; i++)  
    if(my_queue.dequeue(d)<0) 
      cout << "dequeue() failed!" << endl;
    else
      cout << "dequeue: " << d << endl;
}
