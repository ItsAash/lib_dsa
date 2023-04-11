#include <iostream>
#include "Stack.hpp"

int main()
{
  StackWithArray<int> s(3);
  cout << s.isFull() << endl;
  s.push(6);
  s.push(9);
  s.push(10);
  cout << s.isEmpty() << endl;
  cout << s.isFull() << endl;
  s.push(3);
  cout << s.pop() << endl;

  s.printStack();

  // cout << s.peek() << endl;
}