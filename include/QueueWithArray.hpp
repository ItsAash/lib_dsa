#include<iostream>
#include"Queue.hpp"

template <class T>
class QueueWithArray : public Queue<T>
{
private:
  T* _queue;
  int _front;
  int _rear;
  int _size;
  int _capacity;

public:
    QueueWithArray(int);
    ~QueueWithArray();
    
    void enqueue(T);
    T dequeue();
    
    bool isEmpty();
    bool isFull();
    T peek();
    };
 // !QUEUEWITHARRAY_HPP