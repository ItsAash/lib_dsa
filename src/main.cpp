#include "StackWithArray.hpp"
#include <iostream>

int main() {
  StackWithArray<int> s(3);
  std::cout << s.isFull() << std::endl;
  s.push(6);
  s.push(9);
  s.push(10);
  std::cout << s.isEmpty() << std::endl;
  std::cout << s.isFull() << std::endl;
  s.push(3);
  std::cout << s.pop() << std::endl;

  s.printStack();

  std::cout << s.peek() << std::endl;
}
