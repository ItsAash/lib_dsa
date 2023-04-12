#ifndef STACK_WITH_ARRAY_HPP
#define STACK_WITH_ARRAY_HPP

#include "Stack.hpp"

template <typename T> class StackWithArray : protected Stack<T> {
private:
  int _size;
  int _top;
  T *_datas;

public:
  StackWithArray();
  StackWithArray(int size);

  ~StackWithArray();

  bool isEmpty();
  bool isFull();

  void push(T value);
  T peek();

  T pop();

  void printStack();
};

#endif // !STACK_WITH_ARRAY_HPP
