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

template <class T>
QueueWithArray<T>::QueueWithArray(int capacity)
{
  this->capacity = _capacity;
  _queue = new T[capacity];
  _front = 0;
  _rear = -1;
  _size = 0;
}

template <class T>
QueueWithArray<T>::~QueueWithArray()
{
  delete[] _queue;
}

template <class T>
void QueueWithArray<T>::enqueue(T item)
{
  if (isFull())
  {
    std::cout << "Queue is full" << std::endl;
    return;
  }
  _rear = (_rear + 1) % _capacity;
  _queue[_rear] = item;
  _size++;
}

template <class T>
T QueueWithArray<T>::dequeue()
{
  if (isEmpty())
  {
    std::cout << "Queue is empty" << std::endl;
    return 0;
  }
  T item = _queue[_front];
  _front = (_front + 1) % _capacity;
  _size--;
  return item;
}

template <class T>
bool QueueWithArray<T>::isEmpty()
{
  return _size == 0;
}

template <class T>
bool QueueWithArray<T>::isFull()
{
  return _size == _capacity;
}

template <class T>
T QueueWithArray<T>::peek()
{
  if (isEmpty())
  {
    std::cout << "Queue is empty" << std::endl;
    return 0;
  }
  return _queue[_front];
}

 // !QUEUEWITHARRAY_HPP