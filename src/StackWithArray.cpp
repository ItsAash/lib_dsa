// Stack implementation using array

#include "StackWithArray.hpp"
#include <iostream>

template <typename T> StackWithArray<T>::StackWithArray() {}

template <typename T> StackWithArray<T>::StackWithArray(int size) {
  this->_size = size;
  _top = -1;
  _datas = new T[size];
}

template <typename T> StackWithArray<T>::~StackWithArray() { delete[] _datas; }

template <typename T> bool StackWithArray<T>::isEmpty() {
  if (_top == -1)
    return true;
  else
    return false;
}

template <typename T> bool StackWithArray<T>::isFull() {
  if (_top == _size - 1)
    return true;
  else
    return false;
}
template <typename T> void StackWithArray<T>::push(T value) {
  if (_top == _size - 1) {
    std::cout << "Stack is full.\n";
    return;
  } else {
    _top++;
    _datas[_top] = value;
  }
}

template <typename T> T StackWithArray<T>::peek() {
  if (isEmpty()) {
    std::cout << "Empty";
  } else
    return _datas[_top];
}

template <typename T> T StackWithArray<T>::pop() {
  if (isEmpty()) {
    std::cout << "Underflow";
  } else {
    T data = _datas[_top];
    // delete _datas[_top];
    _top--;
    return data;
  }
}

template <typename T> void StackWithArray<T>::printStack() {
  for (int i = 0; i < _top + 1; i++) {
    std::cout << _datas[i] << "  ";
  }
}
