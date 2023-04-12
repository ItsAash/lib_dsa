#include<iostream>
#include"Queue.hpp"

template <class T>
class QueueWithArray : public Queue<T>
{
private:
  T* queue;
  int front;
  int rear;
  int size;
  int capacity;

public:
    QueueWithArray(int);
    ~QueueWithArray();
    
    void enqueue(T);
    T dequeue();
    
    bool isEmpty();
    bool isFull();
    T peek();
    };

template <class T>
QueueWithArray<T>::QueueWithArray(int capacity)
{
  this->capacity = capacity;
  queue = new T[capacity];
  front = 0;
  rear = -1;
  size = 0;
}

template <class T>
QueueWithArray<T>::~QueueWithArray()
{
  delete[] queue;
}

template <class T>
void QueueWithArray<T>::enqueue(T item)
{
  if (isFull())
  {
    std::cout << "Queue is full" << std::endl;
    return;
  }
  rear = (rear + 1) % capacity;
  queue[rear] = item;
  size++;
}

template <class T>
T QueueWithArray<T>::dequeue()
{
  if (isEmpty())
  {
    std::cout << "Queue is empty" << std::endl;
    return 0;
  }
  T item = queue[front];
  front = (front + 1) % capacity;
  size--;
  return item;
}

template <class T>
bool QueueWithArray<T>::isEmpty()
{
  return size == 0;
}

template <class T>
bool QueueWithArray<T>::isFull()
{
  return size == capacity;
}

template <class T>
T QueueWithArray<T>::peek()
{
  if (isEmpty())
  {
    std::cout << "Queue is empty" << std::endl;
    return 0;
  }
  return queue[front];
}

 // !QUEUEWITHARRAY_HPP