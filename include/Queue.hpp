#ifndef Queue_h
#define Queue_h

template <class T>
class Queue
{
public:
  Queue() {}
  ~Queue() {}

  virtual void enqueue(T) = 0;
  virtual T dequeue() = 0;

  virtual bool isEmpty() = 0;
  virtual bool isFull() = 0;
  virtual T peek() = 0;
};

#endif /* Queue_h */