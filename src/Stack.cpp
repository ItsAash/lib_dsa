// Stack implementation using array

#include <iostream>
#include "Stack.hpp"

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

template <class T>
class StackWithArray : protected Stack<T>
{
private:
    int _size;
    int _top;
    T *_datas;

public:
    StackWithArray() {}
    StackWithArray(int size)
    {
        this->_size = size;
        _top = -1;
        _datas = new T[size];
    }

    ~StackWithArray()
    {
        delete[] _datas;
    }

    bool isEmpty()
    {
        if (_top == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (_top == _size - 1)
            return true;
        else
            return false;
    }
    void push(T value)
    {
        if (_top == _size - 1)
        {
            std::cout << "Stack is full.\n";
            return;
        }
        else
        {
            _top++;
            _datas[_top] = value;
        }
    }

    T peek()
    {
        if (isEmpty())
        {
            std::cout << "Empty";
        }
        else
            return _datas[_top];
    }

    T pop()
    {
        if (isEmpty())
        {
            std::cout << "Underflow";
        }
        else
        {
            T data = _datas[_top];
            // delete _datas[_top];
            _top--;
            return data;
        }
    }

    void printStack()
    {
        for (int i = 0; i < _top + 1; i++)
        {
            cout << _datas[i] << "  ";
        }
    }
};