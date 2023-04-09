#ifndef STACK_HPP
#define STACK_HPP

class Stack {
public:
  Stack() {}
  ~Stack() {}

  virtual void push(int) = 0;
  virtual int pop() = 0;

  virtual bool isEmpty() = 0;
  virtual bool isFull() {}
};

#endif // !STACK_HPP
