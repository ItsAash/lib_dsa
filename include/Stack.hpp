#ifndef STACK_HPP
#define STACK_HPP

template <class T>
class Stack
{
public:
  Stack() {}
  ~Stack() {}

  virtual void push(T) = 0;
  virtual T pop() = 0;

  virtual bool isEmpty() = 0;
  virtual bool isFull() = 0;
  virtual T peek() = 0;
};

#endif // !STACK_HPP
